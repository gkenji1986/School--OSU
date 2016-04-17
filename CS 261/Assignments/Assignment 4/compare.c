/*********************************************************************
** Program Filename: compare.c
** Author: Grant Nakashima
** Date: 05/03/15
** Description: This is the c file that has all of the logic that will be tested in
**				bst.c.
** Input: none
** Output: none
*********************************************************************/
#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

  /*
  function to compares the left and right numbers and returns either -1, 1 or 0
  param: TYPE
  pre: tree != null;
  post: compare numbers finds result
  */
int compare(TYPE left, TYPE right)
{
	struct data* temp1;
	struct data* temp2;

	temp1 = (struct data*)left;						// make temp1 equal to left
	temp2 = (struct data*)right;					// make temp2 equal to right

	if (temp1->number < temp2->number)				// check if the left number is less than the right
	{
		return -1;
	}
	else if (temp1->number > temp2->number)			// check if the left number is less than the right
	{
		return 1;
	}
	else                                            // if equal
	
	{
		return 0;
	}
}

/*
function to print the number at the struct
param: TYPE 
pre: tree != null;
post: all values printed
*/
void print_type(TYPE curval)
{
	struct data *temp;

	temp = (struct data *) curval;

	printf("printing value: %d", temp->number);
}


