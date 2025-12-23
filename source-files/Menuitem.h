#pragma once
#include <iostream>
#include <string>
using namespace std;

class Menuitem{
protected:
	int itemID;
	string itemName;
	double itemPrice;
	char itemType;


public:

	virtual void showItem() = 0;
	virtual double calculateDiscount() = 0;

	Menuitem();
	virtual ~Menuitem();

	string getItemName();
	int getItemID();
	double getItemPrice();
	char getItemType();

	void setItemName(const string& newItemName);
	void setItemID(const int& newItemId);
	void setItemPrice(const double& newItemPrice);
	void setItemType(const char& newItemType);
};
