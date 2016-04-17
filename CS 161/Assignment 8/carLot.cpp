/*******************************************************************************
* Author: Grant Nakashima
* Date Created: 11/20/14
* Last Modification Date: 11/22/14
* Filename: carLot.cpp
*
* Overview:
* This program will use a struct and a vector. The user will choose which option they want
* to do at the start. The user will input information about cars that are in the lot. 
* The second option will show what cars are currently in inventory. It will exclude the cars
* that were sold. The third option will show a certain month and year's sales. 
*
* Input:
* The user will input information about the car like make, model, year of purchase etc.
* In the menu screen, the user will input a number from 1-4 to pick which option they 
* what to use. 
*
* Example input file contents:
*  1 : Toyota, Camry, 2014, 10, 23, Y, 
*
*Output: The program will output instructions for the user to input certain inputs.
* It will also show the total sales of a certain month.
*
*Output example: How much was the car sold for? The total profit is $10000.00
****************************************************************/

#include <iostream>		// for cout and cin
#include <vector>		// used for vectors
#include <algorithm>	// used for atoi
#include <iomanip>		
#include <string>		// need for string
#include <string.h>		
#include <stdlib.h> 

using namespace std;

typedef struct Date		// struct used to get purchase dates
{
	int day;
	int month;
	int year;
} DateType;

typedef struct Car		// car structs used to organize car information
{
	string make;
	string model;
	int year;
	Date datePurchased;
	double purchasePrice;
	bool isSold;
	Date dateSold;
	double salePrice;
} CarType;

void AddCarInfo(vector<CarType>& vtrCarType, vector<DateType>& vtrDateType, int&);			// function to get car info
void CheckInventory(vector<CarType>& vtrCarType, vector<DateType>& vtrDateType, int&);		// function to check inventory
void ProfitofMonth(vector<CarType>& vtrCarType, vector<DateType>& vtrDateType, int&);		// function to get the profits
vector<DateType> vtrDateType;		// vector for date
vector<CarType> vtrCarType;			// vector for car info
int MonthChecker(string);			
int DayChecker(string, string);
int arraySizeCounter = 0;
int iMonth;
string soldMonth, soldDay;
double totalProfitSale = 0;
double totalPurchase = 0;
int isSoldCounter = 0;

int main()
{
	int menuPick = 0;
	int a = 0;

	while (menuPick !=4)
	{
		cout << "Menu";
		cout << "\n1 Add Entry";
		cout << "\n2 List current inventory ";
		cout << "\n3 Profit for a month ";
		cout << "\n4 Quit " << endl << endl;
		cout << "Please pick an option. " << endl << endl;
		cin >> menuPick;
		cout << endl;

		switch (menuPick)			// switch used for menu
		{
		case 1:
			AddCarInfo(vtrCarType, vtrDateType, arraySizeCounter);
			break;
		case 2:
			CheckInventory(vtrCarType, vtrDateType, arraySizeCounter);
			break;
		case 3:
			ProfitofMonth(vtrCarType, vtrDateType, arraySizeCounter);
			break;
		case 4:
			cout << "Thank you for using this program. " << endl << endl;
			return 0;
		default:
			cout << "Invalid option. Please input a number from 1 to 4. " << endl;
			break;
		}
	}

	return 0;
}

/**************************************************************
* Entry: gets the array in the main
*
* Exit: when the user inputs quit
*
* Purpose: To get input from user 
*
***************************************************************/

void AddCarInfo(vector<CarType>& vtrCarType, vector<DateType>& vtrDateType, int& arraySizeCounter)
{
	CarType ct;
	DateType dt;
	string isSoldInput, monthInput, dayInput;


	for (int i = arraySizeCounter; i < 100; i++)		// will for size of array. max set at 100
	{
		cout << "If you would like to exit please enter: quit when you are inputting a new car make. " << endl << endl;
		cout << "What make is the car? " << endl;
		cin >> ct.make;

		if (ct.make == "quit")
		{
			cout << "Printing item list...." << endl;
			arraySizeCounter = i;
			break;
		}

		cout << "What model is the car? " << endl;
		cin >> ct.model;

		cout << "What year is the car? " << endl;
		cin >> ct.year;

		cout << "What is the purchase year of the car? " << endl;
		cin >> ct.datePurchased.year;

		cout << "What is the purchase month of the car? " << endl;
		cin >> monthInput;
		ct.datePurchased.month = MonthChecker(monthInput);

		cout << "What is the purchase day of the car? " << endl;
		cin >> dayInput;
		ct.datePurchased.day = DayChecker(dayInput, monthInput);

		cout << "What was the purchase price on the car? " << endl;
		cin >> ct.purchasePrice;

		cout << "Was the car sold? " << endl;
		cin >> isSoldInput;

		if (isSoldInput == "Y" || isSoldInput == "y")		// only get input if it is y
		{
			ct.isSold = true;

			cout << "What year was the car sold in? " << endl;
			cin >> ct.dateSold.year;

			cout << "What month was the car sold in? " << endl;
			cin >> soldMonth;
			ct.dateSold.month = MonthChecker(soldMonth);

			cout << "What day was the car sold on? " << endl;
			cin >> soldDay;
			ct.dateSold.day = DayChecker(soldDay, soldMonth);

			cout << "How much was the car sold for? " << endl;
			cin >> ct.salePrice;
		}
		else
		{
			ct.isSold= false;
		}
		vtrCarType.push_back(ct);
	}
}

