#include <iostream>
#include <stdio.h>
#include "Keeper.h"
#include <string>
#include <sstream>
#include <vector>
#include <exception>

static keep::Keeper::vars strToVar(string& str) {
	using namespace keep;
	string classNames[3];
	classNames[0] = Student().getClassName();
	classNames[1] = Professor().getClassName();
	classNames[2] = AdminStaff().getClassName();
	if (str == classNames[0])
	{
		return Keeper::vars::STUDENT;
	}
	else if (str == classNames[1])
	{
		return Keeper::vars::PROFESSOR;
	}
	else if (str == classNames[2])
	{
		return Keeper::vars::ADMINSTAFF;
	}
	return Keeper::vars::NONE;
}

static MyVector<string> extractWordsBetweenChars1(string str, char c0, char c1) {
	MyVector<string> words;
	bool inRange = false;
	string temp = "";
	for (char c : str)
	{
		if (c == c0)
		{
			inRange = true;
			continue;
		}
		if (c == c1)
		{
			inRange = false;
			words.pushBack(std::move(temp));
			continue;
		}
		if (inRange)
		{
			temp += c;
		}
	}
	return words;
}

static MyVector<string> extractFirstNWords1(string str, char c0, int num) {
	MyVector<string> words;
	string temp = "";
	bool inWord = false;
	if (str[str.size() - 1] != '\n')
	{
		str.push_back('\n');
	}
	for (char c : str)
	{
		if ((c != c0) && (c != '\n') && (c != '\0'))
		{
			inWord = true;
			temp += c;
			continue;
		}
		if ((inWord) && ((c == c0) || (c == '\n') || (c == '\0')))
		{
			words.pushBack(std::move(temp));
			inWord = false;
			if (words.getSize() == num)
			{
				break;
			}
		}
	}
	return words;
}


static bool is_integer(float k)
{
	return std::floor(k) == k;
}

namespace COM {
	enum COM
	{
		DEFAULT,
		HELP,
		LOAD,
		SAVE,
		PRINT,
		INPUT,
		EXIT
	};
}

namespace MODE {
	enum MODE {
		DEFAULT,
		HELP,
		ADD,
		EMPLACE,
		DELETE,
		EXIT
	};
}



static istream& operator>>(istream& is, COM::COM& i)
{
	int temp;
	if (is >> temp)
		i = static_cast<COM::COM>(temp);
	return is;
}

static istream& operator>>(istream& is, MODE::MODE& i)
{
	int temp;
	if (is >> temp)
		i = static_cast<MODE::MODE>(temp);
	return is;
}


