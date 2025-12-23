#include <iostream>
#include <string>
#include "Drinkitem.h"

using namespace std;


Drinkitem::Drinkitem(){
	setItemID(0);
	setItemName("Drink");
	setItemPrice(0);
	setItemType('D');
}

Drinkitem::Drinkitem(int newItemId, string newItemName,  double newItemPrice, char newItemType){
	setItemID(newItemId);
	setItemName(newItemName);
	setItemPrice(newItemPrice);
	setItemType(newItemType);
}

Drinkitem::~Drinkitem() {}

void Drinkitem::showItem() {
	cout << "Item ID: " << getItemID() << "Item name: " << getItemName()<< "Item price: " << getItemPrice() << endl;
}
double Drinkitem::calculateDiscount() {
	return (getItemPrice() - (getItemPrice() * 0.05) );
}