void CheckInventory(vector<CarType>& vtrCarType, vector<DateType>& vtrDateType, int& arraySizeCounter)
{
	for (int i = 0; i < arraySizeCounter; i++)		// will print only cars that werent sold
	{
		if (vtrCarType[i].isSold == false)
		{
			cout << "Car make: " << vtrCarType[i].make << endl;
			cout << "Car model: " << vtrCarType[i].model << endl;
			cout << "Car year: " << vtrCarType[i].year << endl;
			cout << "Car purchase date: " << vtrCarType[i].datePurchased.year << "/";
			cout << vtrCarType[i].datePurchased.month << "/";
			cout << vtrCarType[i].datePurchased.day << endl;
			cout << "Car purchase price: " << "$" << vtrCarType[i].purchasePrice << endl;
			cout << endl;
		}	
		else
		{
			isSoldCounter++;		// calculate the cars inputs that got sold
		}
	}
	cout << "There are/is " << arraySizeCounter - isSoldCounter << " car(s)." << endl << endl;
	
	isSoldCounter = 0;
}

/**************************************************************
* Entry: gets the vector in the main after they input information
*
* Exit: Once profit has been printed
*
* Purpose: To get the information in vector from isSold and will
* calcuate the difference. 
*
***************************************************************/
void ProfitofMonth(vector<CarType>& vtrCarType, vector<DateType>& vtrDateType, int& arraySizeCounter)
{
	CarType ct;
	int iYear;
	

	cout << "Please enter in a month and a year to that month/year profits. " << endl;
	cout << "Please enter in a month. Please use numbers and not letters. "<< endl;
	cout << "1 for January and 12 for December. " << endl << endl;
	cin >> soldMonth;
	cout << endl;

	iMonth = MonthChecker(soldMonth);

	cout << "Please enter in a year. Please use numbers and not letters. " << endl;
	cin >> iYear;
	cout << endl;

	for (int i = 0; i < arraySizeCounter; i++)		// checks the year and month
	{
		if (iYear == vtrCarType[i].dateSold.year)
		{
			if (iMonth == vtrCarType[i].dateSold.month)
			{
				if (vtrCarType[i].isSold == true)
				{
					totalProfitSale = totalProfitSale + vtrCarType[i].salePrice;		//loops to get only sales profit
					totalPurchase = totalPurchase + vtrCarType[i].purchasePrice;
				}
				else
				{
					continue;
				}
			}
		}
	}
	cout << "The total profit is: " << fixed << showpoint << setprecision(2) << "$" << totalProfitSale - totalPurchase << endl << endl;

	totalProfitSale = 0;
	totalPurchase = 0;		// setting to 0 to make sure it will be 0 when it is used again
}

/**************************************************************
* Entry: gets the input from the user in AddCarInfo 
*
* Exit: once they input a valid input
*
* Purpose: To check if the month input is valid
*
***************************************************************/
int MonthChecker(string month)
{
	iMonth = atoi(month.c_str());

	while (true)
	{
		if (iMonth <= 12 && iMonth >= 1)			
		{
			return iMonth;
		}
		else
		{
			cout << "Invalid input. Please pick a number between 1 and 12." << endl;
			cin >> iMonth;
		}
	}
}

/**************************************************************
* Entry: gets the input from the user in AddCarInfo
*
* Exit: once they input a valid input
*
* Purpose: To check if the day input is valid
*
***************************************************************/
int DayChecker(string strDay, string strMonth)		// added month to set specific number of days to month
{
	int iDay = atoi(strDay.c_str());
	int iMonth = atoi(strMonth.c_str());

	while (true)
	{
		if (iMonth == 1 & iDay <= 31 && iDay >= 1)		// setting days to specific months
		{
			return iDay;
		}
		if (iMonth == 2 & iDay <= 28 && iDay >= 1)
		{
			return iDay;
		}
		if (iMonth == 3 & iDay <= 31 && iDay >= 1)
		{
			return iDay;
		}
		if (iMonth == 4 & iDay <= 30 && iDay >= 1)
		{
			return iDay;
		}
		if (iMonth == 5 & iDay <= 31 && iDay >= 1)
		{
			return iDay;
		}
		if (iMonth == 6 & iDay <= 30 && iDay >= 1)
		{
			return iDay;
		}
		if (iMonth == 7 & iDay <= 31 && iDay >= 1)
		{
			return iDay;
		}
		if (iMonth == 8 & iDay <= 31 && iDay >= 1)
		{
			return iDay;
		}
		if (iMonth == 9 & iDay <= 30 && iDay >= 1)
		{
			return iDay;
		}
		if (iMonth == 10 & iDay <= 31 && iDay >= 1)
		{
			return iDay;
		}
		if (iMonth == 11 & iDay <= 30 && iDay >= 1)
		{
			return iDay;
		}
		if (iMonth == 12 & iDay <= 31 && iDay >= 1)
		{
			return iDay;
		}
		else
		{
			cout << "Invalid input. " << endl;
			cin >> iDay;
		}
	}
}
