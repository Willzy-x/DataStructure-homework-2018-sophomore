//
//  LinkList.h
//  LinkList
//
//  Created by Yucheng on 2018/9/18.
//  Copyright © 2018年 Yucheng. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h
template <class T>
struct Node{
    T data;
    Node<T> * next;
};

template <class T>
class LinkList {
    Node<T> * head;
    
public:
    LinkList();
    LinkList(T a[], int n);
    ~LinkList();
    int ListLength();
    T Get(int pos);
    int Locate(T item);
    void PrintLinkList();
    void Insert(int i, T item);
    T Delete(int i);
    void Invert();//原地逆置
    void getMiddleNode(LinkList<T> &L);//将链表从中间分成两段
    void Merge(LinkList<T> &L2);//合并已有链表
    void changeInfo(int i, T item);
    T GetTheLastK(int k);//找倒数第K个元素
    
    bool isLoop();//判断是否有环
    int LoopLen();//求环的程序
    void Append(T item);//末尾添加节点
};

#endif /* LinkList_h */
