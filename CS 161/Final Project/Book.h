//
//  Book.h
//  examples
//
//  Created by Tim Alcon on 11/25/14.
//  Copyright (c) 2014 Tim Alcon. All rights reserved.
//

#ifndef examples_Book_h
#define examples_Book_h
#include <string>

using namespace std;

class Patron;


enum Locale { ON_SHELF = 0 , ON_HOLD = 1, CHECKED_OUT =2};

class Book
{
private:
	std::string idCode;
	std::string title;
	std::string author;
	Locale location;
	Patron* checkedOutBy;
	Patron* requestedBy;
	int dateCheckedOut;
public:
	static const int CHECK_OUT_LENGTH = 21;
	Book();
	Book(std::string idc, std::string t, std::string a);
	int getCheckOutLength();
	std::string getIdCode();
	void setIdCode(string idc);
	std::string getTitle();
	void setTitle(string t);
	std::string getAuthor();
	void setAuthor(string a);
	Locale getLocation();
	void setLocation(Locale lo);
	Patron* getCheckedOutBy();
	void setCheckedOutBy(Patron* p);
	Patron* getRequestedBy();
	void setRequestedBy(Patron* p);
	int getDateCheckedOut();
	void setDateCheckedOut(int d);
};

#endif
