/**********************************************************************************************************
* Author: Grant Nakashima
* Date Created: 12/02/14
* Last Modification Date: 12/06/14
* Filename: menu.cpp
*
* Overview:
* The menu.cpp consists of a while loop and switch. It is the display that book, patron and library
* are connected to. The user will input which function they want to use and then get asked for further
* input if that function requires it.
*
* Input:
* The user will input a number between 1 - 10 to go into certain functions.
*
* Example input file contents:
*  1 : add books
*
*Output: The program will output instructions for the user to input certain inputs.
* In general it is the members id number or the book id.
*
*Output example: Please enter in your member ID and the book ID" , "Please enter in your member ID"
**********************************************************************************************************/

#include "Library.h"
#include "Patron.h"
#include "Book.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool checkValidMenu(int&);		// function to check menu input. prevent infinite loop

int main()
{
	Library privateLibrary;

	int menuPick = 0;
	string patronID, bookID;
	char menu;
	double payment;

	while (menuPick != 10)
	{
		cout << "Menu";
		cout << "\n1 Add Book";
		cout << "\n2 Add Member";
		cout << "\n3 Check out book";
		cout << "\n4 Return book";
		cout << "\n5 Request book";
		cout << "\n6 Pay fine";
		cout << "\n7 Increment Current Date";
		cout << "\n8 View Patron Info";
		cout << "\n9 View Book info ";
		cout << "\n10 Quit " << endl << endl;
		checkValidMenu(menuPick);
		cout << endl;

		switch (menuPick)
		{
		case 1:
			privateLibrary.addBook();
			break;
		case 2:
			privateLibrary.addMember();
			break;
		case 3:
			cout << "Please enter in your member ID and the book ID" << endl;
			cout << "Please enter in your member ID" << endl;
			cin >> patronID;
			cout << endl;
			cout << "Please enter in the book ID" << endl;
			cin >> bookID;
			cout << endl;
			privateLibrary.checkOutBook(patronID, bookID);
			break;
		case 4:
			cout << "Please enter in the book ID" << endl;
			cin >> bookID;
			cout << endl;
			privateLibrary.returnBook(bookID);
			break;
		case 5:
			cout << "Please enter in your member ID and the book ID" << endl;
			cout << "Please enter in your member ID" << endl;
			cin >> patronID;
			cout << endl;
			cout << "Please enter in the book ID" << endl;
			cin >> bookID;
			cout << endl;
			privateLibrary.requestBook(patronID, bookID);
			break;
		case 6:
			cout << "Please enter in your member ID and how much you want to pay" << endl;
			cout << "Please enter in your member ID" << endl;
			cin >> patronID;
			cout << endl;
			cout << "Please enter in how much you want to pay. " << endl;
			cin >> payment;
			cout << endl;
			privateLibrary.payFine(patronID, payment);
			break;
		case 7:
			privateLibrary.incrementCurrentDate();
			break;
		case 8:
			cout << "Please enter in your member ID" << endl;
			cin >> patronID;
			privateLibrary.viewPatronInfo(patronID);
			break;
		case 9:
			cout << "Please enter in the book ID" << endl;
			cin >> bookID;
			cout << endl;
			privateLibrary.viewBookInfo(bookID);
			break;
		case 10:
			cout << "Thank you for using the library. " << endl << endl;
			return 0;
		default:
			cout << "Invalid option. Please input a number from 1 to 10. " << endl;
			break;
		}
	}
	return 0;
}

/**************************************************************
* Entry: in fill vector.
*
* Exit: once they input a valid input
*
* Purpose: To check if the number input is valid
*
***************************************************************/

bool checkValidMenu(int& iDigit)
{
	int i;
	iDigit = 0;
	string strNumber;

	while (true)
	{
		cout << "Please pick an option. From 1 to 10. " << endl << endl;
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
			cout << "Invalid input. " << endl << endl;
		}
	}
}
