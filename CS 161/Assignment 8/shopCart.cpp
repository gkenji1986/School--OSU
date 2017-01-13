/****************************************************************
* Author: Grant Nakashima
* Date Created: 11/17/14
* Last Modification Date: 11/19/14
* Filename: shopCart.cpp
*
* Overview:
* This program acts like a shopping cart. The user will choose an option of their
* choice and decide whether they want to  add items to their cart, look at what they
* have inputted and the total. When the user wants to quit, they can pick that in the
* menu to exit. The program uses a struct to get multiple information for the user
* on the item.
*
* Input:
* The user will input the items name, price and quantity they want. The other input
* the user does is picking which menu option they want to do.
*
* Example input file contents:
* 1, Apple juice, 4.99, 2
*
*Output: The program will ask the user the name of the product, price, quantity
* and which menu option they would like. The second menu option will display
* what they have currently input. The total option will total out their input.
*
*Output example: Enter the item name: , Enter the price :, Enter the quantity: ,
* Your total is :.
****************************************************************/

#include <iostream>                 // used for cin and cout 
#include <string>                      // used for strings
#include <iomanip>                 
#include <stdio.h>                    // used for atof
#include <algorithm>                // used for atoi 
#include <vector>                     // used for vectors

using namespace std;

struct Item                                // this stuct uses 3 variables
{
	string name;
	double price;
	int quantity;
};

vector <Item> add;
void ItemArray(Item shoppingCart[], int&);   // function to add items to shopping cart
void ShoppingCart(Item shoppingCart[], int&);         // function to display shopping cart
void Total(Item shoppingCart[], int&);                      // shows total for shopping cart
bool ValidPrice(string&, double&);                   // checks if price input is valid
bool ValidQuantity(string&, int&);                     // checks if quantity is a valid input

int main()
{
	int menuPick = 0;                                              // initialize menuPick
	Item shoppingCart[100];                                           // set max at 100
	int a = 0;                                                           // used for iDigit
	while (true)
	{
		cout << "Menu";
		cout << "\n1 Add item";
		cout << "\n2 See shopping cart ";
		cout << "\n3 Total Price ";
		cout << "\n4 Quit " << endl << endl;
		cout << "Please pick an option. " << endl << endl;
		cin >> menuPick;
		cout << endl;

		switch (menuPick)
		{
		case 1:
			ItemArray(shoppingCart, a);                         // Array to input items
			break;
		case 2:
			ShoppingCart(shoppingCart, a);                                // to see shopping cart
			break;
		case 3:
			Total(shoppingCart, a);                                             // to see total
			break;
		case 4:
			cout << "Thank you for shopping with us. " << endl << endl;
			return 0;
		default:
			cout << "Invalid option. Please input a number from 1 to 4. " << endl;
			break;
		}
	}

	return 0;
}

/**************************************************************
* Entry: from main when user inputs 1
*
* Exit: when user inputs quit
*
* Purpose: add items to the array
*
***************************************************************/
void ItemArray(Item shoppingCart[], int& a)
{
	string strPrice, strQuantity;                                // used to see if valid input
	double dDigit = 0;
	int iDigit = 0;
	int iCount = 0;

	for (int i = a; i < 100; i++)
	{
		cout << "If you would like to exit please enter: quit. " << endl << endl;
		cout << "Enter in the item name. " << endl;
	
		cin.ignore();
		getline(cin, shoppingCart[i].name);                                    // input name in struct
		
		if (shoppingCart[i].name == "quit")                // user can quit if they input quit
		{
			cout << "Printing item list...." << endl;   
			a = i;										// keeping track of the string length. for additional items
			break;
		}
		else
		{
			ValidPrice(strPrice, dDigit);                              // checks for valid price input
			shoppingCart[i].price = dDigit;                                  // sets checked input to struct's price

			ValidQuantity(strQuantity, iDigit);                      // checks for valid quantity input
			shoppingCart[i].quantity = iDigit;        // sets checked input to quantity
		}
	}
}

/**************************************************************
* Entry: gets array from shopping cart and executed when user
*			inputs 2 in menu screen
*
* Exit: once it prints the items
*
* Purpose: To print the items in array
*
***************************************************************/
void ShoppingCart(Item shoppingCart[], int& a)
{
	for (int i = 0; i < a; i++)             // loops so it can print out array
	{
		cout << "Item Name: " << shoppingCart[i].name << endl;
		cout << "Item cost: " << fixed << showpoint << setprecision(2) << "$" << shoppingCart[i].price << endl;
		cout << "Quantity: " << shoppingCart[i].quantity << endl << endl;
	}
}

/**************************************************************
* Entry: gets array and array length. enters from menu when user
*		 inputs 3
*
* Exit: once it prints the total
*
* Purpose: print the total amount in shopping cart
*
***************************************************************/
void Total(Item shoppingCart[], int& a)
{
	double total = 0;

	for (int i = 0; i < a; i++)             // loops for array size
	{
		total = total + (shoppingCart[i].price * shoppingCart[i].quantity);
	}
	cout << "Your total is: ";
	cout << fixed << showpoint << setprecision(2) << "$" << total << endl << endl;
}

/**************************************************************
* Entry: gets the input from the user in AddCarInfo
*
* Exit: once they input a valid input
*
* Purpose: To check if the price input is valid.
*
***************************************************************/
bool ValidPrice(string& strPrice, double& dDigit)
{
	int decimalCounter = 0;             //  checks to see if more than one . was added

	while (true)
	{
		cout << "Enter in the item price. " << endl;
		cin >> strPrice;

		for (int i = 0; i < strPrice.length(); i++)
		{
			if (isdigit(strPrice[i]) || strPrice[i] == '.')  // checks if it is only digits and a .
			{
				if (strPrice[i] == '.')                               // if a . is present it adds to decimal counter
				{
					decimalCounter++;
				}
				else if (decimalCounter > 1)                  // lets it know if it is invalid or not
				{
					cout << "Invalid input. " << endl;
					decimalCounter = 0;
					break;
				}
			}
			else
			{
				cout << "Invalid input. " << endl;
				decimalCounter = 0;
				break;
			}
		}
		if (decimalCounter == 1)
		{
			dDigit = atof(strPrice.c_str());   // converts string to float then sets float to double
			decimalCounter = 0;
			return true;
		}
	}
}
/**************************************************************
* Entry: gets the input from the user in AddCarInfo
*
* Exit: once they input a valid input
*
* Purpose: To check if the quantity input is valid
*
***************************************************************/
bool ValidQuantity(string& strQuantity, int& iDigit)
{
	int i;
	iDigit = 0;

	while (true)
	{
		cout << "Enter in the item quantity. " << endl;
		cin >> strQuantity;

		for (i = 0; i < strQuantity.length(); i++)
		{
			if (!isdigit(strQuantity[i]))                       // checks if it has letters
			{
				break;
			}
		}
		if (strQuantity.length() == i)
		{
			iDigit = atoi(strQuantity.c_str());                                    // changes string to int
			return true;
		}
		else
		{
			cout << "Invalid input. " << endl;
		}
	}
}
