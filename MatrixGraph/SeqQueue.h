//
//  SeqQueue.h
//  MGraph
//
//  Created by Yucheng on 2018/11/27.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#ifndef SeqQueue_h
#define SeqQueue_h
template <class T, int MaxSize>
class SeqQueue
{
    T data[MaxSize];
    int front, rear;
    bool flag;//判断刚刚是否有元素进入队列
public:
    SeqQueue();
    void EnQueue(T x);
    T DeQueue();
    T GetQueue();
    bool Empty();
};

#endif /* SeqQueue_h */
