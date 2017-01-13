/*********************************************************************
** Program Filename: Q3.c
** Author: Grant Nakashima
** Date: 04/09/15
** Description: This program will make an array of random numbers and first print the
**				array, sort the array, and then print the sorted array
** Input: NA
** Output: It will print what happens to the array before and after it gets sorted
*********************************************************************/
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>

void sort(int*, int);

int main()
{
	int n;
	n = 20;
	srand((unsigned int)(time(NULL)));				// seed for rand

	int *array = (int*) malloc(n *(sizeof(int)));		// allocate memory for array

	for (int i = 0; i < n; i++)		// set random numbers to array and print
	{
		array[i] = rand() % 100 + 1;
		printf("Array context %d : %d \n", (i + 1),array[i]);
	}

	printf("\n");

	sort(array, n);			// call sort function

	for (int i = 0; i < n; i++)		// print sorted array
	{
		printf("Array context %d : %d \n", (i + 1), array[i]);
	}

	if (array != NULL)			// check if null before deleting
	{
		free(array);			// delete array
		array = 0;				// make array 0 to be safe
	}

	return 0;
}

/*********************************************************************
** Function: sort
** Description: This function sorts the array in ascending order
** Parameters: int pointer and int
** Pre-Conditions: must have received the three variables
** Post-Conditions: sorts the array
*********************************************************************/
void sort(int *numbers, int n)
{
	int a = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (numbers[i] > numbers[j])		// swaps numbers if num[i] is larger than num[j]
			{
				a = numbers[i];					// it will do it for all numbers
				numbers[i] = numbers[j];
				numbers[j] = a;
			}
		}
	}
}
