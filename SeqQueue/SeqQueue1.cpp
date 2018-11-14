//
//  SeqQueue1.cpp
//  SeqQueue1
//
//  Created by Yucheng on 2018/10/11.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "SeqQueue1.h"
using namespace std;
//使用额外数组空间的循环队列方法
//构造函数
template <class T, int MaxSize>
SeqQueue1<T, MaxSize>::SeqQueue1()
{
    front = 0;
    rear = 0;
}
//入队
template <class T, int MaxSize>
void SeqQueue1<T, MaxSize>::EnQueue(T x)
{
    if ((rear+1) % MaxSize == front) {
        cerr << "Overflow!\n";
        exit(1);
    }
    rear = (rear+1) % MaxSize;
    data[rear] = x;
}
//出队
template <class T, int MaxSize>
T SeqQueue1<T, MaxSize>::DeQueue()
{
    if (rear == front) {
        cerr << "Empty queue!\n";
        exit(1);
    }
    front = (front+1) % MaxSize;
    return data[front];
}
//得到队尾元素
template <class T, int MaxSize>
T SeqQueue1<T, MaxSize>::GetQueue()
{
    if (rear == front) {
        cerr << "Empty queue!\n";
        exit(1);
    }
    int temp = (front+1) % MaxSize;
    return data[temp];
}
//判断队列是否为空
template <class T, int MaxSize>
bool SeqQueue1<T, MaxSize>::Empty()
{
    return front == rear;
}
