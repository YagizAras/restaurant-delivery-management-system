#pragma once
#include <iostream>
#include <string>
using namespace std;
//Menuitem sanal sinifini burada tanimliyoruz.


class Menuitem{
protected:
	int itemID;
	string name;
	double price;
public:
	//sinif'i sanal sinif yapmak icin oluþturulan virtual method
	virtual ~Menuitem() = 0;
	void setName(const string& nam);
	void setItemID(const int& id);
	void setPrice(const double& prc);
	string getName();
	int getID();
	
};
