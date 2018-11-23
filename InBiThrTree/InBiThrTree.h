
//
//  InBiThrTree.h
//  InBiThrTree
//
//  Created by Yucheng on 2018/11/13.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#ifndef InBiThrTree_h
#define InBiThrTree_h
using namespace std;
enum BiThrNodeType {LINK, THREAD};
template <class T>
struct BiThrNode
{
    BiThrNodeType ltype, rtype;
    T data;
    BiThrNode<T> * lchild;
    BiThrNode<T> * rchild;
};

template <class T>
class InBiThrTree
{
private:
    BiThrNode<T> * root;
    BiThrNode<T> * CreateByPre(vector<T> & pre, int &i, T sign);
    void InThreaded(BiThrNode<T> * &p, BiThrNode<T> * &prenode);
    void Free(BiThrNode<T> * p);
    
public:
    InBiThrTree() { root = NULL; }
    InBiThrTree(vector<T> & pre, T sign); // 先序创建二叉树
    void InThreaded();
    ~InBiThrTree();
    BiThrNode<T> * GetNext(BiThrNode<T> * p);
    BiThrNode<T> * GetPrev(BiThrNode<T> * p);
    void Traverse();
    BiThrNode<T> * GetParent(BiThrNode<T> * p);
    BiThrNode<T> * GetRoot();
};

#endif /* InBiThrTree_h */
