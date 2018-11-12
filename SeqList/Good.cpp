//
//  Good.cpp
//  Ds2
//
//  Created by Yucheng on 2018/9/15.
//  Copyright © 2018年 Yucheng. All rights reserved.
//

#include "Good.h"
#include <iostream>
#include <string>
Good::Good(){
    id = 0;
    name = "None";
    store_crr = 0;
    price = 0;
}
Good::Good(int Id, string n, float p, int crr){
    
    id = Id;
    name = n;
    price = p;
    store_crr = crr;
}
int Good::getID(){
    return id;
}
int Good::getPrice(){
    return price;
}
int Good::getCrr(){
    return store_crr;
}
string Good::getName(){
    string *temp = new string;
    *temp = this->name;
    return *temp;
}
void Good::changePrice(int p){
    price = p;
}
//////////////////////////////////////////////
bool operator==(const Good& a, const Good& b){
    return (a.id == b.id);
}

bool operator>(const Good& a, const Good& b){
    return (a.id > b.id);
}
bool operator<(const Good& a, const Good& b){
    return (a.id < b.id);
}
bool operator<=(const Good& a, const Good& b){
    return (a.id <= b.id);
}
bool operator>=(const Good& a, const Good& b){
    return (a.id >= b.id);
}
//所有大小关系以商品代号为准////////////////////////
Good& Good::operator= (Good& a){
    this->id = a.id;
    this->name = a.name;
    this->price = a.price;
    this->store_crr = a.store_crr;
    return *this;
}
ostream& operator<<(ostream& co, Good g){
    co << "ID = " << g.getID() << " Name = " << g.getName() << " Price = " << g.getPrice() << " current = " << g.getCrr() << endl;
    return co;
}
istream& operator>>(istream& ci, Good& g){
    ci >> g.id >> g.price >> g.store_crr >> g.name;
    return ci;
}
