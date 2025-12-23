#include <iostream>
#include <string>
#include "Restaurant.h"
#include <fstream>
using namespace std;


Restaurant::Restaurant() {
	menuSize = 5;
	currentMenuSize = 0;
	restaurantMenu = new Menuitem* [menuSize];
	//segmentasyon fault hatasý aldýk o sebeple basta tum listeyi nullptr yaptik

	for (int i = 0; i < menuSize; i++) {
		restaurantMenu[i] = nullptr;
	}
}

//sinifin kendi listesi kullanilacak
void Restaurant::createRestaurantMenu(string link) {
	int newItemId;
	char newItemtype;
	string newItemName;
	double newItemPrice;

	ifstream reFile;
	reFile.open(link);
	
	if (!reFile.is_open()) {
		cout << "Dosya acilamadi!!!" << endl;
		return;
	}
	//listedeki yemek kadar yer açýlýp yemekler liste içinde ekleniyor.
	while (reFile >> newItemId >> newItemtype >> newItemPrice)
	{
		getline(reFile >> ws, newItemName);
		
		if (newItemtype == 'F') {
			this->addFoodItem(newItemName, newItemId, newItemPrice, newItemtype);
		}
		else if (newItemtype == 'D')
		{
			this->addDrinkItem(newItemName, newItemId, newItemPrice, newItemtype);
		}
		
	}
	
	reFile.close();

}

void Restaurant::showMenu() {
	cout << "Restorantin Menusu: " << endl; 
	for (int i = 0; i < currentMenuSize; i++)
	{
		cout<< restaurantMenu[i]->getItemID() << " "
			<< restaurantMenu[i]->getItemName() << " "
			<< restaurantMenu[i]->getItemPrice() << " "
			<< endl;
	}
}
void Restaurant::addFoodItem(string newItemName, int newItemId, double newItemPrice, char newItemtype) {
	if (currentMenuSize >= menuSize)
	{
		menuSize = menuSize * 2;
		Menuitem** tempMenu = new Menuitem*[menuSize];
		for (size_t i = 0; i < currentMenuSize; i++)
		{
			tempMenu[i] = restaurantMenu[i];
		}

		for (size_t i = currentMenuSize; i < menuSize; i++)
		{
			tempMenu[i] = nullptr;
		}

		delete[] restaurantMenu;
		restaurantMenu = tempMenu;
		tempMenu = nullptr;
	}

	if (currentMenuSize < menuSize) {
		restaurantMenu[currentMenuSize] = new Fooditem(newItemName, newItemId, newItemPrice, newItemtype);
		currentMenuSize++;
	}
}

void Restaurant::addDrinkItem(string newItemName, int newItemId, double newItemPrice, char newItemtype) {
	if (currentMenuSize >= menuSize)
	{
		menuSize = menuSize * 2;
		Menuitem** tempMenu = new Menuitem * [menuSize];
		
		for (size_t i = 0; i < currentMenuSize; i++)
		{
			tempMenu[i] = restaurantMenu[i];
		}
		
		for (size_t i = currentMenuSize ; i < menuSize; i++)
		{
			tempMenu[i] = nullptr;
		}
		delete[] restaurantMenu;
		restaurantMenu = tempMenu;
		tempMenu = nullptr;

	}
	if (currentMenuSize < menuSize)
	{
		restaurantMenu[currentMenuSize] = new Drinkitem(newItemId, newItemName, newItemPrice, newItemtype);
		currentMenuSize++;
	}
}

void Restaurant::removeItem(int newItemId) {
	for (size_t i = 0; i < currentMenuSize; i++)
	{
		if (restaurantMenu[i]->getItemID() == newItemId) {
			cout << restaurantMenu[i]->getItemID() << " "
				<< restaurantMenu[i]->getItemType() << " "
				<< restaurantMenu[i]->getItemPrice() << " "
				<< restaurantMenu[i]->getItemName()
				<<" --> Elemani restourant menusundan silinmistir! " << endl;


			delete restaurantMenu[i];
			for (int j = i; j < currentMenuSize - 1; j++){
				//kaydýrdým
				restaurantMenu[j] = restaurantMenu[j + 1];
			}
				//son elemaný bosalttým
				restaurantMenu[currentMenuSize - 1] = nullptr;
				currentMenuSize--;
				return;
		}
	}
	cout << "Silmek istediginiz eleman restaurant menusunde bulunmamaktadýr! ";
}

void Restaurant::applyToTxt(string link) {
	ofstream wrFile;
	wrFile.open(link);

	for (size_t i = 0; i < currentMenuSize; i++)
	{
		wrFile << restaurantMenu[i]->getItemID() << " "
			<< restaurantMenu[i]->getItemType() << " "
			<< restaurantMenu[i]->getItemPrice() << " "
			<< restaurantMenu[i]->getItemName()
			<< endl;
	}

	wrFile.close();
}

Restaurant::~Restaurant(){
	// pointer ile tutulan nesneler silinir
	for (int i = 0; i < currentMenuSize; i++) {
		if (restaurantMenu[i] != nullptr) {
			delete restaurantMenu[i];
		}
	}
	delete[] restaurantMenu;
}

Menuitem** Restaurant::getMenu() {
	return restaurantMenu;
}

int Restaurant::getCurrentSize() {
	return currentMenuSize;
}