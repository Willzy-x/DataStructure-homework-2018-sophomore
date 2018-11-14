//
//  SeqQueue3.h
//  SeqQueue
//
//  Created by Yucheng on 2018/10/11.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#ifndef SeqQueue3_h
#define SeqQueue3_h
template <class T, int MaxSize>
class SeqQueue3
{
    T data[MaxSize];
    int front, rear, num;//num判断当前队列中的元素个数
public:
    SeqQueue3();
    void EnQueue(T x);
    T DeQueue();
    T GetQueue();
    bool Empty();
    int GetLen();//利用num获得当前队列长度
};

#endif /* SeqQueue3_h */
