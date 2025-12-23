#pragma once
#include <iostream>
#include <string>
#include "Menuitem.h"
using namespace std;

class Drinkitem : public Menuitem {
public:
	Drinkitem();
	Drinkitem(int newItemId, string newItemName,  double newItemPrice, char newItemType);
	~Drinkitem();
	void showItem()override;
	double calculateDiscount()override;

private:

};

