#pragma once
#include "Student.h"
#include "AdminStaff.h"
#include "Professor.h"
#include "MyVector.h"
#include <fstream>


#ifndef KEEPER_H
#define KEEPER_H

namespace keep {


class Keeper
{
private:
	MyVector<Student> students;
	MyVector<Professor> professors;
	MyVector<AdminStaff> adminStaff;
	string saveFile;
	string loadFile;
protected:
	Keeper inputDataFromFile(ifstream& _in);
	template <class Type>
	MyVector<Type> parseString(string str);

public:
	Keeper();
	Keeper(const Keeper& source);
	Keeper(Keeper&& source) noexcept;
	~Keeper();
	MyVector<Student>& getStudens() const;
	MyVector<Professor>& getProfessors() const;
	MyVector<AdminStaff>& getAdminStaff() const;
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

	friend std::string getStrStud(const Student& _source);
	friend std::string getStrProf(const Professor& _source);
	friend std::string getStrAdmi(const AdminStaff& _source);

	friend MyVector<string> extractWordsBetweenChars(string str, char c0, char c1);
	friend MyVector<string> extractFirstNWords(string str, char c0, int num);

	enum vars {
		STUDENT,
		PROFESSOR,
		ADMINSTAFF,
		NONE
	};
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

