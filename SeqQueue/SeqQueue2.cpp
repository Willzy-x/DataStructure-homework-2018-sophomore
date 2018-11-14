//
//  SeqQueue2.cpp
//  SeqQueue1
//
//  Created by Yucheng on 2018/10/11.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "SeqQueue2.h"
using namespace std;
//使用flag判断是否满/空队列
//构造函数
template <class T, int MaxSize>
SeqQueue2<T, MaxSize>::SeqQueue2()
{
    front = -1;
    rear = -1;
    flag = false;
}
//入队
template <class T, int MaxSize>
void SeqQueue2<T, MaxSize>::EnQueue(T x)
{
    if (front == rear && flag) {
        cerr << "Overflow\n";
        exit(1);
    }
    rear = (rear+1) % MaxSize;
    data[rear] = x;
    flag = true;
}
//出队
template <class T, int MaxSize>
T SeqQueue2<T, MaxSize>::DeQueue()
{
    if (front == rear && !flag) {
        cerr << "Empty!\n";
        exit(1);
    }
    front = (front+1) % MaxSize;
    flag = false;
    return data[front];
}
//取得队头元素
template <class T, int MaxSize>
T SeqQueue2<T, MaxSize>::GetQueue()
{
    if (front == rear && !flag) {
        cerr << "Empty!\n";
        exit(1);
    }
    int temp = (front+1) % MaxSize;
    return data[temp];
}
//判读空队列
template <class T, int MaxSize>
bool SeqQueue2<T, MaxSize>::Empty()
{
    return (front == rear && !flag);
}
