#include "Human.h"
#include <string>
#include <iostream>

using namespace std;

Human::Human() : fio()
{

}

Human::Human(const string& _fio): fio(_fio)
{
#ifdef _DEBUG
	cout << " " << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}


Human::~Human()
{
#ifdef _DEBUG
	cout << "~" << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

string Human::getClassName() const
{
	return string("Human");
}

string Human::getStr() const
{
	string _str = this->getClassName() + " " + this->fio;
	return _str;
}

string Human::getFio() const
{
	return this->fio;
}

void Human::setFio(string source_fio)
{
	this->fio = source_fio;
}

