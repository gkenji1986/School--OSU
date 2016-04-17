/*********************************************************************
** Program Filename: hashMap.c
** Author: Grant Nakashima
** Date: 05/31/15
** Description: This is the c file that has all of the logic that will be tested in
**				main.c. It has functions that will simulate a hash table.
** Input: none
** Output: none
*********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"



/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{  
	struct hashLink *temp;
	struct hashLink *temp2;

	for (int i = 0; i < ht->tableSize; i++)
	{
		temp = ht->table[i];

		while (temp != 0)
		{
			temp2 = temp->next;
			free(temp);
			temp = temp2;
		}
	}
	free(ht->table);
	ht->count = 0;
	ht->table = 0;
	ht->tableSize = 0;
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeMap(ht);
	/* free the hashMap struct */
	free(ht);
}

/* 
Resizes the hash table to be the size newTableSize 
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	int i;
	int oldSize;

	oldSize = ht->tableSize;
	struct hashLink *current;
	struct hashLink *previous;
	struct hashMap *newTable = createMap(newTableSize);		// create new temp map

	_initMap(newTable, newTableSize);						// initialize the map

	for (i = 0; i < oldSize; i++)							// copy old map to new sized map
	{
		current = ht->table[i];

		while (current != 0)							// loop until current is null
		{
			insertMap(newTable, current->key, current->value);		// insert value into map
			previous = current;
			current = current->next;
			free(previous);
		}
	}
	_initMap(ht, newTableSize);							// set new size for the old map

	for (i = 0; i < newTableSize; i++)					//loop for new size and copy over temp map to the old resized map
	{
		current = newTable->table[i];

		while (current != 0)							
		{
			insertMap(ht, current->key, current->value);
			previous = current;
			current = current->next;
			free(previous);
		}
	}

	free(newTable);
	newTable = 0;
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".

 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.

 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap(struct hashMap * ht, KeyType k, ValueType v)
{
	if (tableLoad(ht) >= LOAD_FACTOR_THRESHOLD)		//resize table if greater than the load factor
	{
		_setTableSize(ht, (ht->tableSize * 2));
	}

	int hashIdx = stringHash2(k) % (ht->tableSize);		// get index

	if (hashIdx < 0)
	{
		hashIdx += ht->tableSize;
	}

	struct hashLink *temp;
	struct hashLink *temp2;

	if (ht->table[hashIdx] == 0)		// check if bucket has any link
	{
		temp = (struct hashLink *) malloc(sizeof(struct hashLink));
		ht->table[hashIdx] = temp;
		ht->table[hashIdx]->key = k;
		ht->table[hashIdx]->value = v;
		ht->table[hashIdx]->next = 0;
		ht->count++;
	}
	else								// when there is a link
	{
		temp2 = ht->table[hashIdx];		// set temp to link

		while (temp2 != 0)
		{
			if (strcmp(temp2->key, k) == 0)		// check if keys are the same
			{
				temp2->value = temp2->value++;		// increase count
				temp2->next = ht->table[hashIdx];	// set next to link on table
				ht->table[hashIdx] = temp2;
				ht->count++;						// increase count
				free(temp2);
				return;
			}
			else
			{
				temp2 = temp2->next;
			}
		}

		temp = (struct hashLink *) malloc(sizeof(struct hashLink));		
		temp->key = k;
		temp->value = v;
		temp->next = ht->table[hashIdx];
		ht->table[hashIdx] = temp;
		ht->count++;
	}
}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.

 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.

 if the supplied key is not in the hashtable return NULL.
 */
ValueType* atMap(struct hashMap * ht, KeyType k)
{
	int hashIdx = stringHash2(k) % (ht->tableSize);		//create index

	if(hashIdx < 0)
	{
		hashIdx += ht->tableSize;
	}

	struct hashLink *current;
	struct hashLink *previous;

	if (ht->table[hashIdx] == 0)			// checks if there is no list there
	{
		return 0;
	}
	else
	{
		current = ht->table[hashIdx];	
		previous = ht->table[hashIdx];

		while (current != 0)					// breaks if null
		{
			if (strcmp(current->key, k) == 0)	// compare keys
			{
				return &(current->value);
			}
			else
			{
				previous = current;
				current = current->next;
			}
		}
	}
	return 0;
}

/*
 a simple yes/no if the key is in the hashtable.
 0 is no, all other values are yes.
 */
int containsKey(struct hashMap * ht, KeyType k)
{
	int hashIdx = stringHash2(k) % (ht->tableSize);
	
	if (ht->table[hashIdx] != NULL)					// continue if not null
	{
		hashLink *current = ht->table[hashIdx];

		while (current != 0)						// loop until current is null
		{
			if (strcmp(current->key, k) == 0)		// return if keys are similar
			{
				return 1;
			}
			current = current->next;
		}
	}
	return 0;
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{  
	int hashIdx = stringHash2(k) % (ht->tableSize);

	hashLink *current;
	hashLink *previous;

	if (containsKey(ht,k) == 1)			// continue if key is found
	{
		current = ht->table[hashIdx];
		previous = ht->table[hashIdx];

		while (current != 0)						// loop until current is null
		{
			if (strcmp(current->key, k) == 0)		// check if key is similar
			{
				if (current == ht->table[hashIdx])
				{
					ht->table[hashIdx] = current->next;
				}
				else
				{
					previous->next = current->next;
				}
				free(current);		// free current
				current = 0;		// set current to 0
				ht->count--;		//reduce count after removal
			}
			else
			{
				previous = current;
				current = current->next;
			}
		}
	}
}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{  
	return ht->count;	
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{  
	return ht->tableSize;
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{  
	int bucket = 0;
	int i;

	for (i = 0; i < ht->tableSize; i++)		// loop and count the number of blank lists
	{
		if (ht->table[i] == 0)
		{
			bucket++;
		}
	}
	return bucket;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)
 
 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{  
	return (float)size(ht) / (float)capacity(ht);
}

void printMap (struct hashMap * ht)
{
	int i;
	struct hashLink *temp;	
	for(i = 0;i < capacity(ht); i++)
	{
		temp = ht->table[i];

		if(temp != 0) 
		{		
			printf("\nBucket Index %d", i);
			printf("\n");
		}
		while(temp != 0)
		{			
			printf("Key:%s| ", temp->key);
			printValue(temp->value);
			temp=temp->next;	
			printf("\n");
		}		
	}
}
