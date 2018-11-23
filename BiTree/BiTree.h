//
//  BiTree.h
//  BiTree
//
//  Created by Yucheng on 2018/11/6.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#ifndef BiTree_h
#define BiTree_h
using namespace std;
template <class T>
struct BiNode
{
    T data;
    BiNode<T> * lchild;
    BiNode<T> * rchild;
};

template <class T>
class BiTree
{
private:
    BiNode<T> * root;
    BiNode<T> * CreateByPre(vector<T> &pre, int &i, T neg);
    BiNode<T> * CreateByPreMid(vector<T> &pre, vector<T> &mid, int ipre, int imid, int n);
    BiNode<T> * Copy(BiNode<T> * p);
    void Free(BiNode<T> * p);
    void PreOrder(BiNode<T> * p);
    void InOrder(BiNode<T> * p);
    void PostOrder(BiNode<T> * p);
    int Count(BiNode<T> * p);
    int Height(BiNode<T> * p);
    BiNode<T> * Search(BiNode<T> * p, T e);
    BiNode<T> * SearchParent(BiNode<T> * p, BiNode<T> * child);
    
public:
    BiTree() { root = NULL;}
    BiTree(vector<T> &pre, T neg);
    BiTree(vector<T> &pre, vector<T> &mid);
    BiTree(BiTree<T> &tree);
    ~BiTree();
    void PreOrder();
    void InOrder();
    void PostOrder();
    void LevelOrder();
    int Count();
    int Height();
    BiNode<T> * Search(T e);
    BiNode<T> * SearchParent(BiNode<T> * child);
};

#endif /* BiTree_h */
