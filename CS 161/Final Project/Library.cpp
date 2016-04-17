/**********************************************************************************************************
* Author: Grant Nakashima
* Date Created: 12/02/14
* Last Modification Date: 12/06/14
* Filename: Library.cpp
*
* Overview:
* The library.cpp holds all of functions. The add member function adds members to the member vector. Add books
* function adds books into the book vector. checkoutBook function allows the user to input specific member id
* and book id to check out a book. It is added into their list of checked out books. Return book function removes
* specific books from a specific patron's list. Request book function puts books on hold. It also prevents books
* for being requested from multiple members. Pay fine function allows the user to pay off any fees they might have.
* Increment current date function increments the day and applies fines if they are over due. The last two functions
* display either the patron's information or the book's information
*
* Input:
* The return book function asks for the member's id.
*
* Example input file contents:
*  987
*
* Output: Most of the functions will explain if the book id and member id is a part of the system.
* In the checkoutBook function will display if it is checked out, on hold by another patron, and
* what book was checked out. Other functions will display similar information.
*
* Output example: Please enter in your member ID and the book ID" , "Please enter in your member ID"
* Titanic was returned.
**********************************************************************************************************/

#include "Library.h"
#include "Patron.h"
#include "Book.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

static const double DAILY_FINE = 0.1;

Library::Library()
{
	holdings.reserve(100);			// set max books to 100
	members.reserve(100);			// set max members to 100
	currentDate = 0;				// start at day 0
}

void Library::addBook()			// adds books into the library 
{
	Book book;									// making object
	string tempBookID, tempAuthor, tempTitle;		// string input will get used to set to new book

	cout << "Please enter in a Book ID Number." << endl;
	cin.ignore();
	getline(cin, tempBookID);
	book.setIdCode(tempBookID);			// set book idcode

	cout << "Enter the title of the book. " << endl;
	getline(cin, tempTitle);

	book.setTitle(tempTitle);			// set book title

	cout << "Enter the author of the book. " << endl;
	getline(cin, tempAuthor);
	cout << endl;

	book.setAuthor(tempAuthor);			// set book author

	for (int i = 0; i < holdings.size(); i++)
	{
		if (holdings[i].getIdCode() == tempBookID)			// check if book id already registered
		{
			cout << "That ID is currently being used. " << endl << endl;
			return;
		}
	}

	holdings.push_back(book);		// if vaild make new book
}

void Library::addMember()			// adding new members to library system
{
	Patron patron;
	string tempPatID, tempPatName;

	cout << "Please enter in a Patron ID number. " << endl;
	cin.ignore();
	getline(cin, tempPatID);
	patron.setIdNum(tempPatID);		// set member id

	cout << "Please enter in your name. " << endl;
	getline(cin, tempPatName);
	patron.setName(tempPatName);		// set member name
	cout << endl;

	for (int i = 0; i < members.size(); i++)
	{
		if (members[i].getIdNum() == tempPatID)		// check if id already used
		{
			cout << "That ID is currently being used. " << endl << endl;
			return;
		}
	}

	members.push_back(patron);		// push new member into system
}

void Library::checkOutBook(string patronID, string bookID)			// parameters : patronID and bookID. check out book if avaliable and adds to patron's holdings
{
	int x = 0;
	Patron* randomPatron = &members[x];			// making patron object

	for (int i = 0; i < members.size(); i++)
	{
		if (patronID == members[i].getIdNum())
		{
			randomPatron = &members[i];		// get specific member
			x = i;
		}
	}

	bool inLibrary = false;

	for (int i = 0; i < holdings.size(); i++)
	{
		if (holdings[i].getIdCode() == bookID)		// check if book is in library
		{
			inLibrary = true;
			continue;
		}
	}

	if (!inLibrary)
	{
		cout << "That book is not in the library. " << endl << endl;
		return;
	}

	else
	{
		inLibrary = false;			// to check if members id is valid
	}

	for (int i = 0; i < members.size(); i++)
	{
		if (members[i].getIdNum() == patronID)		// check if Patron is member of library
		{
			inLibrary = true;
			continue;
		}
	}

	if (!inLibrary)
	{
		cout << "That person is not a member of this library. " << endl << endl;
		return;
	}

	for (int i = 0; i < holdings.size(); i++)
	{
		if (bookID == holdings[i].getIdCode())		// checking for specific book
		{
			if (holdings[i].getLocation() == CHECKED_OUT)		// check if book is checked out
			{
				cout << "That book has been checked out. " << endl << endl;
				return;
			}

			if (bookID == holdings[i].getIdCode())
			{
				if (holdings[i].getLocation() == ON_HOLD && holdings[i].getRequestedBy() != randomPatron)		// check if book is on hold
				{
					cout << "That book is on hold at the moment. " << endl << endl;;
					return;
				}
			}


		}

	}

	for (int i = 0; i < holdings.size(); i++)
	{
		if ((bookID == holdings[i].getIdCode() && holdings[i].getLocation() == ON_SHELF) || (holdings[i].getLocation() == ON_HOLD && holdings[i].getRequestedBy() == randomPatron))		// update books
		{
			holdings[i].setCheckedOutBy(randomPatron);		// set checked out to member
			holdings[i].setDateCheckedOut(currentDate);		// set check out date to current date
			holdings[i].setLocation(CHECKED_OUT);			// set location to checked out
		}
	}

	for (int i = 0; i < holdings.size(); i++)		// update requested by
	{
		if (bookID == holdings[i].getIdCode())
		{
			if (holdings[i].getLocation() == CHECKED_OUT && holdings[i].getRequestedBy() == randomPatron)		// resetting requested by to null
			{
				holdings[i].setRequestedBy(NULL);
			}
		}
	}

	for (int i = 0; i < holdings.size(); i++)
	{
		if (bookID == holdings[i].getIdCode())
		{
			members[x].addBook(&holdings[i]);		// add book to members list

			cout << holdings[i].getTitle() << " was checked out by: " << members[x].getName() << endl;

		}
	}
	cout << endl;
}

