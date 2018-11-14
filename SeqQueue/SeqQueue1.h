//
//  SeqQueue1.h
//  SeqQueue1
//
//  Created by Yucheng on 2018/10/11.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#ifndef SeqQueue1_h
#define SeqQueue1_h
#include <iostream>
//using namespace std;
template <class T, int MaxSize>
class SeqQueue1
{
    T data[MaxSize];
    int front, rear;
public:
    SeqQueue1();
    void EnQueue(T x);
    T DeQueue();
    T GetQueue();
    bool Empty();
};

#endif /* SeqQueue1_h */
