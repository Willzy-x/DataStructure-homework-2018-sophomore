//
//  SeqStack.cpp
//  SeqStack
//
//  Created by Yucheng on 2018/9/29.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "SeqStack.h"
using namespace std;
//构造函数
template <class T, int MaxSize>
SeqStack<T, MaxSize>::SeqStack()
{
    top = -1;
}
//入栈操作
template <class T, int MaxSize>
void SeqStack<T, MaxSize>::Push(T x)
{
    if (top == MaxSize - 1)
    {
        cerr << "Stack over flow!\n";
        exit(1);
    }
    data[++top] = x;//******************
}
//出栈操作
template <class T, int MaxSize>
T SeqStack<T, MaxSize>::Pop()
{
    if (top == -1)
    {
        cerr << "The stack is empty!\n";
        exit(1);
    }
    return data[top--];
}
//取得栈顶元素
template <class T, int MaxSize>
T SeqStack<T, MaxSize>::Top()
{
    if (top == -1)
    {
        cerr << "The stack is empty!\n";
        exit(1);
    }
    return data[top];
}
//判断空栈
template <class T, int MaxSize>
bool SeqStack<T, MaxSize>::isEmpty()
{
    return (top == -1);
}