void Library::returnBook(string bookID) // parameter is bookID. returnBook removes book from patron's list. 
{
	bool inLibrary = false;
	int bookNum = 0, x = 0;
	Book* book = &holdings[bookNum];
	Patron* patron = &members[x];
	string patronID;

	cout << "Please input your member ID. " << endl;		// makes removing book easier
	cin >> patronID;


	for (int i = 0; i < holdings.size(); i++)
	{
		if (holdings[i].getIdCode() == bookID)		// check if book is in library
		{
			inLibrary = true;
			bookNum = i;
			continue;
		}
	}

	if (!inLibrary)
	{
		cout << "That book is not in the library. " << endl << endl;
		return;
	}
	else
	{
		inLibrary = false;
	}

	for (int i = 0; i < members.size(); i++)
	{
		if (members[i].getIdNum() == patronID)		// check if member is in library system
		{
			inLibrary = true;
			x = i;
			continue;
		}
	}

	if (!inLibrary)
	{
		cout << "That ID is not in the library system. " << endl << endl;
		return;
	}

	for (int i = 0; i < holdings.size(); i++)
	{
		if (holdings[i].getIdCode() == bookID)
		{
			if (holdings[i].getLocation() != CHECKED_OUT)		// check if book is in library
			{
				cout << "That book is not checked out. " << endl << endl;;
				return;
			}
		}
	}

	for (int i = 0; i < holdings.size(); i++)		// loop to remove book
	{
		if (holdings[i].getIdCode() == bookID)
		{
			if (holdings[i].getLocation() == CHECKED_OUT)		// returning book. changing from checked out to on shelf
			{
				if (holdings[i].getRequestedBy() != NULL)		// checking if another Patron has requested the book
				{
					holdings[i].setLocation(ON_HOLD);		// making book reserved for other patron
					holdings[i].setDateCheckedOut(currentDate);		// set checked out date to current date
				}

				else
				{
					holdings[i].setLocation(ON_SHELF);		// no request so book location on shelf
					holdings[i].setDateCheckedOut(currentDate);
				}

				patron[x].removeBook(book);		// remove book from patron

				cout << holdings[i].getTitle() << " has been returned. " << endl;
			}
		}
	}
	cout << endl;
}

void Library::requestBook(string patronID, string bookID)		// pass member id and book id to request book function to check if book has been requested
{
	bool inLibrary = false;
	int patronNum, bookNum;

	for (int i = 0; i < holdings.size(); i++)
	{
		if (holdings[i].getIdCode() == bookID)		// check if book is in library
		{
			inLibrary = true;
			bookNum = i;
			continue;
		}
	}

	if (!inLibrary)
	{
		cout << "That book is not in the library. " << endl << endl;
		return;
	}
	else
	{
		inLibrary = false;
	}

	for (int i = 0; i < members.size(); i++)
	{
		if (members[i].getIdNum() == patronID)		// check if Patron is member of library
		{
			patronNum = i;
			inLibrary = true;
			continue;
		}
	}

	if (!inLibrary)
	{
		cout << "That person is not a member of this library. " << endl << endl;
		return;
	}

	Patron* patron = &members[patronNum];		// patron object
	Book* book = &holdings[bookNum];			// book object

	if (book->getRequestedBy() == NULL)			// checking if book has been requested
	{
		if (book->getLocation() == ON_SHELF)	// if book on shelf set location to on hold
		{
			book->setLocation(ON_HOLD);
			book->setRequestedBy(patron);
			cout << patron->getName() << " has been put on the wait list for: " << book->getTitle() << endl;
		}
		else if (book->getLocation() == CHECKED_OUT)	// only set request to patron. didn't change location
		{
			book->setRequestedBy(patron);
			cout << patron->getName() << " has been put on the wait list for: " << book->getTitle() << endl;
		}
	}

	else
	{
		cout << "This book has been requested by someone already. " << endl << endl;;
		return;
	}
	cout << endl;
}

