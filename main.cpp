#include "Company.h"
#include<windows.h>
#include<conio.h>

Vector <Company> companyList;

void addCompany();
void showEverything();
void addShop();
void addToy();

int main()
{
	while(1)
	{
		int numb;
		system("cls");
		cout<<"Welcome to Toy Shop !\n\n"
			<<"If you want to add a company, press 2\n"
			<<"If you want to add a shop, press 3\n"
			<<"If you want to add a toy, press 4\n"
			<<"If you want to show companies, shops, toys and prices, press 5\n"
			<<"If you want to exit, press 6\n";

		cin>>numb;
		switch(numb)
		{
			case 2 : addCompany();
			break;
			case 3 : addShop();
			break;
			case 4 : addToy();
			break;
			case 5 : showEverything();
			break;
			case 6 : return 1;

			default : cout<<"Enter other number"<<endl;
			break;
		}
	}
	return 0;
}

void addCompany()
{
	string companyName;
	cout<<"Enter company's name: ";
	cin>>companyName;
	companyList.pushBack(Company(companyName));

	cout<<"Press any key to continue..."<<endl;
	getch();
}

void showEverything()
{
	for(Iterator <Company, Vector<Company>> it = companyList.Begin(); it != companyList.End(); it++)
		cout<<(*it)<<endl;

	cout<<endl<<"Press any key to continue..."<<endl;
	getch();
}

void addShop()
{
	string companyName, shopName;
	cout<<"To what company do you want to add a shop?"<<endl;
	cin>>companyName;

	Iterator<Company, Vector<Company>> it = companyList.Begin();
	for(; (*it).getName() != companyName && it != companyList.End(); it++);
	if(it == companyList.End())
	{
		cout<<"Wrong company's name"<<endl;
		cout<<"Press any key to continue..."<<endl;
		getch();
		return;
	}

	(*it).addShop();

	cout<<"Press any key to continue..."<<endl;
	getch();
}

void addToy()
{
	string companyName;
	cout<<"To what company do you want to add a toy?"<<endl;
	cin>>companyName;

	Iterator<Company, Vector<Company>> it = companyList.Begin();
	for(; (*it).getName() != companyName && it != companyList.End(); it++);
	if(it == companyList.End())
	{
		cout<<"Wrong company's name"<<endl;
		cout<<"Press any key to continue..."<<endl;
		getch();
		return;
	}

	(*it).addToy();

	cout<<"Press any key to continue..."<<endl;
	getch();
}

