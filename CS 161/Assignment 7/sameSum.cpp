/************************************************************************
* Author: Grant Nakashima
* Date Created: 11/14/14
* Late Modification: 11/16/14
* FileName: sameSum.cpp
*
* Overview: This program is allows the user to input a number of array
* inputs to with the size of the array up to the user and then it will
* check if the numbers they inputted make the square the same. 
*
* Input : The user will input the numbers in their array until they are 
* satisfied. 
*
* Output: Enter a space delimited lines of integer values for line _ 
* Enter up to 10 values or hit enter with nothing to quit
* IS SAME, NOT SAME, Press any key to continue. 
*
* Output example:
* IS SAME, NOT SAME
**********************************************************************/

#include <iostream>	// need for cout cin
#include <string>	// need for string
#include <algorithm>	// need for atoi
#include <string.h>	// need for string

using namespace std;

const int MAX_ROWS = 10;		// setting max number of rows
const int MAX_COLS = 10;		// setting max number of columns

/**************************************************************
* Entry: received the array and the column and rows size
*
* Exit: it will return true if the sum is the same. if not it
* will exit by returning false.
*
* Purpose: Reads the input and checks to see if they are the same
* in the rows
*
***************************************************************/
bool IsGoodRows(int twoDArray[MAX_ROWS][MAX_COLS], int iMaxRows, int iMaxCols)
{
	int lastSum = 0;
	int currentSum = 0;

	for (int i = 0; i < iMaxRows; i++)
	{
		currentSum = 0;

		for (int j = 0; j < iMaxCols; j++)
		{
			currentSum += twoDArray[i][j];
		}  //** next j

		if (i > 0)
		{
			//** only do this after you have summed the first row
			if (lastSum != currentSum)
			{
				return false;
			}
		}

		lastSum = currentSum;
	}  //** next i

	return true;
}
/**************************************************************
* Entry: received the array and the column and rows size
*
* Exit: it will return true if the sum is the same. if not it
* will exit by returning false.
*
* Purpose: Reads the input and checks to see if they are the same
* in the column
*
***************************************************************/
bool IsGoodCols(int twoDArray[MAX_ROWS][MAX_COLS], int iMaxRows, int iMaxCols)
{
	int lastSum = 0;
	int currentSum = 0;

	for (int i = 0; i < iMaxCols; i++)
	{
		currentSum = 0;

		for (int j = 0; j < iMaxRows; j++)
		{
			currentSum += twoDArray[j][i];
		}  //** next j

		if (i > 0)
		{
			//** only do this after you have summed the first row
			if (lastSum != currentSum)
			{
				return false;
			}
		}

		lastSum = currentSum;
	}  //** next i

	return true;
}
/**************************************************************
* Entry: received the array and the column and rows size
*
* Exit: it will return true if the sum is the same. if not it
* will exit by returning false. 
*
* Purpose: Reads the input and checks to see if they are the same
* in the diagonal direction
*
***************************************************************/
bool IsGoodDiag(int twoDArray[MAX_ROWS][MAX_COLS], int iMaxRows, int iMaxCols)
{
	int rightToLeftSum = 0;
	int leftToRightSum = 0;
	int rightToLeftSumColIdx = iMaxCols - 1;

	for (int i = 0; i < iMaxRows; i++, rightToLeftSumColIdx--)
	{

		leftToRightSum += twoDArray[i][i];
		rightToLeftSum += twoDArray[i][rightToLeftSumColIdx];

	}  //** next i

	if (leftToRightSum == rightToLeftSum)
	{
		return true;
	}
	else
	{
		return false;
	}
	return true;
}
/**************************************************************
* Entry: gets the array, column and rows 
*
* Exit: if they arent the same it will exit and if they are the same
* it will return true
*
* Purpose: check if the whole square is the same
*
***************************************************************/
bool IsSame(int twoDArray[MAX_ROWS][MAX_COLS], int iMaxRows, int iMaxCols)
{
	int lastSum = 0;

	if (IsGoodRows(twoDArray, iMaxRows, iMaxCols) && IsGoodCols(twoDArray, iMaxRows, iMaxCols) && IsGoodDiag(twoDArray, iMaxRows, iMaxCols))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**************************************************************
* Entry: gets the string from the user. 
*
* Exit: once all of the inputs from the array have been
* put into the new string
*
* Purpose: Reads the users string and inputs and returns their input
*
***************************************************************/
void PopArrayFromLine(int idx, int twoDArray[MAX_ROWS][MAX_COLS], const string& strLine, int& iColSize)
{
	char * pszToken = NULL;
	char  delims[] = " ";
	int iCol = 0;

	char szNewString[512] = { NULL };
	strcpy(szNewString, strLine.c_str());

	pszToken = strtok(szNewString, delims);

	// While there are any tokens left in "char_line"...
	while (pszToken != NULL)
	{
		twoDArray[idx][iCol] = atoi(pszToken);

		pszToken = strtok(NULL, delims);

		iCol++;

		iColSize = iCol;
	}

}
/**************************************************************
* Entry: gets the array in the main
*
* Exit: Once the max column size has been set
*
* Purpose: To get the array from the user and then inputs the 
* user input into another function to get rid of the spaces
*
***************************************************************/
void GetArrayData(int twoDArray[MAX_ROWS][MAX_COLS], int& iMaxRowSize, int& iMaxColSize)
{
	string strLine;
	iMaxRowSize = iMaxColSize = 0;

	for (int i = 0; i < MAX_ROWS; i++)
	{
		cout << "Enter a space delimited lines of integer values for line " << i + 1 << ". Enter up to 10 values or hit enter with nothing to quit" << endl;
		getline(cin, strLine);

		if (0 == strLine.length())
		{
			iMaxRowSize = i;
			return;
		}

		int iColSize;

		PopArrayFromLine(i, twoDArray, strLine, iColSize);

		iMaxColSize = max(iMaxColSize, iColSize);
	}

}
/**************************************************************
* Entry: from the twoDarray
*
* Exit: once it set the last array
*
* Purpose: make a blank array
*
***************************************************************/
void InitArray(int twoDArray[MAX_ROWS][MAX_COLS])
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			twoDArray[i][j] = 0;
		}
	}
}

int main(int argc, char* argv[])
{
	int iMaxRows = 0;
	int iMaxCols = 0;
	int twoDArray[MAX_ROWS][MAX_COLS];

	InitArray(twoDArray);

	GetArrayData(twoDArray, iMaxRows, iMaxCols);


	if (IsSame(twoDArray, iMaxRows, iMaxCols))
	{
		cout << "IS SAME" << endl;
	}
	else
	{
		cout << "NOT SAME" << endl;
	}

	string strAnyKey;

	cout << "Press any key to continue" << endl;
	cin >> strAnyKey;

	return 0;
}

