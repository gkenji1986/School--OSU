/*********************************************************************
** Program Filename: dynamicArray.c
** Author: Grant Nakashima
** Date: 04/20/15
** Description: This is the c file that has all of the logic that will be tested in 
**				listDequeTest.c. 
** Input: none
** Output: none
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q) 
{
	assert(q != 0);
	struct DLink *lnk = (struct DLink *) malloc(sizeof(struct DLink));			// allocate memory for DLink
	assert(lnk != 0);															// check if sentinel made
	q->Sentinel = lnk;															// set lnk to sentinel
	q->Sentinel->next = q->Sentinel->prev = q->Sentinel;						// set next and prev to sentinel which is null
	q->size = 0;																// set size to zero
}

/*
 create a new circular list deque
 
 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));			
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	struct DLink *lnk = (struct DLink *)malloc(sizeof(struct DLink));			// allocate memory for new link
	lnk->value = val;															// set links value to given value
			
	return (lnk);											

}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	assert(q != 0);
	assert(lnk != 0);												// check if q and lnk are not null
	
	struct DLink *newLink = _createLink(v);							//set newLink to link createLink

	lnk->next->prev = newLink;										// set link to the newLink right side connects to new
	newLink->next = lnk->next;										// set newLink's next to lnk's next connect new to right
	newLink->prev = lnk;											// set newLink's prev to lnk connect new to left
	lnk->next = newLink;											// set lnk's next to newLink left side connects to new
	q->size++;														// increase q's size
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	assert(q != 0);											// make sure q isnt null
	
	_addLinkAfter(q, q->Sentinel->prev, val);				// call addLinkAfter to add link in back
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	assert(q != 0);											// make sure q isnt null

	_addLinkAfter(q, q->Sentinel, val);						// call addLinkAfter to add link in front
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	assert(q != 0);
	assert(!isEmptyCirListDeque(q));					// make sure q is not null and empty

	return(q->Sentinel->next->value);					// return value in front of deque
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	assert(q != 0);
	assert(!isEmptyCirListDeque(q));					// make sure q is not null and empty

	return(q->Sentinel->prev->value);					// return value in back of deque
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	assert(q != 0);
	assert(!isEmptyCirListDeque(q));						// make sure q not null and empty to prevent errors

	lnk->next->prev = lnk->prev;							//connect right link to left link
	lnk->prev->next = lnk->next;							// connect left link to right link
	q->size--;												// reduce size of q to remove
	free(lnk);												// free memory of lnk
	lnk = 0;												// set lnk to 0 to prevent any errors
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q)
{
	assert(q != 0);
	assert(!isEmptyCirListDeque(q));					// check if q not null and not empty to prevent errors

	_removeLink(q, q->Sentinel->next);					// remove front 
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
	assert(q != 0);
	assert(!isEmptyCirListDeque(q));					// check if q not null and not empty to prevent errors

	_removeLink(q, q->Sentinel->prev);					// remove back of deque
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	struct DLink * temp = q->Sentinel->next;

	while (q->size > 0)									// loop until size is 0
	{
		temp = temp->next;								// temp equal to right
		free(temp->prev);								// free previous will continue to delete links one by one
	}
	free(q->Sentinel);									// free sentinel
	q->Sentinel = 0;									// set sentinel to 0
	q->size = 0;										// set size to 0
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) 
{
	assert(q != 0);									// make sure q isnt null 

	if (EQ(q->size,0))								// if size and 0 are equal
	{
		return 1;									// return true
	}
	else
	{
		return 0;									//return false
	}
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	assert(q != 0);
	assert(!isEmptyCirListDeque(q));					// make sure q isnt null or empty 
	
	struct DLink *temp;
	temp = q->Sentinel->next;							//set temp to right node
	while (temp != q->Sentinel)							// will continue loop until temp is null
	{
		printf("Value : %f\n", temp->value);			// print value at node
		temp = temp->next;								// set temp to next number
	}
}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	assert(q != 0);												// check if not null
	struct cirListDeque *temp = createCirListDeque();			// create new deque to copy reverse to 

	while (!isEmptyCirListDeque(q))								// loop continues until empty
	{
		addBackCirListDeque(temp, backCirListDeque(q));			// add list in back to back of temp
		removeBackCirListDeque(q);								// remove list in back of q
	}
	q->Sentinel = temp->Sentinel;								// set sentinel of q to temp's sentinel
	q->size = temp->size;										// set size 
	q = temp;													// copy links of temp to q
	free(temp);													// delete temp
	temp = 0;													// make temp 0 to prevent errors
}
