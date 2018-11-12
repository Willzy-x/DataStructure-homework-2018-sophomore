//
//  Good.h
//  Ds2
//
//  Created by Yucheng on 2018/9/15.
//  Copyright © 2018年 Yucheng. All rights reserved.
//

#ifndef Good_h
#define Good_h


#include <iostream>
using namespace std;
class Good{
private:
    int id;
    string name;
    float price;
    int store_crr;
public:
    Good();
    Good(int Id, string n, float p=10, int crr=20);
    int getID();
    int getPrice();
    int getCrr();
    string getName();
    void changePrice(int p);
    friend bool operator==(const Good& a, const Good& b);
    friend bool operator> (const Good& a, const Good& b);
    friend bool operator< (const Good& a, const Good& b);
    friend bool operator>= (const Good& a, const Good& b);
    friend bool operator<= (const Good& a, const Good& b);
    Good& operator= (Good& a);
    friend ostream& operator <<(ostream& co, Good g);
    friend istream& operator >>(istream& ci, Good& g);
};



#endif /* Good_h */
