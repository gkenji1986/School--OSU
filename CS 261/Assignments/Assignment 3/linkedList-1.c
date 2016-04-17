/*********************************************************************
** Program Filename: linkedList.c
** Author: Grant Nakashima
** Date: 04/20/15
** Description: This is the c file that has all of the logic that will be tested in
**				linkedListMain.c.
** Input: none
** Output: none
*********************************************************************/
#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


/* Double Link*/
struct DLink 
{
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList
{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList(struct linkedList *lst)
{
	lst->firstLink = malloc(sizeof(struct DLink));			// allocate memory for first link
	assert(lst->firstLink != 0);
	lst->lastLink = malloc(sizeof(struct DLink));			// allocate memory for last link
	assert(lst->lastLink);
	lst->firstLink->next = lst->lastLink;					// set 
	lst->lastLink->prev = lst->firstLink;
	lst->size = 0;
}


/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	assert(l != 0);
	assert(lst != 0);
	struct DLink * newLinkToAdd = (struct DLink *)malloc(sizeof(struct DLink));
	newLinkToAdd->value = v;

	// in lecture he passed like this _addBefore(q, q->backsentinel, e) to add to back of queue
	//and _addBefore(q, q->frontSentinel->next, e) to add to the front of the queue

	struct DLink * oldPreviousLink = l->prev;
	//oldPrevious points to either front Sentinel or link just in front of back Sentinel
	newLinkToAdd->prev = oldPreviousLink;
	newLinkToAdd->next = l;
	//lnk is either first link after front Sentinel before newlink is added or backSentinel
	l->prev = newLinkToAdd;
	oldPreviousLink->next = newLinkToAdd;

	lst->size++;
}

/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{
	assert(lst != 0);
	_addLinkBefore(lst, lst->firstLink->next, e);
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) 
{
	assert(lst != 0);
	_addLinkBefore(lst, lst->lastLink, e);
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) 
{
	assert(!isEmptyList(lst));
	return lst->firstLink->next->value;
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
	assert(!isEmptyList(lst));
	return lst->lastLink->prev->value;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{
	assert(!isEmptyList(lst));
	assert(l != 0);
	l->next->prev = l->prev; 
	l->prev->next = l->next;
	free(l);

	lst->size--;
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) 
{
	assert(!isEmptyList(lst));
	_removeLink(lst, lst->firstLink->next);
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{	
	assert(!isEmptyList(lst));
	_removeLink(lst, lst->lastLink->prev);
	
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) 
{
	assert(lst != 0);

	if (lst->size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
	assert(lst != 0);

	struct DLink *temp;
	temp = lst->firstLink->next;

	while (temp != 0)			// loop will continue until end
	{
		printf("%d ", temp->value);
		temp = temp->next;			// change to next link
	}

	temp = 0;   // set to 0 once finished to prevent errors
}

/* 
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	assert(lst != 0);
	addBackList(lst, v);
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e)
{
	struct DLink *temp;

	assert(lst != 0);
	assert(!isEmptyList(lst));
	temp = lst->firstLink->next;

	while (temp != lst->lastLink)
	{
		if (EQ(temp->value, e))
		{
			return 1;
		}
		else
		{
			temp = temp->next;
		}
	}
	return 0;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) 
{
	assert(lst != 0);
	assert(!isEmptyList(lst));

	struct DLink *temp;
	temp = lst->firstLink->next;

	while (temp != lst->lastLink)
	{
		if (temp->value == e)
		{
			_removeLink(lst, temp);
			return;
		}
	}
	free(temp);
	temp = 0;
}