/**************************************************************
* Created by: Grant Nakashima
* Filename: otp_enc_d.c
* Due Date: 3/14/16
* Purpose - This program will encrypt the message using modular addition. 
*			It gets the files and key by a socket and sends the encrypted text
*			back through the socket. 
* ***************************************************************/

#include <fcntl.h>     // for open
#include <netinet/in.h>
#include <stdio.h>     // for printf
#include <stdlib.h>    // for exit
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFF_SIZE 128000
#define LISTEN_NUM 5

void encrypt(char cipher[], char key[], char encrypted_message[], int textLength);
int checkIfValid(int size, char textArray[]);		//checks if the text from the file are ok to use
int convertCharToInt(char c);		//takes char and converts it to an int
char convertIntToChar(int i);		//takes int and converts it to a char

/**********************************
* Reference: http://www.programminglogic.com/example-of-client-server-program-in-c-using-sockets-and-tcp/
* Reference: http://www-scf.usc.edu/~bagde/networksproject/multiserver.c
* Reference: http://stackoverflow.com/questions/8777055/using-select-in-client-server-acknowledgement-in-c
* Reference: http://stackoverflow.com/questions/5660393/c-socket-client
* Reference: http://codereview.stackexchange.com/questions/41748/small-one-time-pad-encryption-program
* Reference: http://www.binarytides.com/server-client-example-c-sockets-linux/
* Reference: http://www.tutorialspoint.com/unix_sockets/socket_server_example.htm
* Reference: http://beej.us/guide/bgnet/output/html/multipage/clientserver.html
* Reference: http://www.binarytides.com/socket-programming-c-linux-tutorial/
***********************************/
int main(int argc, char** argv)
{
	if (argc < 2)		//check for correct number of arguments
	{
		printf("Error in opt_enc_d: too few arguments\n");
		exit(1);
	}

	int socket_fd;
	int new_socket_fd;
	int pid;
	socklen_t remoteLength;
	int port = atoi(argv[1]);
	int text_len;
	int key_len;
	char message[BUFF_SIZE];
	char key[BUFF_SIZE];
	char encrypted_message[BUFF_SIZE];
	int isValid;

	if (port < 0 || port > 65535)		//check if port is valid
	{
		printf("Error in opt_enc_d: invalid port\n");
		exit(2);
	}

	struct sockaddr_in local;
	struct sockaddr_in remote;

	if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)		//create socket
	{
		printf("Error in opt_enc_d: could not create socket\n");
		exit(1);
	}

	bzero((char *)&local, sizeof(local)); //clear address
	local.sin_family = AF_INET;					//set up address
	local.sin_addr.s_addr = INADDR_ANY;
	local.sin_port = htons(port);

	if (bind(socket_fd, (struct sockaddr*)&local, sizeof(local)) < 0)		//bind socket to port
	{
		printf("Error in opt_enc_d: unable to bind socket to port %d\n", port);
		exit(2);
	}

	if (listen(socket_fd, LISTEN_NUM) == -1)		//listen for connections
	{
		printf("Error in opt_enc_d: unable to listen on port %d\n", port);
		exit(2);
	}

	remoteLength = sizeof(remote);

	while (1)
	{
		new_socket_fd = accept(socket_fd, (struct sockaddr *)&remote, &remoteLength);

		if (new_socket_fd < 0)
		{
			printf("Error in opt_enc_d: unable to accept connection\n");
			continue;
		}

		pid = fork();

		if (pid < 0)
		{
			perror("Error in opt_enc_d: error on fork\n");
		}

		if (pid == 0)
		{
			bzero(message, sizeof(message));		//zero out message

			text_len = read(new_socket_fd, message, BUFF_SIZE);		//get text from otp_enc

			if (text_len < 0)
			{
				printf("Error in opt_enc_d: could not read plaintext on port %d\n", port);
				exit(2);
			}

			isValid = checkIfValid(text_len, message);		//check if text is valid

			if (isValid == 0)
			{
				printf("Error in opt_enc_d: plaintext contains invalid characters\n");
				exit(1);
			}

			int acknowledge;
			acknowledge = write(new_socket_fd, "!", 1);

			if (acknowledge < 0)
			{
				printf("Error in opt_enc_d: could not send acknowledgement to client\n");
				exit(2);
			}
		
			bzero(key, sizeof(key));		//zero out key

			key_len = read(new_socket_fd, key, BUFF_SIZE);		//get key from otp_enc

			if (key_len < 0)
			{
				printf("Error in opt_enc_d: could not read key on port %d\n", port);
				exit(2);
			}

			isValid = checkIfValid(key_len, key);		//check if key is valid

			if (isValid == 0)
			{
				printf("Error in opt_enc_d: key contains invalid characters\n");
				exit(1);
			}
			
			if (key_len < text_len)
			{
				printf("Error in opt_enc_d: key length is too small\n");
				exit(1);
			}

			encrypt(message, key, encrypted_message, text_len);		//encrypt message
			write(new_socket_fd, encrypted_message, text_len);		//send message to opt_enc
			close(new_socket_fd);		//close sockets
			close(socket_fd);
			exit(0);
		}
		else
		{
			close(new_socket_fd);
		}	
	}
	
	return 0;
}

