/* You can modify the structure to store whatever you'd like in your dynamic array.
We define struct Task for the to-do list application in this example */

/*********************************************************************
** Program Filename: type.h
** Author: Grant Nakashima
** Date: 05/21/15
** Description: This is the h file that holds the struct for Task. 
** Input: none
** Output: none
*********************************************************************/
#ifndef __TYPE_H
#define __TYPE_H

#define TASK_DESC_SIZE 128

struct Task 
{
	char description[TASK_DESC_SIZE];  	/* description of the task */
	int priority;			  			/* task priority */
};

typedef struct Task Task;

#endif
