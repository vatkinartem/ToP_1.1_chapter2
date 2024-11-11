#include "AdminStaff.h"

#ifndef ADMINSTAFF_CPP
#define ADMINSTAFF_CPP

using namespace std;

AdminStaff::AdminStaff() : Human()
{
#ifdef _DEBUG
	cout << " " << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

AdminStaff::AdminStaff(const AdminStaff& _source) : 
	Human(_source.fio), post(_source.post), phone(_source.post), areaOfRespons(_source.post)
{
#ifdef _DEBUG
	cout << " " << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

AdminStaff::AdminStaff(AdminStaff&& _source) noexcept : Human()
{
	this->fio = move(_source.fio);
	this->post = move(_source.post);
	this->phone = move(_source.post);
	this->areaOfRespons = move(_source.areaOfRespons);
#ifdef _DEBUG
	cout << " " << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

AdminStaff::~AdminStaff()
{
#ifdef _DEBUG
	cout << "~" << this->getClassName() << "() with adress " << this << endl;
#endif // _DEBUG
}

string AdminStaff::getClassName() const
{
	return string("AdminStaff");
}

string AdminStaff::getStr() const
{
	string _str = this->getClassName() + " ";
	_str = _str + this->fio + " " + this->post + " " + this->phone + " " + this->areaOfRespons + " ";
	return _str;
}

void AdminStaff::moveSwap(AdminStaff& _source) noexcept
{
	AdminStaff temp(move(*this));
	*this = move(_source);
	_source = move(temp);
}

string AdminStaff::getPost() const
{
	return this->post;
}

void AdminStaff::setPost(const string& _source)
{
	this->post = _source;
}

string AdminStaff::getPhone() const
{
	return this->phone;
}

void AdminStaff::setPhone(const string& _source)
{
	this->phone = _source;
}

string AdminStaff::getAreaOfRespons() const
{
	return this->areaOfRespons;
}

void AdminStaff::setAreaOfRespons(const string& _source)
{
	this->areaOfRespons = _source;
}

AdminStaff& AdminStaff::operator=(const AdminStaff& _adminstaff)
{
	this->fio = _adminstaff.fio;
	this->post = _adminstaff.post;
	this->phone = _adminstaff.phone;
	this->areaOfRespons = _adminstaff.areaOfRespons;
	return *this;
}

AdminStaff& AdminStaff::operator=(AdminStaff&& _adminstaff) noexcept
{
	this->fio = move(_adminstaff.fio);
	this->post = move(_adminstaff.post);
	this->phone = move(_adminstaff.phone);
	this->areaOfRespons = move(_adminstaff.areaOfRespons);
	return *this;
}



#endif // !ADMINSTAFF_CPP

