/*********************************************************************
** Program Filename: Q1.c
** Author: Grant Nakashima
** Date: 04/09/15
** Description: This program will use a struct and then allocate memory for 10 students. It will
**				will the manipulate the pointers to the struct and generate numbers for the id and scores,
**				 and print the stats for the scores. 
** Input: NA
** Output: It will print the minimum,maximum and average scores of the 10 students. 
*********************************************************************/
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <assert.h>

struct student		
{
	int id;
	int score;
}; 

struct student *allocate();
void generate(struct student*);
void output(struct student*);
void summary(struct student*);
void deallocate(struct student*);


int main()
{
	struct student *st = 0;

	st = allocate();	// make memory for struct
	generate(st);
	output(st);
	summary(st);		// print scores
	deallocate(st);		// delete

	return 0;
}

/*********************************************************************
** Function: allocate
** Description: This function allocate memory for the struct
** Parameters: none
** Pre-Conditions: must have struct object
** Post-Conditions: none
*********************************************************************/
struct student *allocate()
{
	struct student *st = malloc(10 * sizeof(struct student));		// make memory for struct of 10

	assert(st != NULL);												// check if null

	return st;
}

/*********************************************************************
** Function: generate
** Description: This function makes id's and scores. It will check if the
**				ids are the same. 
** Parameters: student pointer
** Pre-Conditions: must have struct object
** Post-Conditions: none
*********************************************************************/
void generate(struct student *students)
{
	srand((unsigned int)(time(NULL)));				// seed rand
	int duplicate;
	
	for (int i = 0; i < 10; i++)					// check for duplicate
	{
		students[i].id = rand() % 10 + 1;			// get random number for 1-10

		duplicate = 0;

		for (int j = 0; j <= (i - 1); j++)			// check if there is a duplicate
		{
			if (students[i].id == students[j].id)	
			{
				duplicate = 1;
				i--;								// go back and try to get different number
			}
		}
	}

	for (int i = 0; i < 10; i++)	// create random number and set to score
	{
		int x = rand() % 100;

		students[i].score = x;
	}
}

/*********************************************************************
** Function: output
** Description: This function prints the students ids and scores
** Parameters: pointer to student
** Pre-Conditions: must have struct object
** Post-Conditions: none
*********************************************************************/
void output(struct student *students)
{
	for (int i = 0; i < 10; i++)	// print ids
	{
		printf("Student id: %d \n", students[i].id);
	}

	for (int i = 0; i < 10; i++)	// print scores
	{
		printf("Student score: %d \n", students[i].score);
	}
}

/*********************************************************************
** Function: summary
** Description: This function finds the average, max and min score to print
** Parameters: pointer to student
** Pre-Conditions: must have struct object
** Post-Conditions: none
*********************************************************************/
void summary(struct student *students)
{
	int sum = 0;
	int minimum = 100;
	int maximum = 0;

	for (int i = 0; i < 10; i++)			// for loop to get sum of scores
	{
		sum = sum + students[i].score;
	}

	int average = sum / 10;					// calculate average

	for (int i = 0; i < 10; i++)			// for loop to find max
	{
		if (students[i].score > maximum)
		{
			maximum = students[i].score;
		}
	}

	for (int i = 0; i < 10; i++)			// for loop to find min
	{
		if (students[i].score < minimum)
		{
			minimum = students[i].score;
		}
	}

	printf("Minimum score: %d \n", minimum);
	printf("Maximum score: %d \n", maximum);
	printf("Average score: %d \n", average);
}

/*********************************************************************
** Function: deallocate
** Description: This function deallocate memory for the struct
** Parameters: pointer to student
** Pre-Conditions: must have struct object
** Post-Conditions: none
*********************************************************************/
void deallocate(struct student *students)
{
	if (students != NULL)		// make sure not null before freeing memory
	{
		free(students);			// delete
		students = 0;			// make 0 to be safe
	}
}