#include "Professor.h"
#ifndef PROFESSOR_CPP
#define PROFESSOR_CPP

using namespace std;
using namespace myvec;

Professor::Professor() : Human()
{
#ifdef _DEBUG
	cout << " " << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

/*Constructor of copy*/
Professor::Professor(const Professor& _source) : 
	Human(_source.fio), listOfGroups(_source.listOfGroups), subjects(_source.subjects)
{
#ifdef _DEBUG
	cout << " " << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

/*Constructor of move*/
Professor::Professor(Professor&& _source) noexcept : Human()
{
	this->fio = move(_source.fio);
	this->listOfGroups = move(_source.listOfGroups);
	this->subjects = move(_source.subjects);
#ifdef _DEBUG
	cout << " " << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

Professor::~Professor()
{
#ifdef _DEBUG
	cout << "~" << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

void Professor::SwapProfessors(Professor& _source) noexcept
{
}

string Professor::getClassName() const
{
	return string("Professor");
}

string Professor::getStr() const
{
	string _str = this->getClassName() + " ";
	_str = _str + this->fio + " ";
	/*getting all groups*/
	_str = _str + "(";
	for (long long i = 0; i < this->listOfGroups.getSize(); i++)
	{
		_str = _str + this->listOfGroups[i] + " ";
	}
	_str = _str + ") ";

	/*getting all groups*/
	_str = _str + "(";
	for (long long i = 0; i < this->subjects.getSize(); i++)
	{
		_str = _str + this->subjects[i] + " ";
	}
	_str = _str + ") ";
	return _str;
}

MyVector<string>& Professor::getListOfGroups() const
{
	return (MyVector<string>&)(this->listOfGroups);
}

void Professor::setListOfGroups(const MyVector<string>& list)
{
	this->listOfGroups = list;
}

MyVector<string>& Professor::getSubjects() const
{
	return (MyVector<string>&)(this->subjects);
}

void Professor::setSubjects(const MyVector<string>& list)
{
	this->subjects = this->subjects;
}

Professor& Professor::operator=(const Professor& _professor)
{
	this->fio = _professor.fio;
	this->listOfGroups.freeMyVector();
	this->subjects.freeMyVector();
	for (long long i = 0; i < _professor.listOfGroups.getSize(); i++)
	{
		this->listOfGroups[i] = _professor.listOfGroups[i];
	}
	for (long long i = 0; i < _professor.subjects.getSize(); i++)
	{
		this->subjects[i] = _professor.subjects[i];
	}
	return *this;
}

Professor& Professor::operator=(Professor&& _professor) noexcept
{
	this->fio = move(_professor.fio);
	this->listOfGroups = move(_professor.listOfGroups);
	this->subjects = move(_professor.subjects);
	return *this;
}


#endif // !PROFESSOR_CPP