/**********************
* Reference: http://www.ascii-code.com/
* Reference: http://www.cquestions.com/2011/07/c-program-for-modular-division-of-large.html
***********************/
int checkIfValid(int size, char textArray[])
{
	int i;
	int character;
	i = 0;

	while (i < size - 1)		//loop for size of textArray
	{
		character = convertCharToInt(textArray[i]);

		if (character < 65 && character != 32)		//check if character is less than A and not ' ' on ascii table
		{
			return 0;
		}
		else if (character  > 90 && character != 32)	//check if character is greater than Z and not ' '
		{
			return 0;
		}
		i++;
	}

	return 1;
}

/**********************
* Reference: http://crypto.stackexchange.com/questions/15669/how-to-calculate-modulo-using-a-standard-calculator-for-a-one-time-pad-encryptio
* Reference: http://khimanichirag.blogspot.com/2013/04/normal-0-false-false-false-en-us-x-none_21.html
* Reference: http://www.cplusplus.com/forum/beginner/179981/
* Reference: http://www.cs.utsa.edu/~wagner/laws/pad.html
* Reference: http://www.cimt.plymouth.ac.uk/resources/codes/codes_u12_text.pdf
* Reference: http://cryptography.wikia.com/wiki/One-time_pad
* Reference: http://math.stackexchange.com/questions/429449/encryption-using-modular-addition-and-a-key
***********************/
void encrypt(char cipher[], char key_array[], char encrypted_message[], int textLength)
{
	int i;
	i = 0;

	while (i < textLength)
	{
		if (cipher[i] == ' ')		// change spaces to at symbol since @ symbol is ascii 64
		{
			cipher[i] = '@';		// use of any other symbol produces error
		}
		if (key_array[i] == ' ')
		{
			key_array[i] = '@';
		}

		int message = convertCharToInt(cipher[i]);			// convert to int
		int key = convertCharToInt(key_array[i]);

		message = message - 64;				// subtract 64 so that range is 0 - 26 (27 characters)
		key = key - 64;

		int cipher = (message + key) % 27;		// use modular addition. combine message and key

		cipher = cipher + 64;				// add 64 back to that range is 64 - 90

		encrypted_message[i] = convertIntToChar(cipher);		// convert back to char

		if (encrypted_message[i] == '@')					// after encryption, change asterisks to spaces
		{
			encrypted_message[i] = ' ';
		}
		i++;
	}
}
/****************
* Reference: http://stackoverflow.com/questions/628761/character-to-integer-in-c
*****************/
int convertCharToInt(char c)
{
	int converted;

	converted = (int)c;

	return converted;
}

/****************
* Reference: http://stackoverflow.com/questions/628761/character-to-integer-in-c
*****************/
char convertIntToChar(int i)
{
	char converted;

	converted = (char)i + 0;

	return converted;
}