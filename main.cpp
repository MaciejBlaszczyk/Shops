#include "Company.h"
#include<windows.h>
#include<conio.h>

Vector <Company> companyList;

void addCompany();
void addShop();
void addToy();
void showEverything();
void deleteCompany();
void deleteShop();
void deleteToy();

int main()
{
	while(1)
	{
		int numb;
		system("cls");
		cout<<"Welcome to Toy Shop !\n\n"
			<<"If you want to add a company, press 1\n"
			<<"If you want to add a shop, press 2\n"
			<<"If you want to add a toy, press 3\n"
			<<"If you want to delete a company, press 4\n"
			<<"If you want to delete a shop, press 5\n"
			<<"If you want to delete a toy, press 6\n"
			<<"If you want to show companies, shops, toys and prices, press 7\n"
			<<"If you want to exit, press 8\n";

		cin>>numb;
		switch(numb)
		{
			case 1 : addCompany();
			break;
			case 2 : addShop();
			break;
			case 3 : addToy();
			break;
			case 4 : deleteCompany();
			break;
			case 5 : deleteShop();
			break;
			case 6 : deleteToy();
			break;
			case 7 : showEverything();
			break;
			case 8 : return 1;

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

