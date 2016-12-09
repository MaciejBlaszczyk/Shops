#ifndef TOY
#define TOY

#include "iterator.h"

class Toy
{
public:
	Toy(string toy_name = "Unnamed Toy", double toy_price = 0) : toy_name(toy_name), toy_price(toy_price) { }

	friend ostream &operator<<(ostream &os, Toy &temp) { cout<<"Toy: "<<temp.toy_name<<"  Price: "<<temp.toy_price<<endl; return os; }
private:
	string toy_name;
	double toy_price;
};

#endif // TOY
