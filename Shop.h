#ifndef SHOP
#define SHOP

#include "Toy.h"

class Shop
{
public:
	Shop(string name = "Unnamed Shop") : shop_address(name) { }

	string get_name() { return shop_address; }
	void add_toy();

	friend ostream &operator<<(ostream &os, Shop &temp);
private:
	string shop_address;
	Vector <Toy> toys;
};

#endif
