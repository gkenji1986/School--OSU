/**************************************************************
* Created by: Grant Nakashima
* Filename: otp_dec_d.c
* Due Date: 3/14/16
* Purpose - This programs decrypts an encrypted message. The method used is modular addition.
*			Through a socket connections, the program receives the ecrypted text file and key.
*			The decrypted text is sent back through the socket.
* ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>

#define BUFF_SIZE 128000
#define LISTEN_NUM 5

int checkIfValid(int size, char textArray[]);		//checks if the text from the file are ok to use
void decode(char cipher[], char key_array[], char decoded_message[], int textLength);		//takes the encrypted text and coverts its back
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
	int sockfd;
	int newsockfd;
	int port;
	int pid;
	char cipher[BUFF_SIZE];
	char key[BUFF_SIZE];
	char decoded_message[BUFF_SIZE];
	socklen_t clilen;
	int cipherLength;
	int keyLength;
	int validInput;

	struct sockaddr_in serv_addr;
	struct sockaddr_in cli_addr;

	if (argc < 2)		//check if there are the required number of arguments
	{
		printf("Error in otp_dec_d: otp_dec_d port\n");
		exit(1);
	}

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)		//create the socket
	{
		printf("Error in otp_dec_d: could not create socket\n");
		exit(1);
	}

	port = atoi(argv[1]);		//get port

	if (port < 0 || port > 65535)		//make sure port is useable
	{
		printf("Error in otp_dec_d: invalid port\n");
		exit(2);
	}

	bzero((char *)&serv_addr, sizeof(serv_addr)); //clear address
	serv_addr.sin_family = AF_INET;			//set up address
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)		//bind socket and port
	{
		printf("Error in otp_dec_d: Not able to bind socket to port %d\n", port);
		exit(2);
	}

	if (listen(sockfd, LISTEN_NUM) == -1)		//listen for connections
	{
		printf("Error in otp_dec_d: Not able to listen on port %d\n", port);
		exit(2);
	}

	clilen = sizeof(cli_addr);

	while (1)	
	{	
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

		if (newsockfd < 0)
		{
			printf("Error in otp_dec_d: Not able to use connection\n");
			continue;
		}

		pid = fork();		//spawn process when client connects

		if (pid < 0)
		{
			perror("otp_dec_c: error on fork\n");
		}

		if (pid == 0)
		{
			bzero(cipher, sizeof(cipher));		//zero cipher

			cipherLength = read(newsockfd, cipher, BUFF_SIZE);		//get cipher from otp_dec

			if (cipherLength < 0)
			{
				printf("Error: otp_end_d could not read ciphertext on port %d\n", port);
				exit(2);
			}

			int acknowledge;
			acknowledge = write(newsockfd, "!", 1);

			if (acknowledge < 0)
			{
				printf("Error in otp_dec_d: Could not send acknowledgement to client\n");
				exit(2);
			}

			bzero(key, sizeof(key));		//zero key

			keyLength = read(newsockfd, key, BUFF_SIZE);		//get key from otp_dec

			if (keyLength < 0)
			{
				printf("Error in otp_dec_d: could not read key on port %d\n", port);
				exit(2);
			}

			validInput = checkIfValid(cipherLength, cipher);

			if (validInput == 0)
			{
				printf("Error in otp_dec_d: ciphertext contains bad characters\n");
				exit(1);
			}

			validInput = checkIfValid(keyLength, key);

			if (validInput == 0)
			{
				printf("Error in otp_dec_d: key contains bad characters\n");
				exit(1);
			}

			if (keyLength < cipherLength)
			{
				printf("Error in otp_dec_d: key is too short\n");
				exit(1);
			}

			decode(cipher, key, decoded_message, cipherLength);		//decode message
			write(newsockfd, decoded_message, cipherLength);		//send to otp_enc
			close(newsockfd);		//close sockets
			close(sockfd);
			exit(0);
		}
		else
		{
			close(newsockfd);
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
***********************/
void decode(char cipher[], char key_array[], char decoded_message[], int textLength)
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
		
		int message = convertCharToInt(cipher[i]);		// convert to int
		int key = convertCharToInt(key_array[i]);
	
		message = message - 64;			// subtract 64 to put in range of 0 - 26 
		key = key - 64;

		int decrypted = message - key;		// use modular subtraction by subtracting key and message 

		if (decrypted < 0)
		{
			decrypted = decrypted + 27;
		}

		decrypted = decrypted + 64;		// put range between 64 and 90

		decoded_message[i] = convertIntToChar(decrypted);		// convert to char
	
		if (decoded_message[i] == '@')		// after decryption, change asterisks back to spaces
		{
			decoded_message[i] = ' ';
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