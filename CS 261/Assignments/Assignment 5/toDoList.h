/*********************************************************************
** Program Filename: toDoList.h
** Author: Grant Nakashima
** Date: 05/21/15
** Description: This is the h file that has all of the logic that will be used in our 
**				toDoList.c file. 
** Input: none
** Output: none
*********************************************************************/
#ifndef __TODOLIST_H
#define __TODOLIST_H

#include "dynamicArray.h"
#include "type.h"

Task* createTask (int priority, char *desc);

void saveList(DynArr *heap, FILE *filePtr);

void loadList(DynArr *heap, FILE *filePtr);

void printList(DynArr *heap);

void deleteList(DynArr *heap);

#endif
