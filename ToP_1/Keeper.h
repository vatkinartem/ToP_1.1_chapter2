#pragma once
#include "Student.h"
#include "AdminStaff.h"
#include "Professor.h"
#include "MyVector.h"
#include <fstream>


#ifndef KEEPER_H
#define KEEPER_H

using namespace std;
using namespace myvec;

namespace keep {


class Keeper
{
private:
	MyVector<Student> students;
	MyVector<Professor> professors;
	MyVector<AdminStaff> adminStaff;
	string saveFile;
	string loadFile;

	friend std::string getStrStud(const Student& _source);
	friend std::string getStrProf(const Professor& _source);
	friend std::string getStrAdmi(const AdminStaff& _source);
protected:
	Keeper inputDataFromFile(ifstream& _in);
	template <class Type>
	MyVector<Type> parseString(string str);
	MyVector<string> extractWordsBetweenChars(string str, char c0, char c1);
	MyVector<string> extractFirstNWords(string str, char c0, int num = -1);

public:
	Keeper();
	Keeper(const Keeper& source);
	Keeper(Keeper&& source) noexcept;
	~Keeper();
	string getClassName() const;
	void clearKeeper();
	void setDefaults();
	void saveToFile();
	void loadFromFile();
	void setSaveFile(const string& str);
	string getSaveFile() const;
	void setLoadFile(const string& str);
	string getLoadFile() const;
	void print();
	void execute(const string& _str);
	void addEntry(const string& _str);
	Keeper& operator= (const Keeper& right);
	Keeper& operator= (Keeper&& right) noexcept;
};

#endif // !KEEPER_H


inline Keeper Keeper::inputDataFromFile(ifstream& _in)
{
	Keeper temp;
	string str;

	while (_in.eof())
	{
		_in >> str;
	}

	return temp;
}


template<class Type>
inline MyVector<Type> Keeper::parseString(string str)
{
	return MyVector<Type>();
}

} // keep

