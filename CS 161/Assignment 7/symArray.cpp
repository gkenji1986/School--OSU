/************************************************************************
* Author: Grant Nakashima
* Date Created: 11/16/14
* Late Modification: 11/16/14
* FileName: symSum.cpp
*
* Overview: This program is allows the user to input a number of command line
* arguments at the start to determine the size of the arrays. It will then get
* the users input for each array. Once they user is finished inputting the numbers
* it will then determine if the array is symmetric or not. 
*
* Input : The user will input the length of each array. Once they do that, they will
* input numbers into each array. 
*
* Output: The program will output if the user's arrays are symmetric or not. It will also
* output instructions for the user. 
* 
* Output example:
* Array 1 is symmetric, Array 2 is not symmetric, Array 3 is not symmetric
**********************************************************************/

#include <iostream>			// for cin and cout
#include <string>			// for string 
#include <algorithm>		// for atoi	
#include <string.h>			// c style string

using namespace std;
void GetArrayData(int*, int);
bool IsSymmetric(int*, int);
void GetArray1Num(int*, int);
void GetArray2Num(int*, int);
void GetArray3Num(int*, int);
void CheckArray1Sym(int*, int);
void CheckArray2Sym(int*, int);
void CheckArray3Sym(int*, int);

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		cout << "Please enter in 3 values. " << endl;
		return 0;
	}
	int arraySize1 = atoi(argv[1]);			// converting the array size to an usable int.
	int arraySize2 = atoi(argv[2]);
	int arraySize3 = atoi(argv[3]);

	int* array1 = new int[arraySize1];		// creating an array
	int* array2 = new int[arraySize2];
	int* array3 = new int[arraySize3];

	GetArray1Num(array1, arraySize1);		// getting the user's input for each array
	GetArray2Num(array2, arraySize2);
	GetArray3Num(array3, arraySize3);

	CheckArray1Sym(array1, arraySize1);		// checking each individual array
	CheckArray2Sym(array2, arraySize2);
	CheckArray3Sym(array3, arraySize3);
	
	return 0;
}
/**************************************************************
* Entry: Accepts an array
*
* Exit: When it is finished copying the user's string input.
*
* Purpose: Take each individual number and assign it to a new string
*
***************************************************************/
void GetArrayData(int* DArray, int arraySize)
{
	string strLine;
	char * pszToken = NULL;			// keep track of each new digit
	char  delims[] = " ";			// to check for spaces
	int iCol = 0;

		cout << "Enter in the numbers you want for your array. " << endl;
		getline(cin, strLine);

		char szNewString[512] = { NULL };					// setting the string to some random buffer
		strcpy(szNewString, strLine.c_str());

		pszToken = strtok(szNewString, delims);				// to set the numbers in the string to a char

		// While there are any tokens left in "char_line"...
		while (pszToken != NULL)
		{
			DArray[iCol] = atoi(pszToken);

			pszToken = strtok(NULL, delims);

			iCol++;
		}
}
/**************************************************************
* Entry: Gets the array and it's array size. Inside specific
* array check function
*
* Exit: When it is not the same or when it is the same
*
* Purpose: Split up the input into two different integers
*
***************************************************************/
bool IsSymmetric(int *arr, int arraySize)
{
	int i, j;

	for (i = arraySize - 1, j = 0; i >= 0; i--, j++)		// checking the number from one side to the other side
	{
		if (arr[i] != arr[j])								// if they aren't the same it will break
		{
			return false;
		}
	}
	return true;
}
/**************************************************************
* Entry: Gets the array and it's array size. This applies for
* array 1, 2 and 3
*
* Exit: Once it finishes with the get array data function
*
* Purpose: organize getting each array
*
***************************************************************/
void GetArray1Num(int* array1, int arraySize1)
{
		cout << "Please enter the numbers for the first array. " << endl;
		GetArrayData(array1, arraySize1);
}
void GetArray2Num(int* array2, int arraySize2)
{
		cout << "Please enter the numbers for the second array. " << endl;
		GetArrayData(array2, arraySize2);
}
void GetArray3Num(int* array3, int arraySize3)
{
		cout << "Please enter the numbers for the third array. " << endl;
		GetArrayData(array3, arraySize3);
}
/**************************************************************
* Entry: Gets the array and it's array size. 
*
* Exit: When it is symmetric or not
*
* Purpose: tells if the arrays are symmetric or not. Prints out
* if they are or not. Each array has it's own separate funtion
* but is the same. 
*
***************************************************************/
void CheckArray1Sym(int* array1, int arraySize)
{
	if (IsSymmetric(array1, arraySize) == true)
	{
		cout << "Array 1 is symmetric. " << endl;
	}
	else
	{
		cout << "Array 1 is not symmetric. " << endl;
	}
}
void CheckArray2Sym(int* array2, int arraySize)
{
	if (IsSymmetric(array2, arraySize) == true)
	{
		cout << "Array 2 is symmetric. " << endl;
	}
	else
	{
		cout << "Array 2 is not symmetric. " << endl;
	}
}
void CheckArray3Sym(int* array3, int arraySize)
{
	if (IsSymmetric(array3, arraySize) == true)
	{
		cout << "Array 3 is symmetric. " << endl;
	}
	else
	{
		cout << "Array 3 is not symmetric. " << endl;
	}

}
