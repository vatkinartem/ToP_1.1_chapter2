#include <iostream>
#include <stdio.h>
#include "Keeper.h"
#include <string>
#include <vector>
#include <exception>

using namespace std;
using namespace myvec;

enum COM
{
	DEFAULT,
	LOAD,
	SAVE,
	INPUT,
	EXIT
};

static istream& operator>>(istream& is, COM& i)
{
	int temp;
	if (is >> temp)
		i = static_cast<COM>(temp);
	return is;
}


int main()
{
	using namespace std;
	using namespace myvec;
	using namespace keep;


	COM cmnd;
	int cmnd_int;

	Keeper base;


	try
	{
		cout << "Begin" << endl;
		base.addEntry("Student fio group profession 1 0.0 \n");
		cout << "\nStudent is done\n" << endl;
		base.addEntry("Professor fio (group1 group2 group3) (sub1 sub2 sub3) \n");
		cout << "\nProfessor is done\n" << endl;
		base.addEntry("AdminStaff fio post phone areaOfResponse \n");
		cout << "\nAdminStaff is done\n" << endl;
		base.print();
		base.saveToFile();
		base.loadFromFile();
		base.saveToFile();
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	do
	{
		try
		{
			cmnd = COM::DEFAULT;
			cout << "Awaiting command..." << endl;
			cin >> cmnd_int;
			if (cin.fail())
			{
				throw(exception("Non numeric character found"));
			}
			if (((COM)cmnd_int < COM::DEFAULT) || ((COM)cmnd_int > COM::EXIT))
			{
				throw(exception("Wrong command"));
			}
			cmnd = (COM)cmnd_int;

			switch (cmnd)
			{
			case LOAD:

				break;
			case SAVE:

				break;
			case INPUT:

				break;
			case EXIT:

				break;
			default:
				cout << "Invalid command" << endl;
				break;
			}
		}
		catch (const exception& ex)
		{
			cin.clear();
			char c;
			cin >> c;
			cout << ex.what() << endl;
		}

	} while (cmnd != COM::EXIT);


	

	return 1;
}

