//
//  BiTree.cpp
//  BiTree
//
//  Created by Yucheng on 2018/11/6.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#include "BiTree.h"
#include "SeqQueue.cpp"
#include <vector>
using namespace std;

// 先序构造---------------------------------
template <class T>
BiNode<T> * BiTree<T>::CreateByPre(vector<T> &pre, int &i, T neg)
{
    T e = pre[i++];
    if (e == neg) {
        return NULL;
    }
    BiNode<T> * p = new BiNode<T>;
    p->data = e;
    p->lchild = CreateByPre(pre, i, neg);
    p->rchild = CreateByPre(pre, i, neg);
    return p;
}
template <class T>
BiTree<T>::BiTree(vector<T> &pre, T neg)
{
    int i = 0;
    root = CreateByPre(pre, i, neg);
}
// 双序列构造二叉树----------------------------
template <class T>
BiNode<T> * BiTree<T>::CreateByPreMid(vector<T> &pre, vector<T> &mid, int ipre, int imid, int n)
{
    if (n == 0)
        return NULL;
    BiNode<T> * p = new BiNode<T>;
    int i;
    p->data = pre[ipre];
    for (i=0; i<n; i++) {
        if (pre[ipre] == mid[imid + i])
            break;
    }
    p->lchild = CreateByPreMid(pre, mid, ipre+1, imid, i);
    p->rchild = CreateByPreMid(pre, mid, ipre+1+i, imid+1+i, n-1-i);
    return p;
}
template <class T>
BiTree<T>::BiTree(vector<T> &pre, vector<T> &mid)
{
    int n = pre.size();
    root = CreateByPreMid(pre, mid, 0, 0, n);
}
// 复制函数-----------------------------------
template <class T>
BiNode<T> * BiTree<T>::Copy(BiNode<T> *p)
{
    if (p == NULL)
        return NULL;
    BiNode<T> * q = new BiNode<T>;
    q->data = p->data;
    q->lchild = Copy(p->lchild);
    q->rchild = Copy(p->rchild);
    return q;
}
template <class T>
BiTree<T>::BiTree(BiTree<T> &tree)
{
    root = Copy(tree.root);
}
// 析构函数------------------------------------
template <class T>
void BiTree<T>::Free(BiNode<T> *p)
{
    if (p == NULL)
        return;
    Free(p->lchild);
    Free(p->rchild);
    delete p;
}
template <class T>
BiTree<T>::~BiTree<T>()
{
    Free(root);
}
// 先序遍历-------------------------------------
template <class T>
void BiTree<T>::PreOrder(BiNode<T> * p)
{
    if (p == NULL) return;
    cout << p->data;
    PreOrder(p->lchild);
    PreOrder(p->rchild);
}
template <class T>
void BiTree<T>::PreOrder()
{
    PreOrder(root);
    cout << endl;
}
// 中序遍历-------------------------------------
template <class T>
void BiTree<T>::InOrder(BiNode<T> * p)
{
    if (p == NULL) return;
    InOrder(p->lchild);
    cout << p->data;
    InOrder(p->rchild);
}
template <class T>
void BiTree<T>::InOrder()
{
    InOrder(root);
    cout << endl;
}
// 后序遍历--------------------------------------
template <class T>
void BiTree<T>::PostOrder(BiNode<T> * p)
{
    if (p == NULL) return;
    PostOrder(p->lchild);
    PostOrder(p->rchild);
    cout << p->data;
}
template <class T>
void BiTree<T>::PostOrder()
{
    PostOrder(root);
    cout << endl;
}
// 层次遍历---------------------------------------
template <class T>
void BiTree<T>::LevelOrder()
{
    if (root == NULL)
        return;
    SeqQueue<BiNode<T>*, 50>  Q;
    Q.EnQueue(root);
    while (!Q.Empty()) {
        BiNode<T> * p = Q.DeQueue();
        cout << p->data;
        if (p->lchild != NULL)
            Q.EnQueue(p->lchild);
        if (p->rchild != NULL)
            Q.EnQueue(p->rchild);
    }
    cout << endl;
}
// 计算树的总结点------------------------------------
template <class T>
int BiTree<T>::Count(BiNode<T> * p)
{
    if (p == NULL) 
        return 0;
    int left = Count(p->lchild);
    int right = Count(p->rchild);
    return left + right + 1;
}
template <class T>
int BiTree<T>::Count()
{
    return Count(root);
}
// 计算树的高度---------------------------------------
template <class T>
int BiTree<T>::Height(BiNode<T> * p)
{
    if (p == NULL)
        return 0;
    int left = Height(p->lchild);
    int right = Height(p->rchild);
    return ((left > right ? left : right) + 1);
}
template <class T>
int BiTree<T>::Height()
{
    return Height(root);
}
// 查找算法-------------------------------------------
template <class T>
BiNode<T> * BiTree<T>::Search(BiNode<T> *p, T e)
{
    if (p == NULL)
        return NULL;
    if (p->data == e)
        return p;
    BiNode<T> * q = Search(p->lchild, e);
    if (q != NULL)
        return q;
    return Search(p->rchild, e);
}
template <class T>
BiNode<T> * BiTree<T>::Search(T e)
{
    return Search(root, e);
}
// 查找结点的父结点-------------------------------------
template <class T>
BiNode<T> * BiTree<T>::SearchParent(BiNode<T> *p, BiNode<T> *child)
{
    if (p == NULL || child == NULL)
        return NULL;
    if (p->lchild == child || p->rchild == child)
        return p;
    BiNode<T> * q = SearchParent(p->lchild, child);
    if (q != NULL)
        return q;
    return SearchParent(p->rchild, child);
}
template <class T>
BiNode<T> * BiTree<T>::SearchParent(BiNode<T> *child)
{
    return SearchParent(root, child);
}
// --------------------------------------------------

