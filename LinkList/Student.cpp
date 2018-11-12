//
//  Student.cpp
//  LinkList
//
//  Created by Yucheng on 2018/9/25.
//  Copyright © 2018年 Yucheng. All rights reserved.
//

#include <iostream>
#include <string>
#include "Student.h"
using namespace std;
Student::Student()
{
    ID = 0;
    name = "None";
    gender = 0;
}

Student::Student(int i, string n, int g)
{
    ID = i;
    name = n;
    gender = g;
}

int Student::getID()
{
    return ID;
}

string Student::getName()
{
    return name;
}

int Student::getGender()
{
    return gender;
}

void Student::Modify(string n, int g)
{
    name = n;
    gender = g;
}

bool Student::operator==(const Student& s1)
{
    return (s1.ID == ID);
}

Student& Student::operator=(Student &a)
{
    if(ID == a.getID()) return a;
    ID = a.getID();
    name = a.getName();
    gender = a.getGender();
    return *this;
}

ostream& operator<< (ostream& co, Student a)
{
    co << "ID: " << a.getID() << " " <<  "Name: " << a.getName() << " Gender: " << a.getGender() << endl;
    return co;
}

istream& operator>> (istream& ci, Student& a)
{
    ci >>  a.ID >> a.gender >> a.name;
    return ci;
}
