/****************************************************************
* Author: Grant Nakashima
* Date Created: 11/26/14
* Last Modification Date: 11/30/14
* Filename: shopCart2.cpp
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
#include <vector>                     // used for vectors

using namespace std;

class Item
{
private:
	string name;		// members of item class
	double price;
	int quantity;
public:
	Item();
	~Item();
	Item(string n, double p, int q);	// constructors
	string getName();
	void setName(string n);
	double getPrice();
	void setPrice(double p);
	int getQuantity();
	void setQuantity(int q);
};

class ShoppingCart
{
private: 
	vector < Item > itemList;			// items pushed into vector

public:

	ShoppingCart();
	~ShoppingCart();

	void addItem(Item& product);		// add items into vector
	void listItems();		// print items in vector
	void totalPrice();		// prints total of items
	
};

void addItem(Item&, ShoppingCart& shoppingCart);		// function in main for menu input 1
void showList(ShoppingCart& shoppingCart);				// function in main for menu input 2
void showPrice(ShoppingCart& shoppingCart);				// function in main for menu input 3
int arraySize = 0;
double dPrice;
int iQuantity;

int main()
{
	ShoppingCart shoppingCart;			// shopping cart object to get passed to functions
	string itemName;					// used for item object
	Item item(itemName, dPrice, iQuantity);		// item object to get passed to function

	int menuPick = 0;         // initialize menuPick

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
			addItem(item, shoppingCart);                         // function to organize item input
			break;
		case 2:
			showList(shoppingCart);                                                              // to see shopping cart
			break;
		case 3:
			showPrice(shoppingCart);                                             // to see total
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

Item::Item()			// default constructor
{

}

Item::~Item()			// default destructor
{

}

Item::Item(string n, double p, int q)		// constructor for item
{
	name = n;
	price = p;
	quantity = q;
}

string Item::getName()						// gets item name
{
	return name;
}

double Item::getPrice()						// gets price of item
{
	return price;
}

int Item::getQuantity()					// gets quanitity of item
{
	return quantity;
}

void Item::setName(string n)			// sets name of item
{
	name = n;
}

void Item::setPrice(double p)			// sets price of item input
{
	if (p >= 0)							// free allowed
	{
		price = p;
	}
	else
	{
		cout << "Invalid input. " << endl;			// for negative prices
	}
}

void Item::setQuantity(int q)			// set quantity
{
	if (q >= 0)				// no items ok
	{
		quantity = q;
	}
	else
	{
		cout << "Invalid input. " << endl;			// for negative items
	}
}

ShoppingCart::ShoppingCart()				// default constructor
{

}

ShoppingCart::~ShoppingCart()				// destructor
{

}

void ShoppingCart::addItem(Item& product)		// pushes item into the shopping cart
{
	itemList.push_back(product);
}

void ShoppingCart::listItems()		// prints items in shopping cart
{
	for (int i = 0; i < itemList.size(); i++)
	{
		cout << "Product Name: " << itemList[i].getName() << endl;
		cout << fixed << showpoint << setprecision(2) <<"Price: $" << itemList[i].getPrice() << endl;
		cout << "Quantity: " << itemList[i].getQuantity() << endl << endl;
	}
}

void ShoppingCart::totalPrice()			// gives total price of items
{
	double total = 0;

	for (int i = 0; i < itemList.size(); i++)
	{
		total = total + (itemList[i].getPrice() * itemList[i].getQuantity());
	}
	cout << "Your total is: ";
	cout << fixed << showpoint << setprecision(2) << "$" << total << endl << endl;

}
/**************************************************************
* Entry: main in switch input 1
*
* Exit: user inputs quit to exit
*
* Purpose: get item input
*
***************************************************************/
void addItem(Item& item, ShoppingCart& shoppingCart)
{
	string itemName;
	double dPrice;
	int iQuantity;

	while (itemName != "quit")			// allows user to quit 
	{
		for (int i = arraySize; i < 100; i++)
		{
			cout << "Enter in quit in lower case to exit. " << endl << endl;
			cout << "Please enter in the name of the item. " << endl;
			cin.ignore();
			getline(cin, itemName);				// get items with spaces 
			
			if (itemName == "quit")
			{
				arraySize = i;			// allow to add more items later
				break;
			}
			item.setName(itemName);

			cout << "Please enter in the price of the item. " << endl;
			cin >> dPrice;
			item.setPrice(dPrice);
				
			cout << "Please enter in the quantity of the item. " << endl;
			cin >> iQuantity;
			item.setQuantity(iQuantity);

			shoppingCart.addItem(item);		//puts item into shoppingcart
		}
	}
}
/**************************************************************
* Entry: menu in switch number 2
*
* Exit: prints item list
*
* Purpose: print shopping cart
*
***************************************************************/
void showList(ShoppingCart& shoppingCart)			
{
	shoppingCart.listItems();
}
/**************************************************************
* Entry: main switch number 3
*
* Exit: calculates total price
*
* Purpose: get total price
*
***************************************************************/
void showPrice(ShoppingCart& shoppingCart)
{
	shoppingCart.totalPrice();
}
