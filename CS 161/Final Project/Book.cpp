/**********************************************************************************************************
* Author: Grant Nakashima
* Date Created: 12/02/14
* Last Modification Date: 12/06/14
* Filename: Book.cpp
*
* Overview:
* The book.cpp are all the descriptive parts of book. The functions in book either get or set the parts
* the user is looking for. For example, it will set the books name, title or author.
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

#include "Book.h"
#include "Patron.h"
#include "Library.h"
#include <string>

using namespace std;

Book::Book()
{
	checkedOutBy = NULL;
	requestedBy = NULL;
	dateCheckedOut = 0;
	location = ON_SHELF;
}

Book::Book(string idc, string t, string a)		// parameters: idCode, title and author. for new books
{
	idCode = idc;
	title = t;
	author = a;
	checkedOutBy = NULL;		// new so hasn't been checked out yet
	requestedBy = NULL;			// new so hasn't been requested yet
	dateCheckedOut = 0;			// default date checked out is 0
	location = ON_SHELF;		// starts on shelf
}

string Book::getIdCode()		// returns idCode when needed. example for printing
{
	return idCode;
}

void Book::setIdCode(string idc)		// parameter: idCode. used when making new book. sets id to that book
{
	idCode = idc;
}

string Book::getTitle()			// returns title. example: for printing
{
	return title;
}

void Book::setTitle(string t)		// parameter: title. used when making new book. sets title to book object
{
	title = t;
}

string Book::getAuthor()		// returns author of book object. 
{
	return author;
}

void Book::setAuthor(string a)	// parameter: author. used when making new book. sets author to book object
{
	author = a;
}

int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}

Locale Book::getLocation()		// gives location of book. either on shelf, on hold or checked out
{
	return location;
}

void Book::setLocation(Locale lo)	// parameter: location. used to change the location of the book. like when returned or checked out 
{
	location = lo;
}

Patron* Book::getCheckedOutBy()		// gives who checked out specified book. patron pointer to patron's books
{
	return checkedOutBy;
}

void Book::setCheckedOutBy(Patron* checkOut)	// parameter is patron object. set the object to checked out book
{
	checkedOutBy = checkOut;
}

Patron* Book::getRequestedBy()		// gives who requested specific book
{
	return requestedBy;
}

void Book::setRequestedBy(Patron* requestB)		// parameter is patron object. set object to requested book
{
	requestedBy = requestB;
}

int Book::getDateCheckedOut()		// returns when the book was checked out
{
	return dateCheckedOut;
}

void Book::setDateCheckedOut(int dateCout)		// parameter : current date. sets the checkedout day to the current day 
{
	dateCheckedOut = dateCout;
}

