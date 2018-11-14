//
//  SeqQueue2.h
//  SeqQueue
//
//  Created by Yucheng on 2018/10/11.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#ifndef SeqQueue2_h
#define SeqQueue2_h
template <class T, int MaxSize>
class SeqQueue2
{
    T data[MaxSize];
    int front, rear;
    bool flag;//判断刚刚是否有元素进入队列
public:
    SeqQueue2();
    void EnQueue(T x);
    T DeQueue();
    T GetQueue();
    bool Empty();
};

#endif /* SeqQueue2_h */
