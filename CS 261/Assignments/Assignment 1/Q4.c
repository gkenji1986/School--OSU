/*********************************************************************
** Program Filename: Q4.c
** Author: Grant Nakashima
** Date: 04/09/15
** Description: This program will make a struct object and assign random numbers to the id 
**				scores. It will make sure the ids arent the same. It will then sort the struct
**				based on their scores
** Input: NA
** Output: It will print the ids and scores of the students
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct student
{
	int id;
	int score;
};

void sort(struct student*, int);

int main()
{
	/*Declare an integer n and assign it a value.*/
	int n = 10;
	/*Allocate memory for n students using malloc.*/
	struct student *st = malloc(n * sizeof(struct student));
	/*Generate random IDs and scores for the n students, using rand().*/
	srand((unsigned int)(time(NULL)));		// seed for rand
	int duplicate;

	for (int i = 0; i < n; i++)				// check for duplicates
	{
		st[i].id = rand() % 10 + 1;			// set random number to id

		duplicate = 0;

		for (int j = 0; j <= (i - 1); j++)		// check if there is a duplicate
		{
			if (st[i].id == st[j].id)
			{
				duplicate = 1;
				i--;								// return to number again if the same
			}
		}
	}

	for (int i = 0; i < n; i++)					// make and set random number for score
	{
		int x = rand() % 100;

		st[i].score = x;
	}
	/*Print the contents of the array of n students.*/
	for (int i = 0; i < n; i++)
	{
		printf("Student id: %d \n", st[i].id);
	}

	printf("\n");

	for (int i = 0; i < n; i++)		// print scores
	{
		printf("Student score: %d \n", st[i].score);
	}

	printf("\n");

	/*Pass this array along with n to the sort() function*/
	sort(st, n);
	/*Print the contents of the array of n students.*/
	for (int i = 0; i < n; i++)
	{
		printf("Student %d score: %d \n", st[i].id, st[i].score);
	}

	if (st != NULL)		// check for null before deleting
	{
		free(st);		// delete
		st = 0;			// make 0 to be safe
	}

	return 0;
}

/*********************************************************************
** Function: sort
** Description: This function sorts the array in ascending order
** Parameters: struct pointer and int
** Pre-Conditions: must have received the three variables
** Post-Conditions: sorts the array
*********************************************************************/
void sort(struct student* students, int n)
{
	/*Sort the n students based on their score*/
	int a = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (students[i].score > students[j].score)
			{
				a = students[i].score;
				students[i].score = students[j].score;
				students[j].score = a;
			}
		}
	}
}