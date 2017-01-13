/****************************************************************
* Author: Grant Nakashima
* Date Created: 11/17/14
* Last Modification Date: 11/19/14
* Filename: findMode.cpp
*
* Overview:
* This program will get input from the user put them into a vector. It will then check
* the user's input and see which number appeared the most and assign that as the mode.
*
* Input:
* The user will input numbers one at a time. When they want to finish inputting numbers
* the user can input 99999 to quit.
*
* Example input file contents:
*  1 2 3 3 3 2 3 5 6 99999
*
*Output: The program will ask the user to input their number and let them know
* how to quit. It will then show the mode of their inputs.
*
*Output example: Enter in a number. Enter in 99999 to exit. Your mode is: 2
****************************************************************/

#include <iostream>                             // need for cin and cout
#include <string>                                  // need for strings
#include <algorithm>                            // need for atoi
#include <vector>                                 // need for vectors

using namespace std;

void FillVector(vector<int>&);  // have the user input their vector
bool GetValidInput(int&);                     // checks if input is valid
vector<int>GetMode(vector<int>);  // gets mode from vector
int countCheck(vector<int> mode, int);
void FindMax(vector<int> mode);
string strNumber;
int iDigit = 0;

int main()
{
	int maxNumber = 0;
	vector<int> mode;

	FillVector(mode);
	vector<int> NewModes = GetMode(mode);

	sort(NewModes.begin(),NewModes.end());
	NewModes.erase(unique(NewModes.begin(), NewModes.end()), NewModes.end());

	for (int i = 0; i < NewModes.size(); i++)
	{
		cout << "The modes of the input were: " << NewModes[i] << endl;
	}

	return 0;
}

/**************************************************************
* Entry: in main. gets vector from user
*
* Exit: when the user inputs 99999
*
* Purpose: To get inputs from the user to add to the vector
*
***************************************************************/
void FillVector(vector<int>& mode)
{
	while (iDigit != 99999)                          // allows users to quit inputting numbers
	{
		mode.push_back(iDigit);                     // puts input into vector
		GetValidInput(iDigit);                      // gets and checks input
	}
}

/**************************************************************
* Entry: in fill vector. 
*
* Exit: once they input a valid input
*
* Purpose: To check if the number input is valid
*
***************************************************************/
bool GetValidInput(int& iDigit)
{
	int i;
	iDigit = 0;
	string strNumber;

	while (true)
	{
		cout << "Enter in a number. Enter in 99999 to exit. " << endl;
		cin >> strNumber;

		for (i = 0; i < strNumber.length(); i++)
		{
			if (!isdigit(strNumber[i]))                       // if there are letters in the input it will break
			{
				break;
			}
		}
		if (strNumber.length() == i)                   // if the loop number matches string length valid
		{
			iDigit = atoi(strNumber.c_str());            // changes from string to int
			return true;
		}
		else
		{
			cout << "Invalid input. " << endl;
		}
	}
}
/**************************************************************
* Entry: in main. gets mode from fill vector
*
* Exit: when it returns modes
*
* Purpose: to find the modes of the users input
*
***************************************************************/
vector<int> GetMode(vector<int>mode)
{
	vector<int>count(mode.size());		// sets vector size to the size of the original vector
	vector<int>number;					// vector that will contain trimmed mode
	int highCount = 0;					// determine which count is highest

	sort(mode.begin(), mode.end());		// sort vector for easier counting

	for (int i = 0; i < mode.size(); i++)
	{
		for (int j = 1; j < mode.size(); j++)
		{
			if (mode[j] == mode[i])		// sets count number for each number. 
			{
				count[i]++;
			}
		}
	}

	for (int i = 0; i < mode.size(); i++)
	{
		if (count[i] >= highCount)		// checking each count for each number and seeing which is the highest
		{
			highCount = count[i];		// setting new high count
		}
	}

	for (int i = 0; i < mode.size(); i++)
	{
		if (count[i] == highCount)			// will push number into vector if it has the highest count
		{
			number.push_back(mode[i]);
		}
	}
	return number;
}
