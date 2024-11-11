#pragma once
#include "Human.h"

#ifndef STUDENT_H
#define STUDENT_H


using namespace std;

class Student :
    public Human
{
private:
    string group;
    string profession;
    double avgMark;
    int curCourse;

    void nullifyParams();
public:
    Student();
    Student(string& _fio, string& _group, string& _profession, int _curCourse = 0, double _avgMark = 0.0);
    Student(const Student& _student);
    Student(Student&& _student) noexcept;
    virtual ~Student();
    void moveSwap(Student& _source) noexcept;
    virtual string getClassName() const override;
    virtual string getStr() const override;

    double getAvgMark() const;
    void setAvgMark(double _avgMark);
    int getCurCourse() const;
    void setCurCourse(int _curCourse);
    string getGroup() const;
    void setGroup(string _group);
    string getProfession() const;
    void setProfession(string _profession);

    Student& operator= (const Student& _student);
    Student& operator= (Student&& _student) noexcept;
};



#endif // !STUDENT_H


