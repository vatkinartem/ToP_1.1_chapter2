#include "Keeper.h"
#include <iostream>
#include <exception>
#include <fstream>
#include <string>

using namespace std;
using namespace myvec;
using namespace keep;

#ifndef KEEPER_CPP
#define KEEPER_CPP


namespace keep {

	std::string getStrStud(const Student& _source) {
		string _str = "Student " + _source.getFio() + " " \
			+ _source.getGroup() + " " + _source.getProfession() + " " \
			+ std::to_string(_source.getCurCourse()) + " " + std::to_string(_source.getAvgMark()) + " ";
		return _str;
	}

	std::string getStrProf(const Professor& _source) {
		string _str = "Professor ";
		_str = _str + _source.getFio() + " ";
		/*getting all groups*/
		_str = _str + "(";
		for (long long i = 0; i < _source.getListOfGroups().getSize(); i++)
		{
			_str = _str + _source.getListOfGroups()[i] + " ";
		}
		_str = _str + ") ";

		/*getting all groups*/
		_str = _str + "(";
		for (long long i = 0; i < _source.getSubjects().getSize(); i++)
		{
			_str = _str + _source.getSubjects()[i] + " ";
		}
		_str = _str + ") ";
		return _str;
	}

	std::string getStrAdmi(const AdminStaff& _source) {
		string _str = "AdminStaff ";
		_str = _str + _source.getFio() + " " + _source.getPost() + " " + _source.getPhone() + " " + _source.getAreaOfRespons() + " ";
		return _str;
	}


Keeper::Keeper()
{
	this->saveFile = "base.txt";
	this->loadFile = "base.txt";
#ifdef _DEBUG
	cout << " " << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

Keeper::Keeper(const Keeper& source)
{
	this->saveFile = "base.txt";
	this->loadFile = "base.txt";
	*this = source;
#ifdef _DEBUG
	cout << " " << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

Keeper::Keeper(Keeper&& source) noexcept
{
	this->students = std::move(source.students);
	this->professors = std::move(source.professors);
	this->adminStaff = std::move(source.adminStaff);
	this->saveFile = std::move(source.saveFile);
	this->loadFile = std::move(source.loadFile);
#ifdef _DEBUG
	cout << " " << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

Keeper::~Keeper()
{
#ifdef _DEBUG
	cout << "~" << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

string Keeper::getClassName() const
{
	return string("Keeper");
}

void Keeper::clearKeeper() {
	this->students.freeMyVector();
	this->professors.freeMyVector();
	this->adminStaff.freeMyVector();
}

void Keeper::setDefaults()
{
	this->saveFile = "base.txt";
	this->loadFile = "base.txt";
}

void Keeper::saveToFile()
{
	string ans;
	ofstream out;

	try
	{
		cout << "Are you sure you want to save to \"" << this->saveFile << "\" ?" << endl;
		cout << "Save base? [y/n]" << endl;
		cin >> ans;
		if (cin.fail())
		{
			throw(exception("Cant convert to string."));
		}
		if ((ans != "y") && (ans != "n"))
		{
			throw(exception("Wrong input. It has to be \"y\" or \"n\" "));
		}
		if (ans == "n")
		{
			return;
		}
		out.open(this->saveFile, ios::out);

		/*output data in file*/
		for (long long i = 0; i < this->students.getSize(); i++)
		{
			Student& tempStu = this->students[i];
			out << getStrStud(tempStu) << endl;
		}
		for (long long i = 0; i < this->professors.getSize(); i++)
		{
			Professor& tempPro = this->professors[i];
			out << getStrProf(tempPro) << endl;
		}
		for (long long i = 0; i < this->adminStaff.getSize(); i++)
		{
			AdminStaff& tempAdm = this->adminStaff[i];
			out << getStrAdmi(tempAdm) << endl;
		}

		out.close();
		cout << "Saving to file \"" << this->saveFile << "\" has been completed.\n" << endl;
	}
	catch (const exception& ex)
	{
		cin.clear();
		char c;
		cin >> c;
		cout << ex.what() << endl;
	}
}

void Keeper::loadFromFile()
{
	string ans;
	string str;
	ifstream in;		/*to temporary storage parced data*/

	try
	{
		cout << "Are you sure you want to load from \"" << this->loadFile << "\" ?" << endl;
		cout << "Load base? [y/n]" << endl;

		cin >> ans;
		if (cin.fail())
		{
			throw(exception("Cant convert to string."));
		}
		if ((ans != "y") && (ans != "n"))
		{
			throw(exception("Wrong input. It has to be \"y\" or \"n\" "));
		}
		if (ans == "n")
		{
			return;
		}

		in.open(this->saveFile, ios::in);

		this->clearKeeper();

		while (getline(in, str, '\n'))
		{
			try
			{
				this->addEntry(str);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
		}

		cout << "Loading from file \"" << this->saveFile << "\" has been completed.\n" << endl;
		in.close();
	}
	catch (const exception& ex)
	{
		cin.clear();
		char c;
		cin >> c;
		cout << ex.what() << endl;
	}
}

void Keeper::setSaveFile(const string& str)
{
	this->loadFile = str;
}

string Keeper::getSaveFile() const
{
	return this->saveFile;
}

void Keeper::setLoadFile(const string& str)
{
	this->loadFile = str;
}

string Keeper::getLoadFile() const
{
	return this->loadFile;
}

void Keeper::print()
{
	cout << "\nOutput in console" << endl;
	for (long long i = 0; i < this->students.getSize(); i++)
	{
		Student& tempStu = this->students[i];
		cout << getStrStud(tempStu) << endl;
	}
	for (long long i = 0; i < this->professors.getSize(); i++)
	{
		Professor& tempPro = this->professors[i];
		cout << getStrProf(tempPro) << endl;
	}
	for (long long i = 0; i < this->adminStaff.getSize(); i++)
	{
		AdminStaff& tempAdm = this->adminStaff[i];
		cout << getStrAdmi(tempAdm) << endl;
	}
	cout << endl;
}

void Keeper::execute(const string& _str)
{

}

void Keeper::addEntry(const string& _str)
{
	string classNames[3];
	classNames[0] = Student().getClassName();
	classNames[1] = Professor().getClassName();
	classNames[2] = AdminStaff().getClassName();
	string str = _str;
	MyVector<string> words;				/*for usual text fields*/
	words = std::move(extractFirstNWords(str, ' ', 1));

	if (words[0] == classNames[0])			/*if Student data*/
	{
		/*then Student fio group profesion 1 0.0*/

		words = std::move(extractFirstNWords(str, ' ', 6));
		Student temp = { words[1] , words[2] , words[3] , stoi(words[4]) , stod(words[5]) };
		this->students.pushBack(std::move(temp));
	}
	else if (words[0] == classNames[1])		/*if Professor data*/
	{
		/*then Professor fio (group1 group2) (sub1 sub2) */
		words = std::move(extractFirstNWords(str, ' ', 2));
		Professor temp;
		temp.setFio(words[1]);

		words = extractWordsBetweenChars(str, '(', ')');
		MyVector<string> words2;		/*for text field in brekets*/
		words2 = std::move(extractFirstNWords(words[0], ' ', -1));
		temp.getListOfGroups().pushBack(std::move(words2));


		words2 = std::move(extractFirstNWords(words[1], ' ', -1));
		temp.getSubjects().pushBack(std::move(words2));

		this->professors.pushBack(std::move(temp));
	}
	else if (words[0] == classNames[2])		/*if AdminStaff data*/
	{
		/*then AdminStaff fio post phone areaOfResponse */
		words = std::move(extractFirstNWords(str, ' ', 5));
		AdminStaff temp;
		temp.setFio(words[1]);
		temp.setPost(words[2]);
		temp.setPhone(words[3]);
		temp.setAreaOfRespons(std::move(words[4]));
		this->adminStaff.pushBack(std::move(temp));
	}
}

MyVector<string> Keeper::extractWordsBetweenChars(string str, char c0, char c1) {
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

MyVector<string> Keeper::extractFirstNWords(string str, char c0, int num) {
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


Keeper& Keeper::operator=(const Keeper& right)
{
	this->clearKeeper();
	this->students = right.students;
	this->professors = right.professors;
	this->adminStaff = right.adminStaff;
	this->saveFile = right.saveFile;
	this->loadFile = right.loadFile;
	return *this;
}

Keeper& Keeper::operator=(Keeper&& right) noexcept
{
	this->students = std::move(right.students);
	this->professors = std::move(right.professors);
	this->adminStaff = std::move(right.adminStaff);
	this->saveFile = std::move(right.saveFile);
	this->loadFile = std::move(right.loadFile);
	return *this;
}


#endif // !KEEPER_CPP

}
