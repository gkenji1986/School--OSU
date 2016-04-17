/*******************************************************************************
* Author: Grant Nakashima
* Date Created: 11/25/14
* Last Modification Date: 11/25/14
* Filename: geom.cpp
*
* Overview:
* This program will use two classes to determine the slope of a line. The user will input the 
* coordinates and it will take the input and calculate the slope. 
*
* Input:
* The user will input 4 different coordinates. Two x coordinates and two y coordinates.
*
* Example input file contents:
*  0,0  1,2
*
*Output: The program will output the slope of if the slope is vertical
*
*Output example: The slope is 1.33333
****************************************************************/

#include <iostream>			// need for cin and cout
#include <string>			// need for string
#include <cmath>			
#include <algorithm>		
#include <math.h>			// need for NAN

using namespace std;

class Point
{
private:
	double xCoordinate;
	double yCoordinate;

public:
	Point(double x = 0, double y = 0)
	{
		xCoordinate = x;
		yCoordinate = y;
	}
	double getX()
	{
		return xCoordinate;
	}
	double getY()
	{
		return yCoordinate;
	}
	double distanceTo(Point p2)			// calculate distance between coordinates
	{
		double coord1, coord2, coord3, coord4;

		coord1 = xCoordinate - p2.xCoordinate;
		coord2 = yCoordinate - p2.yCoordinate;
		coord3 = pow(coord1, 2) + pow(coord2, 2);				
		coord4 = sqrt(coord3);						// gets distance between coordinates

		return coord4;
	}
};

class LineSegment
{
private:
	Point beginP1;
	Point endP2;

public:
	LineSegment(Point P1, Point P2)
	{
		beginP1 = P1;
		endP2 = P2;
	}
	Point getP1()
	{
		return beginP1;
	}
	Point getP2()
	{
		return endP2;
	}
	void setP1(Point P1)
	{
		beginP1 = P1;
	}
	void setP2(Point P2)
	{
		endP2 = P2;
	}
	double length()
	{
		return beginP1.distanceTo(endP2);
	}
	double slope()			
	{
		if ((endP2.getY() - beginP1.getY()) / (endP2.getX() - beginP1.getX()) != 0)
		{
			return (endP2.getY() - beginP1.getY()) / (endP2.getX() - beginP1.getX());		// y2 -y1/ x2-x1 to get slope
		}
		else if ((endP2.getY() - beginP1.getY()) / (endP2.getX() - beginP1.getX()) == 0)
		{
			return 0;		// return zero if slope is zero
		}
		else
		{
			return NAN;
		}
	}
};

int main()
{
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0;			// initialize coordinates to 0
	string strRepeat;		// determine to loop again

	while (strRepeat != "n")
	{
		cout << "Please enter in coordinates in for the x coordinate in point 1. " << endl;
		cin >> x1;
		cout << "Please enter in coordinates in for the y coordinate in point 1. " << endl;
		cin >> y1;

		cout << "Please enter in coordinates in for the x coordinate in point 2. " << endl;
		cin >> x2;
		cout << "Please enter in coordinates in for the y coordinate in point 2. " << endl;
		cin >> y2;
		cout << endl;

		Point p1(x1, y1);		// set point 1 and 2
		Point p2(x2, y2);

		LineSegment Coord(p1, p2);		// get slope

		cout << "The lines length is: " << Coord.length() << endl;

		if (isinf(Coord.slope()) == true)			
		{
			cout << "The line is vertical. " << endl;
		}
		else
		{
			cout << "The slope of the line is: " << Coord.slope() << endl << endl;
		}

		cout << "Would you like to input another coordinate? Input y for yes and n for no. " << endl;
		cin >> strRepeat;

		for (int i = 0; i < strRepeat.length(); i++)
		{
			tolower(strRepeat[i]);		// make sure input only lower case
		}
	}
	return 0;
}

