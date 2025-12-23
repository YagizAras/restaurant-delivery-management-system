#pragma once
#include <iostream>
#include <string>
#include "Menuitem.h"
//Burada Menu item icerisindeki fonksiyonlarý setliyoruz.
//Deðiþkenlere direkt ulasamadigimiz icin degiskenleri get ve set ile manipule ediyoruz.

Menuitem::Menuitem() {}

Menuitem::~Menuitem(){}


void Menuitem::setItemName(const string& newItemName) {
	itemName = newItemName;
}
void Menuitem::setItemID(const int& newItemId) {
	itemID = newItemId;
}
void Menuitem::setItemPrice(const double& newItemPrice) {
	itemPrice = newItemPrice;
}
void Menuitem::setItemType(const char& newItemType) {
	itemType = newItemType;
}
string Menuitem::getItemName(){
	return itemName;
}
int Menuitem::getItemID(){
	return itemID;
}
double Menuitem::getItemPrice() {
	return itemPrice;
}
char Menuitem::getItemType() {
	return itemType;
}
