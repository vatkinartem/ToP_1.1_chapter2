#pragma once
#include <string>

using namespace std;

class Human
{
private:

protected:
	string fio;
public:
	Human();
	Human(const string& _fio);
	virtual ~Human();
	virtual string getClassName() const;
	virtual string getStr() const;

	string getFio() const;
	void setFio(string _fio);
};

