/******************************************************************************
** Filename: smallsh.c
** Author: Grant Nakashima
** Date Due: 2/28/16
**
** Description: In this assignment you will write your own shell in C. 
** The shell will run command line instructions and return the results 
** similar to other shells you have used, but without many of their fancier features.
** In this assignment you will write your own shell, called smallsh.  
** This will work like the bash shell you are used to using, prompting for a command line 
** and running commands, but it will not have many of the special features of the bash shell.
** Your shell will allow for the redirection of standard input and standard output and 
** it will support both foreground and background processes.
** Your shell will support three built in commands: exit, cd, and status. 
** It will also support comments, which are lines beginning with the # character.
******************************************************************************/

#include <sys/types.h>
#include <sys/stat.h> 
#include <sys/wait.h>	//for waitpid()
#include <stdio.h>		//for printf
#include <stdlib.h>		//for malloc, realloc, free, exit, exec family
#include <string.h>		//for strtok, strcmp
#include <unistd.h>		//for chdir, fork, exec, pid_t, close
#include <errno.h>		//exit track status
#include <fcntl.h>		//file control
#include <signal.h>		//for signals
#include <limits.h>    // for INT_MAX

#define MAX_PIDS       1000 // maximum PIDs to track

//functions
char* getInput();			//gets users input
char **splitLine(char *line);		//breaks string into parts
int start(char **arguments);		//runs checks that aren't built in	
void sigintHandler();
void backgroundHandler(int sig, siginfo_t* info, void* vp);

//signal structs
struct sigaction background_act;
struct sigaction foreground_act;		//struct to catch ctrl+c
struct sigaction restOfTheTime_act;

//globals
int signalNum = 0;
int has_background = 0;
int arg_nums = 0;	//tracker for number of split arguments
int completed_cur = 0;
int cur = 0;                   // index to add next bg process in background_pid[]
int status;
pid_t background_pid[MAX_PIDS];         // array of open background process IDs
pid_t array_pid[MAX_PIDS]; // array of completed bg process IDs
pid_t foreground_pid = INT_MAX;         // running foreground process

