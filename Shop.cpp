#include "Shop.h"

ostream &operator<<(ostream &os, Shop &temp)
{
	cout<<"Shop Address: "<<temp.shop_address<<endl;

	for(Iterator <Toy, Vector<Toy>> it = temp.toys.Begin(); it != temp.toys.End(); it++)
		os<<(*it);

	return os;
}

void Shop::add_toy()
{
	string toy_name;
	double toy_price;
	cout<<"Enter toy name: ";
	cin>>toy_name;
	cout<<"Enter toy price: ";
	cin>>toy_price;

	toys.push_last(Toy(toy_name, toy_price));
}
