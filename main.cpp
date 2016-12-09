#include "Company.h"
#include<windows.h> //for system("cls")
#include<conio.h> //for getch()

Vector <Company> company_list;

void read_shops_from_file();
void add_company();
void show_everything();
void add_shop();
void add_toy();

int main()
{
	while(1)
	{
		try
		{
			int numb;
			system("cls");
			cout<<"Welcome to Toy Shop !\n\n"
				<<"If you want to read Companies and their shops from file , press 1\n"
				<<"If you want to add a company, press 2\n"
				<<"If you want to add a shop, press 3\n"
				<<"If you want to add a toy, press 4\n"
				<<"If you want to show companies, shops, toys and prices, press 5\n"
				<<"If you want to exit, press 6\n";

			cin>>numb;
			switch(numb)
			{
				case 1 : read_shops_from_file();
				break;
                case 2 : add_company();
				break;
				case 3 : add_shop();
				break;
				case 4 : add_toy();
				break;
				case 5 : show_everything();
				break;
				case 6 : return 1;

				default : cout<<"Enter other number"<<endl;
				break;
			}
		}
		catch (const out_of_range& oor)
		{
			cerr<<"Out of Range error: "<<oor.what()<<endl;
		}
	}
	return 0;
}

void read_shops_from_file()
{
	ifstream file;
	string name = "dane.txt" ;
	file.open(name.c_str());

	if(!file.is_open())
	cout<<"Bad file reading"<<endl;

	while(file.good())
	{
		Company temp;
		file>>temp;
	}

	cout<<"Press any key to continue..."<<endl;
	getch();
}

void add_company()
{
	string company_name;
	cout<<"Enter company's name: ";
	cin>>company_name;
	company_list.push_last(Company(company_name));

	cout<<"Press any key to continue..."<<endl;
	getch();
}

void show_everything()
{
	for(Iterator <Company, Vector<Company>> it = company_list.Begin(); it != company_list.End(); it++)
		cout<<(*it)<<endl;

	cout<<endl<<"Press any key to continue..."<<endl;
	getch();
}

void add_shop()
{
	string company_name, shop_name;
	cout<<"To what company do you want to add a shop?"<<endl;
	cin>>company_name;

	Iterator<Company, Vector<Company>> it = company_list.Begin();
	for(; (*it).get_name() != company_name && it != company_list.End(); it++);
	if(it == company_list.End())
	{
		cout<<"Wrong company's name"<<endl;
		cout<<"Press any key to continue..."<<endl;
		getch();
		return;
	}

	(*it).add_shop();

	cout<<"Press any key to continue..."<<endl;
	getch();
}

void add_toy()
{
	string company_name;
	cout<<"To what company do you want to add a toy?"<<endl;
	cin>>company_name;

	Iterator<Company, Vector<Company>> it = company_list.Begin();
	for(; (*it).get_name() != company_name && it != company_list.End(); it++);
	if(it == company_list.End())
	{
		cout<<"Wrong company's name"<<endl;
		cout<<"Press any key to continue..."<<endl;
		getch();
		return;
	}

	(*it).add_toy();

	cout<<"Press any key to continue..."<<endl;
	getch();
}

