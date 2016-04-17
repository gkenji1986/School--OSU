/**************************************************************
* Created by: Grant Nakashima
* Filename: otp_enc.c
* Due Date: 3/14/16
* Purpose - The program gets the text and key and sends the files via a socket
*			to our server program that will encrypt the message. 
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
	char cipher[BUFF_SIZE];
	char key[BUFF_SIZE];
	char acknowledge[1];
	int fd;
	int i;
	int port;
	int keyLength;
	int numSent;
	int textLength;
	int sockfd;
	int isValid;

	struct sockaddr_in serv_addr;
	struct hostent *server;

	if (argc < 4)		//check for the correct number of arguments
	{
		printf("Error in otp_enc: not enough arguments\n");
		exit(1);
	}

	port = atoi(argv[3]);		//get port

	if (port < 0 || port > 65535)
	{
		printf("Error in otp_enc: Not a valid port\n");
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd < 0)		//check if the file can be read
	{
		printf("Error in otp_enc: cannot open plaintext file %s\n", argv[1]);
		exit(1);
	}

	textLength = read(fd, cipher, BUFF_SIZE);		//get the context of the file and the number of bytes

	isValid = checkIfValid(textLength, cipher);		//check if file is valid

	if (isValid == 0)
	{
		printf("Error in otp_enc: ciphertext contains bad characters\n");
		exit(1);
	}

	close(fd);

	fd = open(argv[2], O_RDONLY);			//check if key is valid key

	if (fd < 0)			
	{
		printf("Error in otp_enc: cannot open key file %s\n", argv[2]);
		exit(1);
	}

	keyLength = read(fd, key, BUFF_SIZE);		//get the context of the key and the number of bytes

	isValid = checkIfValid(keyLength, key);		//check if context of key is valid

	if (isValid == 0)
	{
		printf("Error in otp_enc: key contains bad characters\n");
		exit(1);
	}

	close(fd);

	if (keyLength < textLength)		//error out if the key to smaller than the file
	{
		printf("Error in otp_enc: key '%s' is too small\n", argv[2]);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);		//create socket

	if (sockfd < 0)
	{
		printf("Error in otp_enc: could not contact otp_enc_d on port %d\n", port);
		exit(2);
	}

	bzero((char *)&serv_addr, sizeof(serv_addr)); //clear address

	server = gethostbyname("localhost");

	if (server == NULL)
	{
		printf("Error in otp_enc: could not connect to otp_enc_d\n");
		exit(2);
	}

	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(port);

	if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)		//connect to otp_enc_d
	{
		printf("Error in otp_enc: could not connect to otp_enc_d on port %d\n", port);
		exit(2);
	}
	
	numSent = write(sockfd, cipher, textLength - 1);	//send text to otp_enc_d

	if (numSent < textLength - 1)
	{
		printf("Error in otp_enc: could not send plaintext to otp_enc_d on port %d\n", port);
		exit(2);
	}

	int receivedNum;
	bzero(acknowledge, sizeof(acknowledge));
	receivedNum = read(sockfd, acknowledge, 1);

	if (receivedNum < 0)
	{
		printf("Error in otp_enc: could not receive acknowledgement from otp_enc_d\n");
		exit(2);
	}

	numSent = write(sockfd, key, keyLength - 1);		//send key to otp_enc_d

	if (numSent < keyLength - 1)
	{
		printf("Error in otp_enc: could not send key to otp_enc_d on port %d\n", port);
		exit(2);
	}

	bzero(cipher, sizeof(cipher));		//zero cipher

	while (receivedNum > 0)
	{
		receivedNum = read(sockfd, cipher, textLength - 1);		//get text from otp_enc_d
	} 

	for (i = 0; i < textLength - 1; i++)	//print text
	{
		printf("%c", cipher[i]);
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
	
	while(i < size - 1)		//loop for size of textArray
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