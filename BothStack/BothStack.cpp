//
//  BothStack.cpp
//  BothStack
//
//  Created by Yucheng on 2018/9/29.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "BothStack.h"
using namespace std;
//初始化
template <class T, int MaxSize>
BothStack<T, MaxSize>::BothStack()
{
    top1 = -1;
    top2 = MaxSize;
}
//析构函数
template <class T, int MaxSize>
BothStack<T, MaxSize>::~BothStack<T, MaxSize>()
{
}
//入栈操作
template <class T, int MaxSize>
void BothStack<T, MaxSize>::Push(int i, T x)
{
    while (true)
    {
        switch (i)
        {
            case 1:
                if (top1 == top2 - 1)
                {
                    cerr << "Stack over flow!\n";
                    exit(1);
                }
                else
                {
                    top1++;
                    data[top1] = x;
                }
                return;
            case 2:
                if (top2 == top1 + 1)
                {
                    cerr << "Stack over flow!\n";
                    exit(1);
                }
                else
                {
                    top2--;
                    data[top2] = x;
                }
                return;
            default:
                cout << "Illegal input, please try again:\n";
                return;
        }
        cin >> i;
    }
}
//出栈操作
template <class T, int MaxSize>
T BothStack<T, MaxSize>::Pop(int i)
{
    while (true)
    {
        switch (i)
        {
            case 1:
                if (top1 == -1)
                {
                    cerr << "Stack over flow!\n";
                    exit(1);
                }
                else
                {
                    return data[top1--];
                }
                break;
            case 2:
                if (top2 == MaxSize)
                {
                    cerr << "Stack over flow!\n";
                    exit(1);
                }
                else
                {
                    return data[top2++];
                }
                break;
            default:
                cout << "Illegal input, please try again:\n";
        }
        cin >> i;
    }
}
//判断栈是否为空
template <class T, int MaxSize>
bool BothStack<T, MaxSize>::Empty(int i)
{
    while (true) {
        switch (i) {
            case 1:
                return (top1 == -1);
            case 2:
                return (top2 == MaxSize);
            default:
                cout << "Illegal input, please try again:\n";
        }
        cin >> i;
    }
}
