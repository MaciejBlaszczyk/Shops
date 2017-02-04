#ifndef COMPANY
#define COMPANY

#include "Shop.h"

class Company
{
public:
	Company(string name = "Unnamed Company") : companyName(name) { }

	string getName() { return companyName; }
	void addShop();
	void addToy();

	friend ostream &operator<<(ostream &os, Company &temp);

private:
	string companyName;
	Vector <Shop> shops;
};

#endif // COMPANY
