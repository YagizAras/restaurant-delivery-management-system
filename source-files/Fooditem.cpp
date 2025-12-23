#include <iostream>
#include <string>
#include "Fooditem.h"

using namespace std;



Fooditem::Fooditem(){
	setItemID(0);
	setItemName("food");
	setItemPrice(0);
	setItemType('F');
}

Fooditem::Fooditem(string newItemName, int newItemId, double newItemPrice, char newItemType) {
	setItemID(newItemId);
	setItemName(newItemName);
	setItemPrice(newItemPrice);
	setItemType(newItemType);
}

Fooditem::~Fooditem(){}


void Fooditem::showItem(){
	cout << "Item ID: " << getItemID() << "Item name: " << getItemName() << "Item price: " << getItemPrice() << endl;
}
double Fooditem::calculateDiscount() {
	return getItemPrice() - (getItemPrice() * 0.15);
}


