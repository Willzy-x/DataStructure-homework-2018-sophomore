//
//  InBiThrTree.cpp
//  InBiThrTree
//
//  Created by Yucheng on 2018/11/13.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include "InBiThrTree.h"
using namespace std;
// 先序构造二叉树---------------------------------------------------
template <class T>
BiThrNode<T> * InBiThrTree<T>::CreateByPre(vector<T> &pre, int &i, T sign)
{
    T e = pre[i++];
    if (e == sign)
    {
        return NULL;
    }
    BiThrNode<T> * p = new BiThrNode<T>;
    p->data = e;
    p->ltype = LINK;
    p->rtype = LINK;
    p->lchild = CreateByPre(pre, i, sign);
    p->rchild = CreateByPre(pre, i, sign);
    return p;
}
template <class T>
InBiThrTree<T>::InBiThrTree(vector<T> & pre, T sign)
{
    int i = 0;
    root = CreateByPre(pre, i, sign);
}
// 中序线索化算法----------------------------------------------------
template <class T>
void InBiThrTree<T>::InThreaded(BiThrNode<T> *&p, BiThrNode<T> *&prenode)
{
    if (p == NULL)
        return;
    InThreaded(p->lchild, prenode); // 对左子树建立线索
    if (p->lchild == NULL)
    {
        p->ltype = THREAD;
        p->lchild = prenode;
    }
    if (p->rchild == NULL)
        p->rtype = THREAD;
    if (prenode != NULL)
    {
        if (prenode->rtype == THREAD)
            prenode->rchild = p;
    }
    prenode = p;
    InThreaded(p->rchild, prenode); // 对右子树建立线索
}
template <class T>
void InBiThrTree<T>::InThreaded()
{
    BiThrNode<T> * prenode = NULL;
    InThreaded(root, prenode);
}
// 析构函数---------------------------------------------------------
template <class T>
void InBiThrTree<T>::Free(BiThrNode<T> *p)
{
    if (p == NULL)
        return;
    if (p->ltype == LINK) {
        Free(p->lchild);
    }
    if (p->rtype == LINK) {
        Free(p->rchild);
    } // 判断是否是连接而不是线索
    delete p;
}
template <class T>
InBiThrTree<T>::~InBiThrTree<T>()
{
    Free(root);
}
// 求后继结点--------------------------------------------------------
template <class T>
BiThrNode<T> * InBiThrTree<T>::GetNext(BiThrNode<T> *p)
{
    if (p->rtype == THREAD)
        return p->rchild;
    p = p->rchild;
    while (p->ltype == LINK)
        p = p->lchild;
    return p;
}
// 求前驱结点--------------------------------------------------------
template <class T>
BiThrNode<T> * InBiThrTree<T>::GetPrev(BiThrNode<T> *p)
{
    if (p->ltype == THREAD)
        return p->lchild;
    p = p->lchild;
    while (p->rtype == LINK)
        p = p->rchild;
    return p;
}
// 中序遍历中序线索二叉树-----------------------------------------------
template <class T>
void InBiThrTree<T>::Traverse()
{
    BiThrNode<T> * p = root;
    while (p->ltype == LINK)
        p = p->lchild; // 找到中序的第一个结点
    while (p != NULL)
    {
        cout << p->data << " ";
        p = GetNext(p);
    }
}
// 求父结点的算法------------------------------------------------------
template <class T>
BiThrNode<T> *  InBiThrTree<T>::GetParent(BiThrNode<T> *p)
{
    if (p == NULL)
        return NULL;
    BiThrNode<T> * parent;
    parent = p;
    while (parent->ltype == LINK) {
        p = p->lchild;
    }
    parent = parent->rchild;
    if (parent && parent->lchild == p) {
        return parent;
    }
    parent = p; // 重置
    while (parent->rtype == LINK) {
        p = p->rchild;
    }
    parent = parent->lchild;
    return parent;
}
// 获取根结点--------------------------------------
template <class T>
BiThrNode<T> * InBiThrTree<T>::GetRoot()
{
    return root;
}
