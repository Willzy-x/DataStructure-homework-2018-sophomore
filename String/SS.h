//
//  SS.h
//  InverseWord
//
//  Created by Yucheng on 2018/10/23.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#ifndef SS_h
#define SS_h
using namespace std;

const int MaxSize = 100;
template <class T, int MaxSize>
class SeqStack
{
private:
    int top;
    T data[MaxSize];
    
public:
    SeqStack();
    void Push(T x);
    T Pop();
    T Top();
    bool isEmpty();
};


#endif /* SS_h */
