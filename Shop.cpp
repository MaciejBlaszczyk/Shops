#include "Shop.h"

ostream &operator<<(ostream &os, Shop &temp)
{
	cout<<"Shop Address: "<<temp.shopAddress<<endl;

	for(Iterator <Toy, Vector<Toy>> it = temp.toys.Begin(); it != temp.toys.End(); it++)
		os<<(*it);

	return os;
}

void Shop:: addToy()
{
	string toyName;
	double toyPrice;
	cout<<"Enter toy name: ";
	cin>>toyName;
	cout<<"Enter toy price: ";
	cin>>toyPrice;

	toys.pushBack(Toy(toyName, toyPrice));
}
