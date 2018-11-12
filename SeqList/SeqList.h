//
//  SeqList.h
//  Ds2
//
//  Created by Yucheng on 2018/9/12.
//  Copyright © 2018年 Yucheng. All rights reserved.
//


#ifndef SeqList_h
#define SeqList_h

const int MaxSize = 100;
template <class T, int MaxSize>
class SeqList
{
private:
    T data[MaxSize];
    int length;
public:
    SeqList();
    SeqList(T a[], int n);
    int ListLength();
    void modify(T item);
    T Get(int pos);
    int Locate(T item);
    void PrintSeqList();
    void Insert(int i, T item);
    T Delete(int i);
    T DeleteMin();//2.2
    void DeleteAppointed(T x);//2.3
    void DeleteRange(T s, T t);//2.4
    void DeleteRepetition();//2.5
    void InsertionSort();
    void Sorting();//2.6
    SeqList& Merge(SeqList s);//（2）
};


#endif /* SeqList_h */
