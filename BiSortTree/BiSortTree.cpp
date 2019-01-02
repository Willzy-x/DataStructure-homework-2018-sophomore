//
//  BiSortTree.cpp
//  BiSortTree
//
//  Created by Yucheng on 2018/12/11.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#include "BiSortTree.h"
using namespace std;

/* private functions */
void BiSortTree::Insert(BiNode *&ptr, int k)
{
    if (ptr == NULL)
    {
        ptr = new  BiNode;
        ptr->key = k;
        ptr->lchild = ptr->rchild = NULL;
    }
    else
    {
        if (k < ptr->key)
            Insert(ptr->lchild, k);
        else if (k > ptr->key)
            Insert(ptr->rchild, k);
        // 如果相等，无需操作
    }
}
//
BiNode* BiSortTree::Search(BiNode *ptr, int k)
{
    if (ptr == NULL)
        return NULL;
    else
    {
        if (ptr->key == k)
            return ptr;
        else if (k < ptr->key)
            return Search(ptr->lchild, k);
        else
            return Search(ptr->rchild, k);
    }
}
//
void BiSortTree::Delete(BiNode *&ptr, int k)
{
    if (ptr != NULL)
    {
        if (k < ptr->key) Delete(ptr->lchild, k);
        if (k > ptr->key) Delete(ptr->rchild, k);
        else
        {
            if (ptr->lchild != NULL && ptr->rchild != NULL)
            {
                BiNode * temp = ptr->lchild;
                while (temp->rchild != NULL)
                    temp = temp->rchild;
                ptr->key = temp->key;
                Delete(ptr->lchild, temp->key); // 删除原来被顶上去的结点
            }
            else
            {
                BiNode* temp = ptr;
                if (ptr->lchild == NULL)
                    ptr = ptr->rchild;
                if (ptr->rchild == NULL)
                    ptr = ptr->lchild;
                delete temp;
            }
        }
    }
}
// 析构
void BiSortTree::Free(BiNode *ptr)
{
    if (ptr->lchild == NULL && ptr->rchild)
        delete ptr;
    else
    {
        if (ptr->lchild != NULL)
            Free(ptr->lchild);
        if (ptr->rchild != NULL)
            Free(ptr->rchild);
    }
}
/* public functions */
void BiSortTree::Insert(int k)
{
    Insert(root, k);
}
//
BiSortTree::BiSortTree(int a[], int n)
{
    root = NULL;
    for (int i=0; i < n; i++)
        Insert(root, a[i]);
}
//
BiSortTree::~BiSortTree()
{
    Free(root);
}
//
bool BiSortTree::Search(int k)
{
    return Search(root, k) != NULL;
}
//
void BiSortTree::Delete(int k)
{
    Delete(root, k);
}
