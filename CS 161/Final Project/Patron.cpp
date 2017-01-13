/**********************************************************************************************************
* Author: Grant Nakashima
* Date Created: 12/02/14
* Last Modification Date: 12/06/14
* Filename: Patron.cpp
*
* Overview:
* The patron.cpp supports library.cpp. The functions in this program gets and sets the input
* from the user. For example, if the user wants to use the patron's info, patron will get
* get that patrons name, id, etc. The remove book function will remove only specified books.
*
* Input:
* no input
*
* Example input file contents:
*  none
*
* Output: no out in patron
*
* Output example: N/A
**********************************************************************************************************/

#include "Patron.h"
#include "Book.h"
#include "Library.h"
#include <string>

using namespace std;

Patron::Patron()		// blank constructor
{
	checkedOutBooks.reserve(100);
	fineAmount = 0.0;
}

Patron::Patron(string idn, string n)		// default constructor. parameters IdNum and name. set max num of books to 100 and fine amount starts at 0
{
	idNum = idn;
	name = n;
	checkedOutBooks.reserve(100);
	fineAmount = 0.0;
}

string Patron::getIdNum()		// receive certain patron's id when needed
{
	return idNum;
}

void Patron::setIdNum(string PNum)		// set id num to certain patron when creating new patron
{
	idNum = PNum;
}

string Patron::getName()		// get name of requested patron
{
	return name;
}

void Patron::setName(string n)		// set name to certain patron when creating new patron
{
	name = n;
}

vector<Book*> Patron::getCheckedOutBooks()		// vector of books patron has. gets books when books added to vector. used to display books
{
	return checkedOutBooks;
}

void Patron::addBook(Book* b)		// add books into patron's list of books checked out. 
{
	checkedOutBooks.push_back(b);
}

void Patron::removeBook(Book* b)		// remove certain book from patron's vector of books
{
	for (int i = 0; i < checkedOutBooks.size(); i++)
	{
		if (checkedOutBooks[i]->getIdCode() == b->getIdCode())		// getting specific book
		{
			checkedOutBooks.erase(checkedOutBooks.begin() + i);
		}
	}
}

double Patron::getFineAmount()		// receiving fine amount patron has built up
{
	return fineAmount;
}

void Patron::amendFine(double amount)		// determines total past due amount. used to increase due amount or is used for patron's payments
{
	fineAmount = amount + fineAmount;		// positive means owe money negative means credit
}
