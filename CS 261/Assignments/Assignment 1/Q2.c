/*********************************************************************
** Program Filename: Q2.c
** Author: Grant Nakashima
** Date: 04/09/15
** Description: This program will print x,y,z and then alter the numbers. 
** Input: NA
** Output: It will print what happens to all of the variables after getting altered.
**			If done correctly c shouldn't get changed
*********************************************************************/
#include <stdio.h>
#include <stdlib.h> 

int foo(int *, int *, int);

int main()
{
	int x = 5;
	int y = 6;
	int z = 7;

	printf("x : %d \n", x);
	printf("y : %d \n", y);
	printf("z : %d \n", z);
	printf("\n");

	foo(&x, &y, z);
	
	printf("x : %d \n", x);
	printf("y : %d \n", y);
	printf("z : %d \n", z);

	return 0;
}

/*********************************************************************
** Function: foo
** Description: This function alters a and b but not c
** Parameters: pointer a and b, c
** Pre-Conditions: must have received the three variables
** Post-Conditions: return c
*********************************************************************/
int foo(int *a, int *b, int c)
{
	int temp = *a;
	*a = temp * 2;		// change a to 10

	temp = *b;
	*b = temp / 2;		//change b to 3

	c = *a + *b;		// c will become 13 but when we try to print in main it wont be 13

	return c;
}

/*We went a copy of z to the function. When it gets used in the function, it will get changed in the function 
but once we return to main z hasn't been changed. When we add the & sign the integer in the function and pass by reference. 
This allows the value to get altered. */