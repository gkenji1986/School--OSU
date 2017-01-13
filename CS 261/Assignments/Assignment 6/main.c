/*********************************************************************
** Program Filename: main.c
** Author: Grant Nakashima
** Date: 05/31/15
** Description: This is the main.c file to run the logic from hashMap.c and 
**				hashMap.h. It will read in a text file and count the words 
**				in the file. It will print the time, total of empty buckets,
**				count, capacity and table load of our hash table. It will then
**				delete certain words in our map and re-print our map after the 
**				deletions. 
** Input: none
** Output: none
*********************************************************************/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashMap.h"
#include <string.h>

/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers seperated by periods, spaces, or newlines.
 
 when there are no more words in the input file this function will return NULL.
 
 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file);


int main (int argc, const char * argv[]) {
	const char* filename;
	struct hashMap *hashTable;	
	int tableSize = 10;
	clock_t timer;
	FILE *fileptr;	
    /*
     this part is using command line arguments, you can use them if you wish
     but it is not required. DO NOT remove this code though, we will use it for
     testing your program.
     
     if you wish not to use command line arguments manually type in your
     filename and path in the else case.
     */
    if(argc == 2)
        filename = argv[1];
    else
        filename = "input2.txt"; /*specify your input text file here*/
    
    printf("opening file: %s\n", filename);
    
	timer = clock();
	
	hashTable = createMap(tableSize);	   

	fileptr = fopen(filename,"r");			// open file and read it

	if (fileptr != NULL);
	{
		char* temp;

		while ((temp = getWord(fileptr)) != NULL)		// loop until null
		{
			if ((atMap(hashTable,temp)) == 0 && (containsKey(hashTable,temp) == 0))		// insert if there is nothing 
			{
				insertMap(hashTable, temp, 1);
			}
			else 
			{
				struct hashLink *current;
				
				for(int i = 0; i < hashTable->tableSize;i++)		// loop to find key
				{
					current = hashTable->table[i];

					if (current != NULL)
					{
						if (strcmp(current->key, temp) == 0)		// if they are the same increase value
						{
							current->value++;
							break;
						}
					}
					
				}
			}
		}
	}

	int fclose(FILE *fileptr);			// close file

	printMap(hashTable);
	timer = clock() - timer;
	printf("\nconcordance ran in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
	printf("Table emptyBuckets = %d\n", emptyBuckets(hashTable));
    printf("Table count = %d\n", size(hashTable));
	printf("Table capacity = %d\n", capacity(hashTable));
	printf("Table load = %f\n", tableLoad(hashTable));
	
	printf("Deleting keys\n");
	
	removeKey(hashTable, "and");
	removeKey(hashTable, "me");
	removeKey(hashTable, "the");
	printMap(hashTable);
		
	deleteMap(hashTable);
	printf("\nDeleted the table\n");   
	return 0;
}

void printValue(ValueType v) {
	printf("Value:%d",v);
}

char* getWord(FILE *file)
{
	int length = 0;
	int maxLength = 16;
	char character;

	char* word = malloc(sizeof(char) * maxLength);
	assert(word != NULL);

	while ((character = fgetc(file)) != EOF)
	{
		if ((length + 1) > maxLength)
		{
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if ((character >= '0' && character <= '9') || /*is a number*/
			(character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
			(character >= 'a' && character <= 'z') || /*or a lowercase letter*/
			character == 39) /*or is an apostrophy*/
		{
			word[length] = character;
			length++;
		}
		else if (length > 0)
			break;
	}

	if (length == 0)
	{
		free(word);
		return NULL;
	}
	word[length] = '\0';
	return word;
}
