#include "Company.h"
#include<sstream> //for str()
#include<conio.h>  //for getch()

string to_string(int value) { ostringstream os; os<<value; return os.str(); } //int to string function

extern Vector <Company> companyList;

ostream &operator<<(ostream &os, Company &temp)
{
	cout<<"Company Name: "<<temp.companyName<<endl;

	for(Iterator <Shop, Vector<Shop>> it = temp.shops.Begin(); it != temp.shops.End(); it++)
		os<<(*it);

	return os;
}

void Company:: addShop()
{
	 string shopAddress;
	 int number;
	 cout<<"Enter shop address: ";
	 cin>>shopAddress>>number;

	 shops.pushBack(Shop(shopAddress + " " + to_string(number)));
}

void Company:: addToy()
{
	string shopName;
	int number;
	cout<<"To what shop do you want to add a toy?"<<endl;
	cin>>shopName>>number;
	shopName += " " + to_string(number);

	Iterator<Shop, Vector<Shop>> it = shops.Begin();
	for(; (*it).getName() != shopName && it != shops.End(); it++)
		cout<<shopName<<" compare "<<(*it).getName()<<endl;
	if(it == shops.End())
	{
		cout<<"Wrong shop's name"<<endl;
		cout<<"Press any key to continue..."<<endl;
		getch();
		return;
	}

	(*it).addToy();
}