void Library::incrementCurrentDate()		// increments current date and daily fine if their books are past due
{
	currentDate++;

	for (int i = 0; i < members.size(); i++)
	{
		for (int j = 0; j < (members[i].getCheckedOutBooks()).size(); j++)		// loop for only the number of checked out books
		{
			if ((currentDate - (((members[i].getCheckedOutBooks())[j])->getDateCheckedOut())) >((members[i].getCheckedOutBooks())[j])->Book::getCheckOutLength())		// checking if the specific book is over max checkout length before fee
			{
				members[i].amendFine(DAILY_FINE);
			}
		}
	}
	cout << endl;
}

void Library::payFine(string patronID, double payment)		// parameters: patronID and payment. user will pay off bill using this option
{
	bool inLibrary = false;

	for (int i = 0; i < members.size(); i++)
	{
		if (members[i].getIdNum() == patronID)		// check if Patron is member of library
		{
			inLibrary = true;
			continue;
		}
	}

	if (!inLibrary)
	{
		cout << "That person is not a member of this library. " << endl << endl;
		return;
	}

	for (int i = 0; i < members.size(); i++)
	{
		if (members[i].getIdNum() == patronID) // gets specific patron
		{
			payment *= -1;

			members[i].amendFine(payment);		// adds payment into fine function 
		}
	}

	cout << endl;
}

void Library::viewPatronInfo(string patronID)		// parameter: patronID. user can view specific members information
{
	bool inLibrary = false;
	int patronNum = 0;

	for (int i = 0; i < members.size(); i++)
	{
		if (members[i].getIdNum() == patronID)		// if ID matches it will print
		{
			inLibrary = true;
			patronNum = i;
			continue;
		}
	}

	if (!inLibrary)			// if inLibrary is false it will print out not a member
	{
		cout << "That person is not a member of this library. " << endl << endl;
		return;
	}

	Patron* patron = &members[patronNum];

	cout << "Current date: " << currentDate << endl;
	cout << "Patron ID: " << patron->getIdNum() << endl;
	cout << "Patron name: " << patron->getName() << endl;
	cout << "Current fees: $" << fixed << setprecision(2) << patron->getFineAmount() << endl;		// get 0.00 look
	cout << "Checked out books: ";

	for (int j = 0; j < holdings.size(); j++)
	{
		if (holdings[j].getCheckedOutBy() == patron)		// seeing if patron checked out the book
		{
			if (holdings[j].getLocation() == CHECKED_OUT)
			{
				cout << holdings[j].getTitle() << " ";			// print out specific book patron checked out
			}
		}
	}

	cout << endl << endl;
}

void Library::viewBookInfo(string bookID)		// parameter: bookId. View information about specific book
{
	bool inLibrary = false;

	for (int i = 0; i < holdings.size(); i++)
	{
		if (holdings[i].getIdCode() == bookID)		// checking for specific book
		{
			inLibrary = true;		// if book isn't found it will be used to print out that book doesn't exist

			cout << "Book ID: " << holdings[i].getIdCode() << endl;
			cout << "Book Title: " << holdings[i].getTitle() << endl;
			cout << "Book Author: " << holdings[i].getAuthor() << endl;
			cout << "Book Location: ";

			if (holdings[i].getLocation() == 0)		// print out location instead of numbers
			{
				cout << "On shelf" << endl;
			}
			else if (holdings[i].getLocation() == 1)
			{
				cout << "On hold" << endl;
			}
			else if (holdings[i].getLocation() == 2)
			{
				cout << "Checked Out" << endl;
			}
			cout << "Current date: " << currentDate << endl;
		}
	}

	if (inLibrary == false)
	{
		cout << "That book does not exist. " << endl << endl;
		return;
	}

	for (int i = 0; i < holdings.size(); i++)
	{
		if (holdings[i].getIdCode() == bookID)		// checking if specific book is requested and printing who requested it
		{
			if (holdings[i].getRequestedBy() != NULL)
			{
				cout << "Book requested by: " << holdings[i].getRequestedBy()->getName() << endl;		// pointing to members name
			}
		}
	}

	for (int i = 0; i < holdings.size(); i++)
	{
		if (holdings[i].getIdCode() == bookID)
		{
			if (holdings[i].getLocation() == CHECKED_OUT)		// checking if specific book is checked out
			{
				cout << "Book checked out by: " << holdings[i].getCheckedOutBy()->getName() << endl;			// changed to name
				cout << "Book due: " << holdings[i].getDateCheckedOut() + Book::CHECK_OUT_LENGTH << endl;		// find out when is due
			}
		}
	}
	cout << endl << endl;
}