/*************
* Reference: http://stackoverflow.com/questions/6629686/writing-linux-shell
* Reference: http://stackoverflow.com/questions/1716296/why-does-printf-not-flush-after-the-call-unless-a-newline-is-in-the-format-strin
* Reference: http://enterpriseprogrammer.com/2013/05/05/pash-a-simple-unix-shell/
* Reference: http://hebabasiony.weebly.com/tutorials/writing-your-own-shell-step-by-step-step-1
* Reference: http://www.experts-exchange.com/questions/26833172/Shell-Background-Processing-in-C.html
* Reference: http://stackoverflow.com/questions/8319484/regarding-background-processes-using-fork-and-child-processes-in-my-dummy-shel
* Reference: http://stackoverflow.com/questions/4788374/writing-a-basic-shell
* Reference: https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf
* Reference: http://enterpriseprogrammer.com/2013/05/05/pash-a-simple-unix-shell/
* Reference: http://cboard.cprogramming.com/c-programming/112536-implement-redirection-simple-shell.html
* Reference: http://stackoverflow.com/questions/11515399/implementing-shell-in-c-and-need-help-handling-input-output-redirection
* Reference: http://stackoverflow.com/questions/12841488/how-can-i-determine-the-maximum-value-of-a-pid-t
* Reference: http://cs.brown.edu/courses/cs033/lecture/24signals2X.pdf  **slide 30
* Reference: http://zguide.zeromq.org/cpp:interrupt
* Reference: Lecture 12 Pipes and IPC, 13 signals
**************/
int main()
{
	int exitStatus_indicator = 0;		//checks status of exit
	int exitCall_indicator = 0;			//checks if exit was called
	int i;
	int j;
	int background_ExitStatus;	//checks background exitstatus
	int background_Status;		//

	
	background_act.sa_sigaction = backgroundHandler;		// set up signal handler for completed child process
	background_act.sa_flags = SA_SIGINFO | SA_RESTART;
	sigfillset(&(background_act.sa_mask));
	sigaction(SIGCHLD, &background_act, NULL);
	
	foreground_act.sa_handler = sigintHandler;	// set up instance of sigaction struct for foreground processes to catch ctrl+c
	foreground_act.sa_flags = SA_RESTART;
	sigfillset(&(foreground_act.sa_mask));
	sigaction(SIGINT, &foreground_act, NULL);

	restOfTheTime_act.sa_handler = SIG_IGN;		// create instance of sigaction struct for foreground processes to catch ctrl+c 
	restOfTheTime_act.sa_flags = SA_RESTART;	
	sigfillset(&(restOfTheTime_act.sa_mask));
	sigaction(SIGINT, &restOfTheTime_act, NULL);

	for (i = 0; i < MAX_PIDS; i++)		
	{
		background_pid[i] = INT_MAX;
		array_pid[i] = INT_MAX;
	}


	while (exitCall_indicator != 1) // break if exit was called	
	{
		char *line = NULL;				//user input
		char **arguments;		//the arguments that get split up
		arg_nums = 0;
		has_background = 0;
		i = 0;
		
		// this loop cleans up zombies, waiting for all ps in completed array
		while (i < MAX_PIDS && array_pid[i] != INT_MAX)
		{
			
			array_pid[i] = waitpid(array_pid[i], &background_Status, 0); // wait on current process

			if (WIFEXITED(background_Status))
			{
				background_ExitStatus = WEXITSTATUS(background_Status); // print process id and exit status
				printf("background pid %d is done: exit value %d.\n", array_pid[i], background_ExitStatus);
			}
			else
			{
				background_ExitStatus = WTERMSIG(background_Status);	//get terminated signal
				printf("background pid %d is done: terminated by signal %d\n", array_pid[i], background_ExitStatus);

			}

			j = 0;
			while (j < MAX_PIDS && background_pid[j] != INT_MAX)
			{ 
				if (background_pid[j] == array_pid[i])		//check for match to remove from array
				{
					background_pid[j] = INT_MAX;

					int k = j;	

					while (k + 1 < MAX_PIDS && background_pid[k + 1] != INT_MAX)	//loop to move shift downward and downsize array
					{
						background_pid[k] = background_pid[k + 1];
						background_pid[k + 1] = INT_MAX;
						k++;
					}
					cur--;
				}
					j++;
			}

			array_pid[i] = INT_MAX;

			i++;
		}

		completed_cur = 0;		//reset tracker

		fflush(stdin);
		fflush(stdout);

		printf(": ");
		fflush(stdin);
		line = getInput();		//get user input
		arguments = splitLine(line);	//break up user input

		if (arguments[0] == NULL || !(strncmp(arguments[0], "#", 1)))		// check if there is a comment or if there are no arguments
		{
			exitStatus_indicator = 0;
		}

		if (arguments[0] != NULL)		//when there are arguments
		{
			if (has_background == 1)			//check if anything is running in the background
			{
				arguments[arg_nums - 1] = NULL; // Clear token
			}

			if (strcmp(arguments[0], "exit") == 0)		//check if exit was called
			{
				i = 0;

				while (i < MAX_PIDS && background_pid[i] != INT_MAX)
				{
					kill(background_pid[i], SIGKILL);		// kill processes before exit
					i++;
				}

				exitCall_indicator = 1;
			}

			else if (strcmp(arguments[0], "status") == 0)	//check if status was called
			{
				if (WIFEXITED(status))
				{
					exitStatus_indicator = WEXITSTATUS(status);
					printf("exit value: %d\n", exitStatus_indicator);		//print status
				}
				else if (signalNum != 0)
				{
					printf("terminated by signal %d\n", signalNum);
				}

			}

			else if (strcmp(arguments[0], "cd") == 0)		//check if cd was called
			{
				if (arguments[1])
				{
					if (chdir(arguments[1]) != 0)		// check if there are any arguments after cd
					{
						exitStatus_indicator = 1;
						printf("There is no such file or directory.\n");
					}
				}
				else	//arguments == NULL
				{
					chdir(getenv("HOME"));
					exitStatus_indicator = 0;
				}	//check directory
			}

			else if (arg_nums > 2 && ((strcmp(arguments[1], ">") == 0) || (strcmp(arguments[1], "<") == 0)))		//redirection
			{
				
				int input;
				int output;
				output = dup(1);	//save output
				input = dup(0);		//save input

				if (strcmp(arguments[1], ">") == 0)	//see if second argument is the > symbol
				{
					int file_destination;

					file_destination = open(arguments[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);	// open file destination

					if (file_destination == -1)
					{
						exitStatus_indicator = 1;
						printf("File or Directory does not exist.\n");
					}
					else
					{
						dup2(file_destination, 1);		//stdout will point to this file
						arguments[1] = NULL;			//terminate any arguments after initial command
						close(file_destination);		//close file
						exitStatus_indicator = start(arguments);		//start commands
					}
				}

				else if (strcmp(arguments[1], "<") == 0)	//see if second argument is the < symbol
				{
					int file_destination;
					file_destination = open(arguments[2], O_RDONLY);

					if (file_destination == -1)
					{
						exitStatus_indicator = 1;
						printf("smallsh: cannot open %s for input.\n",arguments[2]);
					}
					else
					{
						dup2(file_destination, 0);
						arguments[1] = NULL;
						close(file_destination);
						exitStatus_indicator = start(arguments);
					}
				}
				dup2(output, 1);		//restore input and output
				close(output);
				dup2(input, 0);
				close(input);
			}

			else        //other builtins
			{
				exitStatus_indicator = start(arguments);
			}

			free(line);											//free line from memory
			free(arguments);									//free arguments from memory
		}
	}			

	return 0;
}

/*************
* Reference:http://stackoverflow.com/questions/3919009/how-to-read-from-stdin-with-fgets
* Reference: http://www.dummies.com/how-to/content/how-to-use-the-fgets-function-for-text-input-in-c-.html
**************/
char* getInput()
{
	char* userInput = NULL;
	ssize_t buffer_size = 0;			//initialize
	getline(&userInput, &buffer_size, stdin);  //getline sets buffer size and gets input

	char *foundPointer;
	foundPointer = strstr(userInput, "&");

	if (foundPointer == 0)		//check if there is a call for background
	{
		has_background = 0;
	}
	else
	{
		has_background = 1;
	}
	
	return userInput;
}

/*************
* Reference: http://stephen-brennan.com/2015/01/16/write-a-shell-in-c/
* All credit for splitLine(char *line) goes the above link. 
* Reference: http://stackoverflow.com/questions/4513316/split-string-in-c-every-white-space
**************/
#define DELIMS " \t\r\n\a"  

char **splitLine(char *line)
{
	int buffer_size = 64;		//set buffer size
	int position = 0;			// initialize position of token
	char **tokens = malloc(buffer_size * sizeof(char*));		//allocate memory for tokens
	char *token;
	token = strtok(line, DELIMS);		//get first token

	for (position = 0; token != NULL; position++)
	{
		tokens[position] = token;		//put token into token array
		arg_nums++;

		if (position >= buffer_size)
		{
			buffer_size = buffer_size + 64;		//increase buffer size if limit has been reached
			tokens = realloc(tokens, buffer_size * sizeof(char*));		// reallocate memory for tokens
		}
		token = strtok(NULL, DELIMS);		//get next token
	}

	tokens[position] = NULL;					//set last position to be null to cut list off

	return tokens;
}

/*************
* Reference: http://stephen-brennan.com/2015/01/16/write-a-shell-in-c/
* All credit for splitLine(char *line) goes the above link.
* Reference: http://stackoverflow.com/questions/4513316/split-string-in-c-every-white-space
* Reference: http://man7.org/linux/man-pages/man2/wait.2.html
* Reference: http://hebabasiony.weebly.com/tutorials/writing-your-own-shell-step-by-step-step-1
**************/
int start(char **arguments)
{
	pid_t pid = -1;
	pid_t wpid = -1;

	int status_indicator = 0;
	int exitStatus_indicator = 0;

	pid = fork();	// Fork the current process, create child process

	if (pid == 0)		//check if the child is processed
	{
		if (execvp(arguments[0], arguments) == -1)		//check if execution works
		{
			printf("%s: no such file or directory.\n", arguments[0]);
			exit(EXIT_FAILURE);
		}
		else
		{
			execvp(arguments[0], arguments);
			printf("%s", arguments[0]);
			fflush(NULL);
			perror(" ");

			exit(1); // end child process
		}
	}
	else if (pid < 0)
	{ 
		fflush(NULL);
		perror("smallsh");
	}
	else
	{
		if (has_background == 1)		//print background process id
		{
			printf("background pid: %d\n", pid);
			has_background = 0;

			if (cur < MAX_PIDS)
			{
				background_pid[cur++] = pid;
			}
		}

		else
		{
			signalNum = 0;

			foreground_pid = pid;

			sigaction(SIGINT, &foreground_act, NULL);

			foreground_pid = waitpid(foreground_pid, &status, 0);		// wait for fg child process

			sigaction(SIGINT, &restOfTheTime_act, NULL);	// restore to ignore interrupts

			foreground_pid = INT_MAX;

			if (signalNum != 0)		//print if exit by signal
			{
				printf("terminated by signal %d\n", signalNum);
			}
		}

		if (status_indicator != 0 || WIFSIGNALED(status_indicator))
		{
			exitStatus_indicator = 1;
		}

		return exitStatus_indicator;
	}
}

/**********************************
* Reference: http://stackoverflow.com/questions/13273836/how-to-kill-child-of-fork
* Reference: http://stackoverflow.com/questions/6501522/how-to-kill-a-child-process-by-the-parent-process
***********************************/
void sigintHandler()
{

	if (foreground_pid != INT_MAX) 	// if interrupt signal occurs while fg process is running, kill it
	{
		kill(foreground_pid, SIGKILL);	// kill the foreground process

		signalNum = 2;	// set global variable for status messages
	}

	return;
}

void backgroundHandler(int sig, siginfo_t* information, void* vp)
{
	pid_t reference_pid = information->si_pid;

	if (reference_pid != foreground_pid && completed_cur < MAX_PIDS)	// process if the process is not in foreground
	{
		array_pid[completed_cur++] = reference_pid;		//add to array for later use
	}

	return;
}
