/*********************************************************************
** Program Filename: listDequeTest.c
** Author: Grant Nakashima
** Date: 04/20/15
** Description: This is the c file that will be used to test cirListDeque.c
**				Extra prints were added to make it easier to read what is going on. 
** Input: none
** Output: It will print what is going to happen and then print the numbers that 
**			were added into addback addfront functions.
*********************************************************************/
#include "cirListDeque.h"
#include <stdio.h>

int main()
{
	struct cirListDeque* q = createCirListDeque(); 
	addBackCirListDeque(q, (TYPE)1);				//adds to back of deque 3 times
	addBackCirListDeque(q, (TYPE)2);
	addBackCirListDeque(q, (TYPE)3);
	addFrontCirListDeque(q, (TYPE)4);				//adds to front of deque 3 times
	addFrontCirListDeque(q, (TYPE)5);
	addFrontCirListDeque(q, (TYPE)6);				// should end up being 6 5 4 1 2 3
	printf("Printing list.\n");
	printCirListDeque(q);
	printf("\nDisplaying front and back of list.");
	printf("\nFront: %g", frontCirListDeque(q));
	printf("\nBack: %g\n", backCirListDeque(q));
	removeFrontCirListDeque(q);						// removes 6
	removeBackCirListDeque(q);						// removes 3
	printf("\nList with front and back removed.\n");
	printCirListDeque(q);
	printf("\nList will get reversed.\n");
	reverseCirListDeque(q);							// reverses deque should be 2 1 4 5
	printCirListDeque(q);
	printf("\n");
	return 0;
}
