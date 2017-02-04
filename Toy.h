#ifndef TOY
#define TOY

#include "iterator.h"

class Toy
{
public:
	Toy(string toyName = "Unnamed Toy", double toyPrice = 0) : toyName(toyName), toyPrice(toyPrice) { }

	friend ostream &operator<<(ostream &os, Toy &temp) { cout<<"Toy: "<<temp.toyName<<"  Price: "<<temp.toyPrice<<endl; return os; }

private:
	string toyName;
	double toyPrice;
};

#endif // TOY
