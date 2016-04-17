/*******************************************************************************
* Author: Grant Nakashima
* Date Created: 11/28/14
* Last Modification Date: 11/29/14
* Filename: carLot2.cpp
*
* Overview:
* This program will uses classes and a vector. It uses 3 classes; date, car, carlot. The user will choose which 
* option they want to do at the start. The user will input information about cars that are in the lot.
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

#include <iostream>			// for cin and cout
#include <string>			// for strings
#include <vector>			// for vector
#include <iomanip>			// for setprecision
#include <math.h>			// for NAN

using namespace std;

class Date					
{
private:
	int year;
	int month;
	int day;
public:
	Date();							//default constructor
	Date(int y, int m, int d);		// constructor with parameters
	int getYear();					
	void setYear(int y);			// mutator
	int getMonth();
	void setMonth(int m);
	int getDay();
	void setDay(int d);
};

class Car				
{
private:
	string make;			//make for car
	string model;			// model for car
	int year;				// year
	Date datePurchased;		// when the car was bought
	double purchasePrice;	// how much it was bought at
	bool isSold;			// determines if it was sold
	Date dateSold;			// date it was sold
	double salePrice;		// amount it was sold at
public:
	Car();		// constructor
	Car(string make, string model, int y, Date dP, double pP, bool iS, Date dS, double sP);		//constructor for sold car
	~Car();		// destructor
	Car(string make, string model, int y, Date dP, double pP, bool iS);		//constructor not sold
	string getMake();
	void setMake(string make);
	string getModel();
	void setModel(string model);
	int getYear();
	void setYear(int y);
	Date getDatePurchased();
	void setDatePurchased(Date dP);
	double getPurchasePrice();
	void setPurchasePrice(double pP);
	bool getIsSold();
	void setIsSold(bool iS);
	Date getDateSold();
	void setDateSold(Date dS);
	double getSalePrice();
	void setSalePrice(double sP);
	double getProfit();
};

class CarLot
{
private: 
	vector <Car> newCar;			//cars get pushed into vector
public:
	CarLot();			// default constructor
	~CarLot();			// destructor
	void addCar(Car newC);		// adds car into vector
	void listCurrentInv();		// list cars
	double getMonthProfit(int year, int month);		// gets profit
};

void addCarEntry(Car&, Car&, CarLot&);			//function to add cars
void inventoryList(CarLot&);					// functions to hold listcurrentinv()
void profitOfMonth(CarLot&);					// holds getMonthProfit
int validDayInput(int&, int&);					// function to get valid day input
int validMonthInput(int&);						// function to get valid month

string make, model;
int year;
Date dP;
double pP;
bool iS;
Date dS;
double sP;
int arraySize = 0;

int main()
{
	int menuPick = 0;			// used for switch
	Car newCar(make, model, year, dP, pP, iS, dS,sP);		// object pass to addCar
	Car newCar2(make, model, year, dP, pP, iS);				// object pass to addCar not sold
	CarLot GrantLot;			// object for carlot

	while (menuPick != 4)
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
			addCarEntry(newCar, newCar2, GrantLot);
			break;
		case 2:
			inventoryList(GrantLot);
			break;
		case 3:
			profitOfMonth(GrantLot);
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
* Entry: Default constructor
*
* Exit: Once profit has been printed
*
* Purpose: To get the information in vector from isSold and will
* 
*
***************************************************************/

Date::Date()
{

}

