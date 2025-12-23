#pragma once
#include <iostream>
#include <string>
#include "Menuitem.h"
using namespace std;

class Fooditem: public Menuitem {
public:
	Fooditem();
	Fooditem(string newItemName, int newItemId, double newItemPrice, char newItemType);
	~Fooditem();
	void showItem()override;
	double calculateDiscount()override;

private:
	
};

