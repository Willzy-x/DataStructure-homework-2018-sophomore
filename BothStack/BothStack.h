//
//  BothStack.h
//  BothStack
//
//  Created by Yucheng on 2018/9/29.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#ifndef BothStack_h
#define BothStack_h
#include <iostream>
using namespace std;
template <class T,int MaxSize>
class BothStack
{
private:
    T data[MaxSize];
    int top1, top2;
    
public:
    BothStack();
    ~BothStack();
    void Push(int i, T x);
    T Pop(int i);
    T GetTop(int i);
    bool Empty(int i);
};

#endif /* BothStack_h */
