#include "Company.h"
#include<sstream> //for str()
#include<conio.h>  //for getch()

string to_string(int value) { ostringstream os; os<<value; return os.str(); } //int to string function

extern Vector <Company> company_list;

ifstream &operator>>(ifstream &is, Company &temp)
{
	string name, address;
	int number;

	is>>name>>address>>number;
	temp.company_name = name;
	address += " " + to_string(number);

	temp.shops.push_last(Shop(address));

    Iterator<Company, Vector<Company>> it = company_list.Begin();
	for(; (*it).get_name() != temp.get_name() && it != company_list.End(); it++);
	if(it == company_list.End())
		company_list.push_last(temp);
	else
		(*it).shops.push_last(temp.shops[0]);

	return is;
}

ostream &operator<<(ostream &os, Company &temp)
{
	cout<<"Company Name: "<<temp.company_name<<endl;

	for(Iterator <Shop, Vector<Shop>> it = temp.shops.Begin(); it != temp.shops.End(); it++)
		os<<(*it);

	return os;
}

void Company::add_shop()
{
	 string shop_address;
	 int number;
	 cout<<"Enter shop address: ";
	 cin>>shop_address>>number;

	 shops.push_last(Shop(shop_address + " " + to_string(number)));
}

void Company::add_toy()
{
	string shop_name;
	int number;
	cout<<"To what shop do you want to add a toy?"<<endl;
	cin>>shop_name>>number;
	shop_name += " " + to_string(number);

	Iterator<Shop, Vector<Shop>> it = shops.Begin();
	for(; (*it).get_name() != shop_name && it != shops.End(); it++)
		cout<<shop_name<<" compare "<<(*it).get_name()<<endl;
	if(it == shops.End())
	{
		cout<<"Wrong shop's name"<<endl;
		cout<<"Press any key to continue..."<<endl;
		getch();
		return;
	}

	(*it).add_toy();
}
