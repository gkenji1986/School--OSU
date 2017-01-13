/**************************************************************
* Created by: Grant Nakashima
* Filename: keygen.c
* Due Date: 3/14/16
* Purpose - To generate a random string of specified length
* ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int i;
	int str_len = atoi(argv[1]);;
	char key[str_len + 1];
	char letter_array;


	if (argc < 2)
	{
		printf("Usage: %s length\n", argv[0]);
		exit(1);
	}

	srand(time(NULL));

	if (str_len < 1)
	{
		printf("Error: length too small.");
		exit(1);
	}

	for (i = 0; i< str_len; i++)
	{
		letter_array = " ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 27];
		key[i] = letter_array;

	}
	key[str_len] = '\0'; //null terminating char of key string

	printf("%s\n", key);

	return 0;
}
