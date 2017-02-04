#ifndef SHOP
#define SHOP

#include "Toy.h"

class Shop
{
public:
	Shop(string name = "Unnamed Shop") : shopAddress(name) { }

	string getName() { return shopAddress; }
	void addToy();

	friend ostream &operator<<(ostream &os, Shop &temp);
private:
	string shopAddress;
	Vector <Toy> toys;
};

#endif