/**************************************************************
* Entry: Constructor
*
* Exit: done setting day
*
* Purpose: construct date
*
***************************************************************/
Date::Date(int y, int m, int d)
{
		year = y;
		month = m;
		day = d;
}
/**************************************************************
* Entry: when getting some date
*
* Exit: returns year
*
* Purpose: get year
*
***************************************************************/
int Date::getYear()
{
	return year;
}
/**************************************************************
* Entry: when need to set a year integer
*
* Exit: once it sets year
*
* Purpose: sets year integer
*
***************************************************************/
void Date::setYear(int y)
{
	year = y;
}
/**************************************************************
* Entry: when need to set month
*
* Exit: returns month
*
* Purpose: to get month
*
***************************************************************/
int Date::getMonth()
{
	return month;
}
/**************************************************************
* Entry: when getting user input month
*
* Exit: sets month
*
* Purpose: set month to date
*
***************************************************************/
void Date::setMonth(int m)
{
	month = m;
}
/**************************************************************
* Entry: when you need day
*
* Exit: returns day
*
* Purpose: get day from vector
*
***************************************************************/
int Date::getDay()
{
	return day;
}
/**************************************************************
* Entry: when day needs to get set and added to vector
*
* Exit: sets day
*
* Purpose: set day 
*
***************************************************************/
void Date::setDay(int d)
{
	day = d;
}
/**************************************************************
* Entry: Default constructor
*
* Exit: done constructing
*
* Purpose: need default constructor for class
*
***************************************************************/
Car::Car()
{

}
/**************************************************************
* Entry: Car constructor
*
* Exit: done making construct
*
* Purpose: constructor when bool is true
*
***************************************************************/
Car::Car(string m, string mdl, int y, Date dP, double pP, bool iS, Date dS, double sP)
{
	make = m;
	model = mdl;
	year = y;
	datePurchased = dP;
	purchasePrice = pP;
	isSold = iS;
	dateSold = dS;
	salePrice = sP;
}
/**************************************************************
* Entry: Car destructor
*
* Exit: done destructing
*
* Purpose: destructing
*
***************************************************************/
Car::~Car()
{

}
/**************************************************************
* Entry: Car constructor
*
* Exit: done making construct
*
* Purpose: constructor when bool is false
*
***************************************************************/
Car::Car(string m, string mdl, int y, Date dP, double pP, bool iS)
{
	make = m;
	model = mdl;
	year = y;
	datePurchased = dP;
	purchasePrice = pP;
	isSold = iS;
}
/**************************************************************
* Entry: need to access make
*
* Exit: get make
*
* Purpose: access make
*
***************************************************************/
string Car::getMake()
{
	return make;
}
/**************************************************************
* Entry: setting input to make
*
* Exit: set make
*
* Purpose: set make to get put into vector
*
***************************************************************/
void Car::setMake(string m)
{
	make = m;
}
/**************************************************************
* Entry: need to access model
*
* Exit: get model
*
* Purpose: access model
*
***************************************************************/
string Car::getModel()
{
	return model;
}
/**************************************************************
* Entry: when input needs to get set to model
*
* Exit: once input set to model
*
* Purpose: set model to input
*
***************************************************************/
void Car::setModel(string mdl)
{
	model = mdl;
}
/**************************************************************
* Entry: need to access year
*
* Exit: get yaer
*
* Purpose: access year
*
***************************************************************/
int Car::getYear()
{
	return year;
}
/**************************************************************
* Entry: need to set input to year
*
* Exit: once input set to year
*
* Purpose: set input to year
*
***************************************************************/
void Car::setYear(int y)
{
	year = y;
}
/**************************************************************
* Entry: when purchase date needs to be accessed
*
* Exit: returns datePurchased
*
* Purpose: get datePurchased
*
***************************************************************/
Date Car::getDatePurchased()
{
	return datePurchased;
}
/**************************************************************
* Entry: when input needs to get set to date purchased
*
* Exit: once input set to datePurchased
*
* Purpose: set input to datePurchased
*
***************************************************************/
void Car::setDatePurchased(Date dP)
{
	datePurchased = dP;
}
/**************************************************************
* Entry: when purchasePrice needs to get accessed
*
* Exit:return purchasePrice
*
* Purpose: return purchasePrice
*
***************************************************************/
double Car::getPurchasePrice()
{
	return purchasePrice;
}
/**************************************************************
* Entry: when input for purchasePrice is done
*
* Exit: input set to purchasePrice
*
* Purpose: set input to purchasePrice
*
***************************************************************/
void Car::setPurchasePrice(double pP)
{
	purchasePrice = pP;
}
/**************************************************************
* Entry: when need to know if car sold or not
*
* Exit: return isSold
*
* Purpose: return isSold
*
***************************************************************/
bool Car::getIsSold()
{
	return isSold;
}
/**************************************************************
* Entry: once isSold input finished
*
* Exit: isSold set to input
*
* Purpose: set input to isSold
*
***************************************************************/
void Car::setIsSold(bool iS)
{
	isSold = iS;
}
/**************************************************************
* Entry: when sale date needs to get accessed
*
* Exit: returns dateSold
*
* Purpose: get dateSold
*
***************************************************************/
Date Car::getDateSold()
{
	return dateSold;
}
/**************************************************************
* Entry: once input finshed
*
* Exit: dateSold set to dS
*
* Purpose: set sale date to dateSold
*
***************************************************************/
void Car::setDateSold(Date dS)
{
	dateSold = dS;
}
/**************************************************************
* Entry: when access for sale price necessary
*
* Exit: return salePrice
*
* Purpose: get salePrice
*
***************************************************************/
double Car::getSalePrice()
{
	return salePrice;
}
/**************************************************************
* Entry: once sale price inputted
*
* Exit: once salePrice set to input
*
* Purpose: give salePrice a value
*
***************************************************************/
void Car::setSalePrice(double sP)
{
	salePrice = sP;
}
/**************************************************************
* Entry: when determining profit
*
* Exit: when profit calculated
*
* Purpose: subtract sales price to purchase price to get total
*
***************************************************************/
double Car::getProfit()
{
	double total = 0;

	if (getIsSold() == true)
	{
		total = getSalePrice() - getPurchasePrice();
	}
	else
	{
		total = isnan(total);
	}
	
	return total;
}
/**************************************************************
* Entry: default constructor
*
* Exit: done constructing
*
* Purpose: act as default constructor
*
***************************************************************/
CarLot::CarLot()
{

}
/**************************************************************
* Entry: destructor
*
* Exit: finished destructing
*
* Purpose: destruct object
*
***************************************************************/
CarLot::~CarLot()
{

}
/**************************************************************
* Entry: at end of addCar function
*
* Exit: pushes car int carlot vector
*
* Purpose: add car into vector
*
***************************************************************/
void CarLot::addCar(Car newC)
{	
	newCar.push_back(newC);
}
/**************************************************************
* Entry: when user wants to see inventory
*
* Exit: shows list of cars
*
* Purpose: display inventory
*
***************************************************************/
void CarLot::listCurrentInv()
{
	int carTotalCounter = 0;

	for (int i = 0; i < newCar.size(); i++)
	{
		if (newCar[i].getIsSold() == false)			// cars that weren't sold
		{
			cout << "Make: " << newCar[i].getMake() << endl;
			cout << "Model: " << newCar[i].getModel() << endl;
			cout << "Year: " << newCar[i].getYear() << endl;
			cout << "Date Purchased: " << newCar[i].getDatePurchased().getYear() << "/" << newCar[i].getDatePurchased().getMonth() << "/" << newCar[i].getDatePurchased().getDay() << endl;
			cout << fixed << showpoint << setprecision(2) << "Purchased Price: $" << newCar[i].getPurchasePrice() << endl;
		}
		else
		{
			carTotalCounter++;		// if there are cars that were sold
			continue;
		}
	}
	cout << "You have " << newCar.size() - carTotalCounter << " car(s) in inventory." << endl << endl;
}
/**************************************************************
* Entry: when user wants to get monthly profits
*
* Exit: when calculation finished
*
* Purpose: get profit of specific month
*
***************************************************************/
double CarLot::getMonthProfit(int year, int month)
{
	double total = 0;

	for (int i = 0; i < newCar.size(); i++)
	{
		if (newCar[i].getDateSold().getMonth() == month && newCar[i].getDateSold().getYear() == year)		// getting cars for specific month and year
		{
			total = total + (newCar[i].getProfit());
		}
		else
		{
			continue;
		}
	}
	cout << fixed << showpoint  << setprecision(2) << "Total profit for: " << year << "/" << month << " is $" << total << endl << endl;

	return total;
}
/**************************************************************
* Entry: when user enters 1 in menu
*
* Exit: users done with input
*
* Purpose: get input for car
*
***************************************************************/
void addCarEntry(Car& newC, Car& newCar2, CarLot& GrantLot)
{
	char soldInput;
	string strInput;
	int numYear = 0, numMonth = 0, numDay = 0;
	double purchaseP = 0, sellP = 0;

	while (strInput != "quit")
	{
		for (int i = arraySize; i < 100; i++)
		{
			cout << "Enter in the cars information. " << endl << endl;
			cout<< "Enter in quit in lower case to exit. " << endl << endl;
			cout << "What is the make of the car? " << endl;
			cin.ignore();
			getline(cin, strInput);

			if (strInput == "quit")
			{
				arraySize = i;
				break;
			}
			newC.setMake(strInput);
			newCar2.setMake(strInput);
			
			cout << "What model is the car? " << endl;
			getline(cin, strInput);

			newC.setModel(strInput);
			newCar2.setModel(strInput);

			cout << "What year is the car? " << endl;
			cin >> numYear;
			newC.setYear(numYear);
			newCar2.setYear(numYear);

			cout << "What month was the car purchased on? " << endl;
			validMonthInput(numMonth);

			cout << "What day was the car purchased on? " << endl;
			validDayInput(numDay, numMonth);

			cout << "What year was the car purchased? " << endl;
			cin >> numYear;

			Date purchaseDate(numYear, numMonth, numDay);

			newC.setDatePurchased(purchaseDate);
			newCar2.setDatePurchased(purchaseDate);

			cout << "How much was the car purchased for? " << endl;
			cin >> purchaseP;

			newC.setPurchasePrice(purchaseP);
			newCar2.setPurchasePrice(purchaseP);

			cout << "Was the car sold? Enter y for yes and n for no. " << endl;
			cin >> soldInput;
			cout << endl;

			if (soldInput == 'y' || soldInput == 'Y')		// to get cars with isSold input only
			{
				newC.setIsSold(true);

				cout << "What year was the car sold? " << endl;
				cin >> numYear;

				cout << "What month was the car sold. " << endl;
				validMonthInput(numMonth);
			
				cout << "What day was the car sold. " << endl;
				validDayInput(numDay, numMonth);

				Date dateOfCar(numYear, numMonth, numDay);

				newC.setDateSold(dateOfCar);

				cout << "How much did the car sell for? " << endl;
				cin >> sellP;
				cout << endl;

				newC.setSalePrice(sellP);

				GrantLot.addCar(newC);			// adds car to lot for isSold is true
			}

			else
			{
				newCar2.setIsSold(false);			// set isSold to false for object that is false
				GrantLot.addCar(newCar2);			// adds car to lot
			}
		}
	}
}
/**************************************************************
* Entry: menu number 2
*
* Exit: prints inventory
*
* Purpose: prints inventory
*
***************************************************************/
void inventoryList(CarLot& GrantLot)
{
	GrantLot.listCurrentInv();
}
/**************************************************************
* Entry: menu 3
*
* Exit: prints profits
*
* Purpose: prints profits
*
***************************************************************/
void profitOfMonth(CarLot& GrantLot)
{
	int month = 0;
	int year = 0;

	while (true)
	{
		cout << "What month did you want? " << endl;
		cin >> month;

		if(month >= 1 && month <= 12)
		{
			break;
		}
		else
		{
			cout << "Invalid input. " << endl;
		}
	}

	cout << "What year did you want? " << endl;
	cin >> year;

	GrantLot.getMonthProfit(year, month);
}
/**************************************************************
* Entry: when day input needs to get checked
*
* Exit: once day is checked
*
* Purpose: see if day input is valid for specific month
*
***************************************************************/
int validDayInput(int& d, int& m)
{
	while (true)
	{
		cout << "Enter in a day from 1 to 31. " << endl;
		cin >> d;

		if (m == 1 && d >= 1 && d <= 31)
		{
			return d;
		}
		if (m == 2 && d >= 1 && d <= 28)
		{
			return d;
		}
		if (m == 3 && d >= 1 && d <= 31)
		{
			return d;
		}
		if (m == 4 && d >= 1 && d <= 30)
		{
			return d;
		}
		if (m == 5 && d >= 1 && d <= 31)
		{
			return d;
		}
		if (m == 6 && d >= 1 && d <= 30)
		{
			return d;
		}
		if (m == 7 && d >= 1 && d <= 31)
		{
			return d;
		}
		if (m == 8 && d >= 1 && d <= 31)
		{
			return d;
		}
		if (m == 9 && d >= 1 && d <= 30)
		{
			return d;
		}
		if (m == 10 && d >= 1 && d <= 31)
		{
			return d;
		}
		if (m == 11 && d >= 1 && d <= 30)
		{
			return d;
		}
		if (m == 12 && d >= 1 && d <= 31)
		{
			return d;
		}
		else
		{
			cout << "Invalid input. " << endl;
		}
	}
}
/**************************************************************
* Entry: month input needs to get check
*
* Exit: valid input passed
*
* Purpose: make sure input between 1 and 12
*
***************************************************************/
int validMonthInput(int& m)
{
	while (true)
	{
		cout << "Enter in a month from 1 to 12. 1 for January and 12 for December " << endl;
		cin >> m;

		if (m >= 1 && m <= 12)
		{
			break;
		}
		else
		{
			cout << "Invalid input. " << endl;
		}
	}

	return m;
}
