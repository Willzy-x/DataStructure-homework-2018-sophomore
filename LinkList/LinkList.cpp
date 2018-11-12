//
//  LinkList.cpp
//  LinkList
//
//  Created by Yucheng on 2018/9/18.
//  Copyright © 2018年 Yucheng. All rights reserved.
//

#include <iostream>
#include "LinkList.h"
using namespace std;
//无参构造函数
template <class T>
LinkList<T>::LinkList(){
    head = new Node<T>;
    head->next = NULL;
}
//含参构造函数
template <class T>
LinkList<T>::LinkList(T a[], int n){
//从头插入的构造函数
//    head = new Node<T>;
//    head->next = NULL;
//    for (int i=0; i<n; i++) {
//        Node<T>* s = new Node<T>;
//        s->data = a[i];
//        s->next = head->next;
//        head->next = s;
    
//从后插入的含参构造函数
    head = new Node<T>;
    Node<T> *rear = head;
    for (int i=0; i<n; i++) {
        Node<T>* s = new Node<T>;
        s->data = a[i];
        rear->next = s;
        rear = s;
    }
    rear->next = NULL;
}
//求单链表长度
template <class T>
int LinkList<T>::ListLength(){
    int num = 0;
    Node<T>* p = head->next;//
    while (p) {
        p = p->next;
        num++;
    }
    return num;
}
//按位查找
template <class T>
T LinkList<T>::Get(int pos){
    Node<T>* p = head->next;
    int j = 1;
    while (p && j<pos) {
        p = p->next;
        j++;
    }
    if (!p || j>pos) {
        cerr << "Illegal Input!\n";
        exit(1);
    }
    return p->data;
}
//按值查找
template <class T>
int LinkList<T>::Locate(T item){
    Node<T>* p = head->next;
    int j = 1;
    while(p&&p->data!=item){
        p = p->next;
        j++;
    }
    if(p){
        return j;
    }
    else{
        return 0;
    }
}
//遍历链表
template <class T>
void LinkList<T>::PrintLinkList(){
    Node<T>* p = head->next;
    while (p) {
        cout << p->data;
        p = p->next;
    }
}
//插入
template <class T>
void LinkList<T>::Insert(int i, T item){
    Node<T>* p = head;
    int j = 0;
    while (p && j<i-1) {
        p = p->next;
        j++;
    }
    if(!p){
        cerr << "Illegal input!\n";
        exit(1);
    }
    else{
        Node<T>* s = new Node<T>;
        s->data = item;
        s->next = p->next;
        p->next = s;
    }
}
//单链表的删除
template <class T>
T LinkList<T>::Delete(int i){
    Node<T>* p = head;
    int j = 0;
    while (p && j < i-1) {
        p = p->next;
        j++;
    }
    if (!p || !p->next) {
        cerr << "Illegal Input!\n";
        exit(1);
    }
    else{
        Node<T>* q = p->next;
        T x = q->data;
        p->next = q->next;
        delete q;
        return x;
    }
}
//析构函数
template <class T>
LinkList<T>::~LinkList<T>(){
    Node<T>* p = head;
    while (p) {
        Node<T>* q = new Node<T>;
        q = p;
        p = p->next;
        delete q;
    }
    head = NULL;
}
//原地逆置
template <class T>
void LinkList<T>::Invert(){
    Node<T>* p = head->next;
    head->next = NULL;
    while (p!=NULL) {
        Node<T>* q = p;
        p = p->next;
        q->next = head->next;
        head->next = q;
    }
}
//从中间将一个链表分成两段
template <class T>
void LinkList<T>::getMiddleNode(LinkList<T> &L){
    Node<T>* p1 = head;
    Node<T>* p2 = head->next;
    while (p2 != NULL) {
        p2 = p2->next;
        if(p2 != NULL){
            p2 = p2->next;
            p1 = p1->next;
        }
    }
    L.head = p1;
}
//合并两个已有链表
template <class T>
void LinkList<T>::Merge(LinkList<T> &L2){
    Node<T>* p1 = head->next;
    Node<T>* p2 = (L2.head)->next;
    Node<T>* p3 = head;
    while ((p1!=NULL)&&(p2!=NULL)) {
        if (p1->data < p2->data) {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
    }
    //将剩余的链表直接链入
    if (p1 != NULL) {
        p3->next = p1;
    }
    if (p2 != NULL) {
        p3->next = p2;
    }
    delete L2.head;
    L2.head = NULL;
}
//修改链表元素
template <class T>
void LinkList<T>::changeInfo(int i, T item)
{
    Node<T>* p = head->next;
    int j = 1;
    while (p && j<i) {
        p = p->next;
        j++;
    }
    if (!p || j>i) {
        cerr << "Illegal Input!\n";
        exit(1);
    }
    p->data = item;
}
//找倒数第K个元素
template <class T>
T LinkList<T>::GetTheLastK(int k)
{
    if (k == 0) {
        cerr << "Illegal input!\n";
        exit(1);
    }
    int count = 1;
    Node<T>* p = head->next;
    Node<T>* s = head->next;
    while (p->next != NULL) {
        p = p->next;
        count++;
        if(count < k) continue;
        s = s->next;
    }
    return s->data;
}
//判断是否有环
template <class T>
bool LinkList<T>::isLoop()
{
    Node<T>* fast = head->next;
    Node<T>* slow = head->next;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return true;
        }
    }
    
    if (fast == NULL || fast->next == NULL) {
        return false;
    }
}
//求环的长度
template <class T>
int LinkList<T>::LoopLen()
{
    if(!isLoop() || head == NULL) return -1;
    Node<T>* fast = head->next;
    Node<T>* slow = head->next;
    bool first = false;
    bool again = false;
    int len = 0;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow && again) break;
        
        if(fast == slow && !again) {
            first = true;
            again = true;
        }
        if(first) len++;
    }
    
    return len;
}
//末尾添加节点
template <class T>
void LinkList<T>::Append(T item)
{
    Node<T>* p = head;
    while (p->next!=NULL) {
        p = p->next;
    }
    Node<T>* s = new Node<T>;
    s->data = item;
    s->next = NULL;
    p->next = s;
}
