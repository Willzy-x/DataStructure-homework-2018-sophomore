//
//  SeqQueue3.cpp
//  SeqQueue1
//
//  Created by Yucheng on 2018/10/11.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "SeqQueue3.h"
using namespace std;
//利用num存储当前队列所含元素个数，从而判断满/空
//构造函数
template <class T, int MaxSize>
SeqQueue3<T, MaxSize>::SeqQueue3()
{
    front = -1;
    rear = -1;
    num = 0;
}
//入队
template <class T, int MaxSize>
void SeqQueue3<T, MaxSize>::EnQueue(T x)
{
    if (front == rear && num == MaxSize) {
        cerr << "Overflow!\n";
        exit(1);
    }
    rear = (rear+1) % MaxSize;
    data [rear] = x;
    num++;
}
//出队
template <class T, int MaxSize>
T SeqQueue3<T, MaxSize>::DeQueue()
{
    if (front == rear && num == 0) {
        cerr << "Empty!\n";
        exit(1);
    }
    front = (front+1) % MaxSize;
    num--;
    return data[front];
}
//获取队头元素
template <class T, int MaxSize>
T SeqQueue3<T, MaxSize>::GetQueue()
{
    if (front == rear && num == 0) {
        cerr << "Empty!\n";
        exit(1);
    }
    int temp = (front+1) % MaxSize;
    return data[temp];
}
//判读队列为空
template <class T, int MaxSize>
bool SeqQueue3<T, MaxSize>::Empty()
{
    return (front == rear && num == 0);
}
//获取队列长度
template <class T, int MaxSize>
int SeqQueue3<T, MaxSize>::GetLen()
{
    return num;
}
