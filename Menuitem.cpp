#pragma once
#include <iostream>
#include <string>
#include "Menuitem.h"
//Burada Menu item icerisindeki fonksiyonlarý setliyoruz.
//Deðiþkenlere direkt ulasamadigimiz icin degiskenleri get ve set ile manipule ediyoruz.

void Menuitem::setName(const string& nam) {
	name = nam;
}
void Menuitem::setItemID(const int& id) {
	itemID = id;
}
void Menuitem::setPrice(const double& prc) {
	price = prc;
}
string Menuitem::getName(){
	return name;
}
int Menuitem::getID(){
	return itemID;
}
