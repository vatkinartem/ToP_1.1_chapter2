#pragma once
#include "Human.h"
#include "MyVector.h"


#ifndef PROFESSOR_H
#define PROFESSOR_H

using namespace std;
using namespace myvec;

class Professor :
    public Human
{
private:
    MyVector<string> listOfGroups;
    MyVector<string> subjects;

public:
    Professor();
    Professor(const Professor& _source);
    Professor(Professor&& _source) noexcept;
     ~Professor();
    void SwapProfessors(Professor& _source) noexcept;
    virtual string getClassName() const override;
    virtual string getStr() const override;

    MyVector<string>& getListOfGroups()  const;
    void setListOfGroups(const MyVector<string>& list);
    MyVector<string>& getSubjects() const;
    void setSubjects(const MyVector<string>& list) ;

    Professor& operator= (const Professor& _professor);
    Professor& operator= (Professor&& _professor) noexcept;
};


#endif //!ADMINSTAFF_H


