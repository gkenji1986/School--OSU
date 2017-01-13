/*********************************************************************
** Program Filename: bst.c
** Author: Grant Nakashima
** Date: 05/03/15
** Description: This is the c file that has all of the logic that will be tested in
**				main.c.
** Input: none
** Output: none
*********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"


struct Node 
{
	TYPE         val;
	struct Node *left;
	struct Node *right;
};

struct BSTree 
{
	struct Node *root;
	int          cnt;
};

/*----------------------------------------------------------------------------*/
/*
 function to initialize the binary search tree.
 param tree
 pre: tree is not null
 post:	tree size is 0
		root is null
 */

void initBSTree(struct BSTree *tree)
{
	tree->cnt  = 0;				// make count 0
	tree->root = 0;				// make root 0
}

/*
 function to create a binary search tree.
 param: none
 pre: none
 post: tree->count = 0
		tree->root = 0;
 */

struct BSTree*  newBSTree()
{
	struct BSTree *tree = (struct BSTree *)malloc(sizeof(struct BSTree));		// allocate memory for tree
	assert(tree != 0);															// check if memory allocated

	initBSTree(tree);															// initialize tree

	return tree;																// return 
}

/*----------------------------------------------------------------------------*/
/*
function to free the nodes of a binary search tree
param: node  the root node of the tree to be freed
 pre: none
 post: node and all descendants are deallocated
*/

void _freeBST(struct Node *node)
{
	if (node != 0)							// check if node is 0
	{
		_freeBST(node->left);				// recursively remove left
		_freeBST(node->right);				// recursively remove right
		free(node);							// free node
	}
}

/*
 function to clear the nodes of a binary search tree
 param: tree    a binary search tree
 pre: tree ! = null
 post: the nodes of the tree are deallocated
 */
void clearBSTree(struct BSTree *tree)
{
	_freeBST(tree->root);					// free root
	tree->root = 0;							// make root 0
	tree->cnt  = 0;							// make count 0
}

/*
 function to deallocate a dynamically allocated binary search tree
 param: tree   the binary search tree
 pre: tree != null;
 post: all nodes and the tree structure itself are deallocated.
 */
void deleteBSTree(struct BSTree *tree)
{
	clearBSTree(tree);
	free(tree);
}

/*----------------------------------------------------------------------------*/
/*
 function to determine if  a binary search tree is empty.

 param: tree    the binary search tree
 pre:  tree is not null
 */
int isEmptyBSTree(struct BSTree *tree) 
{ 
	return (tree->cnt == 0); 
}

/*
 function to determine the size of a binary search tree

param: tree    the binary search tree
pre:  tree is not null
*/
int sizeBSTree(struct BSTree *tree) 
{ 
	return tree->cnt; 
}

/*----------------------------------------------------------------------------*/
/*
 recursive helper function to add a node to the binary search tree.
 HINT: You have to use the compare() function to compare values.
 param:  cur	the current root node
		 val	the value to be added to the binary search tree
 pre:	val is not null
 */
struct Node *_addNode(struct Node *cur, TYPE val)
{
	struct Node *temp;

	if (cur == 0)				// check if current is 0
	{
		temp = (struct Node*) malloc(sizeof(struct Node));		// allocate memory for temp

		assert(temp != 0);				// check if memory got allocated
		temp->val = val;				// make value equal to paramater value
		temp->left = 0;					// make left = 0
		temp->right = 0;				// make right = 0

		return temp;					// return 
	}

	if (compare(val, cur->val) == -1)				// check if value is less than cur->val
	{
		cur->left = _addNode(cur->left, val);		// recursively call _addNode 
	}
	else if (compare(val, cur->val) == 1)			// check if value is greater than cur->val
	{
		cur->right = _addNode(cur->right, val);		// recursively call _addNode
	}

	return cur;
}

/*
 function to add a value to the binary search tree
 param: tree   the binary search tree
		val		the value to be added to the tree

 pre:	tree is not null
		val is not null
 pose:  tree size increased by 1
		tree now contains the value, val
 */
void addBSTree(struct BSTree *tree, TYPE val)
{
	tree->root = _addNode(tree->root, val);		// set root 

	tree->cnt++;			// increase count of tree
}


/*
 function to determine if the binary search tree contains a particular element
 HINT: You have to use the compare() function to compare values.
 param:	tree	the binary search tree
		val		the value to search for in the tree
 pre:	tree is not null
		val is not null
 post:	none
 */

/*----------------------------------------------------------------------------*/
int containsBSTree(struct BSTree *tree, TYPE val)
{
	struct Node *temp = tree->root;			// make temp 

	while (temp != 0)						// make loop to end when temp is 0
	{
		if (compare(val, temp->val) == 0)	// check if values are equal
		{
			return 1;
		}
		if (compare(val, temp->val) == -1)	// check if val is less than temp->val
		{
			temp = temp->left;				// make temp equal temp->left
		}
		else								// mcheck if val is greater than temp->val
		{
			temp = temp->right;				// make temp equal to temp->right
		}
	}
	return 0;
}

/*
 helper function to find the left most child of a node
 return the value of the left most child of cur
 param: cur		the current node
 pre:	cur is not null
 post: none
 */

/*----------------------------------------------------------------------------*/
TYPE _leftMost(struct Node *cur)
{
	while (cur->left != 0)			//loop until cur->left is null
	{
		cur = cur->left;			// set cur to cur->left
	}

	return cur->val;
}


/*
 recursive helper function to remove the left most child of a node
 HINT: this function returns cur if its left child is NOT NULL. Otherwise,
 it returns the right child of cur and free cur.

Note:  If you do this iteratively, the above hint does not apply.

 param: cur	the current node
 pre:	cur is not null
 post:	the left most node of cur is not in the tree
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeLeftMost(struct Node *cur)
{
	struct Node* temp;

	if (cur->left == 0)		// if left is null
	{
		temp = cur->right;	// set temp to right
		free(cur);			// free cur

		return temp;
	}
	cur->left = _removeLeftMost(cur->left);		// recursively call function again and make cur->left equal to it

	return cur;
}
/*
 recursive helper function to remove a node from the tree
 HINT: You have to use the compare() function to compare values.
 param:	cur	the current node
		val	the value to be removed from the tree
 pre:	val is in the tree
		cur is not null
		val is not null
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeNode(struct Node *cur, TYPE val)
{
	struct Node *temp;				// make temp

	if (compare(val, cur->val) == 0)	// check if equal
	{
		if (cur->right == 0)			// check if right is null
		{
			temp = cur->left;			// make temp equal left
			free(cur);

			return temp;
		}

		cur->val = _leftMost(cur->right);			// set value
		cur->right = _removeLeftMost(cur->right);	// set right
	}
	else if (compare(val, cur->val) == -1)			// check if left less than right
	{
		cur->left = _removeNode(cur->left, val);	// remove left
	}
	else
	{
		cur->right = _removeNode(cur->right, val);	// remove right
	}

	return cur;
}
/*
 function to remove a value from the binary search tree
 param: tree   the binary search tree
		val		the value to be removed from the tree
 pre:	tree is not null
		val is not null
		val is in the tree
 pose:	tree size is reduced by 1
 */
void removeBSTree(struct BSTree *tree, TYPE val)
{
	if (containsBSTree(tree, val))					// check if tree contains value
	{
		tree->root = _removeNode(tree->root, val);	// remove specified node
		tree->cnt--;								// decrement count
	}
}
