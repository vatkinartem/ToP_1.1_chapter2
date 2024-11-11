#pragma once
#include "Human.h"
#include "MyVector.h"



#ifndef ADMINSTAFF_H
#define ADMINSTAFF_H

using namespace std;

class AdminStaff :
    public Human
{
private:
    /*Для административного персонала определено: ФИО, должность, телефон, область ответственности.*/
    string post;
    string phone;
    string areaOfRespons;

public:
    AdminStaff();
    AdminStaff(const AdminStaff& _source);
    AdminStaff(AdminStaff&& _source) noexcept;
    virtual ~AdminStaff();
    virtual string getClassName() const override;
    virtual string getStr() const override;
    void moveSwap(AdminStaff& _source) noexcept;

    string getPost() const;
    void setPost(const string& _source);
    string getPhone() const;
    void setPhone(const string& _source);
    string getAreaOfRespons() const;
    void setAreaOfRespons(const string& _source);

    AdminStaff& operator= (const AdminStaff& _adminstaff);
    AdminStaff& operator= (AdminStaff&& _adminstaff) noexcept;
};


#endif //!ADMINSTAFF_H