#include "Student.h"
#include <string>
#include <iostream>

#ifndef STUDENT_CPP
#define STUDENT_CPP

using namespace std;

/*Constructor of Default*/
Student::Student() : Human()
{
#ifdef _DEBUG
	cout << " " << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

/*Constructor of Copy*/
Student::Student(string& _fio, string& _group, string& _profession, int _curCourse, double _avgMark) :
	Human(_fio), group(_group), profession(_profession), curCourse(_curCourse), avgMark(_avgMark)
{
#ifdef _DEBUG
	cout << " " << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

/*Constructor of Copy*/
Student::Student(const Student& _student) : 
	Human(_student.fio), group(_student.group), profession(_student.profession), curCourse(_student.curCourse), avgMark(_student.avgMark)
{
#ifdef _DEBUG
	cout << " " << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

/*Constructor of Move*/
Student::Student(Student&& _student) noexcept : Human()
{
	this->fio = move(_student.fio);
	this->group = move(_student.group);
	this->profession = move(_student.profession);
	this->curCourse = move(_student.curCourse);
	this->avgMark = move(_student.avgMark);
#ifdef _DEBUG
	cout << " " << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

/*Destructor*/
Student::~Student()
{
#ifdef _DEBUG
	cout << "~" << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

void Student::moveSwap(Student& _source) noexcept
{
	Student temp(*this);
	*this = move(_source);
	_source = move(temp);
}

string Student::getClassName() const
{
	return string("Student");
}

string Student::getStr() const
{
	string _str = this->getClassName() + " " + this->getFio() + " " \
		+ this->getGroup() + " " + this->getProfession() + " " \
		+ std::to_string(this->getCurCourse()) + " " + std::to_string(this->getAvgMark()) + " ";
	return _str;
}

void Student::nullifyParams()
{
	this->fio = "";
	this->group = "";
	this->profession = "";
	this->curCourse = 0;
	this->avgMark = 0.0;
}

double Student::getAvgMark() const
{
	return this->avgMark;
}

void Student::setAvgMark(double _avgMark)
{
	this->avgMark = _avgMark;
}

int Student::getCurCourse() const
{
	return this->curCourse;
}

void Student::setCurCourse(int _curCourse)
{
	this->curCourse = _curCourse;
}

string Student::getGroup() const
{
	return this->group;
}

void Student::setGroup(string _group)
{
	this->group = _group;
}

string Student::getProfession() const
{
	return this->profession;
}

void Student::setProfession(string _profession)
{
	this->profession = _profession;
}

Student& Student::operator=(const Student& _student)
{
	this->fio = _student.fio;
	this->group = _student.group;
	this->profession = _student.profession;
	this->curCourse = _student.curCourse;
	this->avgMark = _student.avgMark;
	return *this;
}

Student& Student::operator=(Student&& _student) noexcept
{
	this->fio = move(_student.fio);
	this->group = move(_student.group);
	this->profession = move(_student.profession);
	this->curCourse = move(_student.curCourse);
	this->avgMark = move(_student.avgMark);
	return *this;
}


#endif // !STUDENT_CPP


