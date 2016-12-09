#ifndef COMPANY
#define COMPANY

#include "Shop.h"

class Company
{
public:
	Company(string name = "Unnamed Company") : company_name(name) { }

	string get_name() { return company_name; }
	void add_shop();
	void add_toy();

	friend ifstream &operator>>(ifstream &is, Company &temp);
	friend ostream &operator<<(ostream &os, Company &temp);

private:
	string company_name;
	Vector <Shop> shops;
};

#endif // COMPANY
