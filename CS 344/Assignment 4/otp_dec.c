/**************************************************************
* Created by: Grant Nakashima
* Filename: otp_dec.c
* Due Date: 3/14/16
* Purpose - This program gets the key and encrypted text and sends it via a socket
*			to our server program that will decypt the message. 
* ***************************************************************/

#include <arpa/inet.h>
#include <fcntl.h>     // for open
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>     // for printf
#include <stdlib.h>    // for exit
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h> 
#include <sys/types.h>
#include <unistd.h>

#define BUFF_SIZE    128000

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
	int port;
	char message[BUFF_SIZE];
	char key[BUFF_SIZE];
	char acknowledge[1];
	int i;

	if (argc < 4)		//check if there are enough arguments
	{
		printf("Error in opt_dec: Too few arguments\n");
		exit(1);
	}

	int fd = open(argv[1], O_RDONLY);		//see if there is the textfile for reading

	if (fd < 0)
	{
		printf("Error in opt_dec: text file does not exist\n");
		exit(1);
	}

	int cipherLength = read(fd, message, BUFF_SIZE);		//read file and track number of bytes

	int validCheck = checkIfValid(cipherLength, message);	//check if text is valid

	if (validCheck == 0)
	{
		printf("Error in opt_dec: ciphertext contains bad characters\n");
		exit(1);
	}

	close(fd);

	fd = open(argv[2], O_RDONLY);		//see if there is a key

	if (fd < 0)
	{
		printf("Error in opt_dec: Key file does not exist\n");
		exit(1);
	}

	int key_size;

	key_size = read(fd, key, BUFF_SIZE);	//read key and tracker number of bytes

	validCheck = checkIfValid(key_size, key);	//check if key is valid

	if (validCheck == 0)
	{
		printf("Error in opt_dec: key contains bad characters\n");
		exit(1);
	}
	close(fd);

	if (key_size < cipherLength)		//make sure key is longer than the text
	{
		printf("Error in opt_dec: The key %s is too small\n", argv[2]);
	}

	int sockfd;

	struct sockaddr_in serv_addr;
	struct hostent *server;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);	//create socket

	port = atoi(argv[3]);		//get port number

	if (port < 0 || port > 65535)
	{
		printf("Error in opt_dec: Not a valid port\n");
		exit(2);
	}

	if (sockfd < 0)
	{
		printf("Error in opt_dec: Could not contact on port %d\n", port);
		exit(2);
	}

	bzero((char *)&serv_addr, sizeof(serv_addr)); //clear address

	server = gethostbyname("localhost");

	if (server == NULL)
	{
		printf("Error in opt_dec: Could not connect to opt_dec_d\n");
		exit(2);
	}

	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(port);

	if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1)		//connect to otp_dec_d
	{
		printf("Error in opt_dec: Could not connect to on specified port %d\n", port);
		exit(2);
	}
	int sentNum;

	sentNum = write(sockfd, message, cipherLength - 1);		//send to otp_enc_d

	if (sentNum < cipherLength - 1)
	{
		printf("Error in opt_dec: could not send ciphertext to otp_dec_d on port %d\n", port);
		exit(2);
	}

	int receivedNum;
	bzero(acknowledge, sizeof(acknowledge));
	receivedNum = read(sockfd, acknowledge, 1);
	
	if (receivedNum < 0)
	{
		printf("Error in opt_dec: Could not get acknowledgement from opt_dec_d\n");
		exit(2);
	}

	sentNum = write(sockfd, key, key_size - 1);		//send key to otp_dec_d

	if (sentNum < key_size - 1)
	{
		printf("Error in opt_dec: could not send key to otp_dec_d on port %d\n", port);
		exit(2);
	}

	bzero(message, sizeof(message));

	while (receivedNum > 0)		//get text from otp_dec_d
	{
		receivedNum = read(sockfd, message, cipherLength - 1);
	} 

	if (receivedNum < 0)
	{
		printf("Error in opt_dec:Could not receive ciphertext from otp_dec_d\n");
		exit(2);
	}

	for (i = 0; i < cipherLength - 1; i++)		//print message
	{
		printf("%c", message[i]);
	}

	printf("\n");

	close(sockfd);

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