static bool isValidString(std::string& str) {
	if (str.size() == 0)
	{
		return false;
	}
	using keep::Keeper;
	using myvec::MyVector;
	MyVector<string> word;
	MyVector<string> wordBrack;
	double testd;
	long long testi;
	Keeper::vars ourVar = Keeper::vars::NONE;
	std::istringstream iss;
	word.pushBack(std::move(extractFirstNWords1(str, ' ', -1)));
	ourVar = strToVar(word[0]);


	if (ourVar == Keeper::vars::STUDENT)				/*then Student fio group profesion 1 0.0 */
	{
		word.pushBack(std::move(extractFirstNWords1(str, ' ', -1)));
		if (word.getSize() == 6)
		{
			if (stoi(word[4]) == errno)
			{
				return false;
			}
			else
			{
				if (!is_integer(stoi(word[4])))
				{
					return false;
				}
			}
			if (stod(word[5]) == errno)
			{
				return false;
			}
			return true;
		}
	}
	else if (ourVar == Keeper::vars::PROFESSOR)		/*then Professor fio (group1 group2) (sub1 sub2) */
	{
		if (word.getSize() >= 2)
		{
			wordBrack.pushBack(std::move(extractWordsBetweenChars1(str, '(', ')')));
			if (wordBrack.getSize() == 2)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (ourVar == Keeper::vars::ADMINSTAFF)		/*then AdminStaff fio post phone areaOfResponse */
	{
		if (word.getSize() == 5)
		{
			return true;
		}
	}
	return false;
}

static void executeFunc(keep::Keeper& base) {
	using keep::Keeper;
	MyVector<string> words;
	istringstream& iss();
	MODE::MODE mode = MODE::DEFAULT;
	keep::Keeper::vars var = keep::Keeper::vars::NONE;
	long long temp = -1;
	string head;
	string str;
	char c;
	cout << "\nHelp - " << MODE::HELP << "\nadd - " << MODE::ADD << "\nemplace - " \
		<< MODE::EMPLACE << "\ndelete - " << MODE::DELETE << "\nexit - " << MODE::EXIT << endl;

	do
	{

		try
		{
			var = Keeper::vars::NONE;
			mode = MODE::DEFAULT;
			cout << "\nAwaiting mode..." << endl;
			cin >> mode;
			if (cin.fail())
			{
				throw(exception("Cant parse to string"));
			}

			switch (mode)
			{
			case MODE::HELP:
				cout << "\nHelp - " << MODE::HELP << "\nadd - " << MODE::ADD << "\nemplace - " \
					<< MODE::EMPLACE << "\ndelete - " << MODE::DELETE << "\nexit - " << MODE::EXIT << endl;
				break;
			case MODE::ADD:
				cout << "\nPrint string to be added. Input according to the hint below (atherwise it wont be added). Separating with spaces.\nIf field is missing then print \"-\"" << endl;
				cout << "For student structure is (without figure brackets)	{Student f_i_o group profesion 1 0.0}" << endl;			/*then Student fio group profesion 1 0.0 */
				cout << "For student structure is (without figure brackets) {Professor f_i_o (group1 group2) (sub1 sub2)}" << endl;			/*then Professor fio (group1 group2) (sub1 sub2) */
				cout << "For student structure is (without figure brackets) {AdminStaff f_i_o post phone areaOfResponse}\n" << endl;			/*then AdminStaff fio post phone areaOfResponse */
				cin >> head;
				getline(cin, str, '\n');
				
				str = head + str;
				if (cin.fail())
				{
					throw(exception("Cant parse to string"));
				}
				if (isValidString(str))
				{
					base.addEntry(str);
				}
				break;

			case MODE::EMPLACE:
				cout << "Print index and string to be emplaced" << endl;
				cout << "Index..." << endl;
				cin >> temp;
				if (cin.fail())
				{
					throw(exception("Cant parse to string"));
				}

				cout << "Class name..." << endl;
				cin >> head;
				var = strToVar(head);
				if (var == Keeper::vars::NONE)
				{
					throw(exception("Wrong class name"));
				}

				cout << "\nPrint string to be added. Input according to the hint below (atherwise it wont be added). Separating with spaces.\nIf field is missing then print \"-\"" << endl;
				cout << "For student structure is (without figure brackets)	{Student f_i_o group profesion 1 0.0}" << endl;			/*then Student fio group profesion 1 0.0 */
				cout << "For student structure is (without figure brackets) {Professor f_i_o (group1 group2) (sub1 sub2)}" << endl;			/*then Professor fio (group1 group2) (sub1 sub2) */
				cout << "For student structure is (without figure brackets) {AdminStaff f_i_o post phone areaOfResponse}" << endl;			/*then AdminStaff fio post phone areaOfResponse */
				cout << "String with validate format..." << endl;
				cin >> head;
				getline(cin, str, '\n');
				str = head + str;
				if (cin.fail())
				{
					throw(exception("Cant parse to string"));
				}
				if (!isValidString(str))
				{
					break;
				}
				
				if (var == Keeper::vars::STUDENT)
				{
					words = std::move(extractFirstNWords1(str, ' ', 6));
					Student temps = { words[1] , words[2] , words[3] , stoi(words[4]) , stod(words[5]) };
					base.getStudens().emplace(temp, std::move(temps));
				}
				else if (var == Keeper::vars::PROFESSOR)
				{
					/*then Professor fio (group1 group2) (sub1 sub2) */
					words = std::move(extractFirstNWords1(str, ' ', 2));
					Professor tempp;
					tempp.setFio(words[1]);

					words = extractWordsBetweenChars1(str, '(', ')');
					MyVector<string> words2;		/*for text field in brekets*/
					words2 = std::move(extractFirstNWords1(words[0], ' ', -1));
					tempp.getListOfGroups().pushBack(std::move(words2));


					words2 = std::move(extractFirstNWords1(words[1], ' ', -1));
					tempp.getSubjects().pushBack(std::move(words2));
					base.getProfessors().emplace(temp, std::move(tempp));
				}
				else if (var == Keeper::vars::ADMINSTAFF)
				{
					words = std::move(extractFirstNWords1(str, ' ', 5));
					AdminStaff tempa;
					tempa.setFio(words[1]);
					tempa.setPost(words[2]);
					tempa.setPhone(words[3]);
					tempa.setAreaOfRespons(words[4]);
					base.getAdminStaff().emplace(temp, std::move(tempa));
				}
				
				break;

			case MODE::DELETE:
				cout << "Print index and string that represents class name (Student for example)" << endl;
				cout << "Index..." << endl;
				cin >> temp;
				if (cin.fail())
				{
					throw(exception("Cant parse to string"));
				}

				cout << "Class name..." << endl;
				cin >> head;
				if (cin.fail())
				{
					throw(exception("Cant parse to string"));
				}
				var = strToVar(head);
				if (var == Keeper::vars::STUDENT)
				{
					base.getStudens().erase(temp);
				}
				else if (var == Keeper::vars::PROFESSOR)
				{
					base.getProfessors().erase(temp);
				}
				else if (var == Keeper::vars::ADMINSTAFF)
				{
					base.getAdminStaff().erase(temp);
				}

				break;

			case MODE::EXIT:
				cout << "Exiting input menu" << endl;
				break;

			default:
				cout << "Invalid command" << endl;
				break;
			}
		}
		catch (const std::exception& ex)
		{
			cin.clear();
			char c;
			cin >> c;
			cout << ex.what() << endl;
		}

	} while (mode != MODE::EXIT);

}



int main()
{
	using namespace std;
	using namespace myvec;
	using namespace keep;

	string str;
	COM::COM cmnd;
	int cmnd_int;

	Keeper base;
	cout << "\nHelp - " << COM::HELP << "\nload - " << COM::LOAD << "\nsave - " \
		<< COM::SAVE << "\nprint - " << COM::PRINT << "\ninput - " << COM::INPUT << "\nexit - " << COM::EXIT << endl;
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
			if (((COM::COM)cmnd_int < COM::DEFAULT) || ((COM::COM)cmnd_int > COM::EXIT))
			{
				throw(exception("Wrong command"));
			}
			cmnd = (COM::COM)cmnd_int;

			switch (cmnd)
			{
			case COM::HELP:
				cout << "\nHelp - " << COM::HELP << "\nload - " << COM::LOAD << "\nsave - " \
					<< COM::SAVE << "\nprint - " << COM::PRINT << "\ninput - " << COM::INPUT << "\nexit - " << COM::EXIT << endl;
				break;
			case COM::LOAD:
				base.loadFromFile();
				break;
			case COM::SAVE:
				base.saveToFile();
				break;
			case COM::PRINT:
				base.print();
				break;
			case COM::INPUT:
				cout << "Please input" << endl;
				executeFunc(base);
				break;
			case COM::EXIT:
				base.clearKeeper();
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

