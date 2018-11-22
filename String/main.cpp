//
//  main.cpp
//  InverseWord
//
//  Created by Yucheng on 2018/10/23.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#include "SS.cpp"
using namespace std;
void PrintReverse(string sent);

SeqStack<string, 100> stringStack;
int main(int argc, const char * argv[]) {
    // insert code here...
    string st = "Do   not stop!";
    PrintReverse(st);
    return 0;
}
//逆置句子单词
void PrintReverse(string sent)
{
    string temp = "";
    for (int i=0; i<sent.length(); i++) {
        if (sent.at(i) != ' ')
        {
            temp += sent.at(i);
        }
        else
        {
            stringStack.Push(temp);
            temp = "";
        }
    }
    stringStack.Push(temp);
    while (!stringStack.isEmpty()) {
        cout << stringStack.Pop() << " ";
    }
}
