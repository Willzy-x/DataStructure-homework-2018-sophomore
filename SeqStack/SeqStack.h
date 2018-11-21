//
//  SeqStack.h
//  SeqStack
//
//  Created by Yucheng on 2018/9/29.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#ifndef SeqStack_h
#define SeqStack_h
#include <iostream>
using namespace std;

const int MaxSize = 100;
template <class T, int MaxSize>
class SeqStack
{
private:
    int top;
    T data[MaxSize];
    
public:
    SeqStack();
    void Push(T x);
    T Pop();
    T Top();
    bool isEmpty();
};

#endif /* SeqStack_h */
