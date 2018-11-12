//
//  Student.h
//  LinkList
//
//  Created by Yucheng on 2018/9/25.
//  Copyright © 2018年 Yucheng. All rights reserved.
//

#ifndef Student_h
#define Student_h
#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    int ID;
    string name;
    int gender;
    
public:
    Student();
    Student(int i, string n, int g);
    int getID();
    string getName();
    int getGender();
    void Modify(string n, int g);
    bool operator==(const Student& s1);
    Student& operator= (Student& a);
    friend ostream& operator <<(ostream& co, Student g);
    friend istream& operator >>(istream& ci, Student& g);
};

#endif /* Student_h */
