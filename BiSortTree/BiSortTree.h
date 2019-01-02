//
//  BiSortTree.h
//  BiSortTree
//
//  Created by Yucheng on 2018/12/11.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#ifndef BiSortTree_h
#define BiSortTree_h
struct BiNode
{
    int key;
    BiNode * lchild, * rchild;
};

class BiSortTree
{
    BiNode * root;
    void Insert(BiNode * &ptr, int k);
    BiNode * Search(BiNode * ptr, int k);
    void Delete(BiNode * &ptr, int k);
    void Free(BiNode * ptr);
public:
    BiSortTree(int a[], int n);
    ~BiSortTree();
    void Insert(int k);
    bool Search(int k);
    void Delete(int k);
};
#endif /* BiSortTree_h */
