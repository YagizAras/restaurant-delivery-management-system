#pragma once

#include <iostream>
#include <string>
#include "MenuItem.h"
#include "Fooditem.h"
#include "Drinkitem.h"
#include "Employee.h"

class Restaurant {
public:
	Restaurant();
	~Restaurant();
	//sinifin kendi listesi kullanilacak
	void createRestaurantMenu(string link);
	void showMenu();
	void addFoodItem(string newItemName, int newItemId, double newItemPrice, char newItemtype);
	void addDrinkItem(string newItemName, int newItemId, double newItemPrice, char newItemtype);
	void removeItem(int newItemId);
	void applyToTxt(string link);
	
	int getCurrentSize(); 
	Menuitem** getMenu();

private:
	string restaurantName;
	int restautantID;
	int menuSize, currentMenuSize;
	Menuitem** restaurantMenu;


};