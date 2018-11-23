//
//  HuffmanTree.cpp
//  HuffmanTree
//
//  Created by Yucheng on 2018/11/20.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include "HuffmanTree.h"
using namespace std;
// 选取权重最小的两个数据
void HuffmanTree::SelectSmall(int &least, int &less, int i)
{
    least = less = i-1;
    for (int j=0; j < i; j++)
    {
        if (hufftree[j].weight <= hufftree[least].weight && hufftree[j].parent == -1)
        {
            least = j;
        }
    }
    if (least == i-1)
        less--;
    for (int j=0; j < i; j++)
    {
        if (hufftree[j].weight <= hufftree[less].weight && j != least && hufftree[j].parent == -1)
        {
            less = j;
        }
    }
}
// 构造函数----------------------------------------------------------
HuffmanTree::HuffmanTree(vector< HuffmanNode > &leafs)
{
    n = int(leafs.size());
    hufftree.resize(2 * n - 1);
    for (int i=0; i<n; i++)
    {
        hufftree[i].data = leafs[i].data;
        hufftree[i].weight = leafs[i].weight;
        hufftree[i].parent = hufftree[i].lchild = hufftree[i].rchild = -1;
    }
    for (int i=n; i<(2 * n - 1); i++)
    {
        int least, less;
        SelectSmall(least, less, i);
        hufftree[least].parent = hufftree[less].parent = i;
        hufftree[i].parent = -1;
        hufftree[i].lchild = least;
        hufftree[i].rchild = less;
        hufftree[i].weight = hufftree[least].weight + hufftree[less].weight;
    }
}
// 析构函数----------------------------------------------------------
HuffmanTree::~HuffmanTree()
{
    hufftree.clear();
}
// 编码算法----------------------------------------------------------
vector<int> HuffmanTree::GetCode(int i)
{
    vector<int> code;
    int p = i;
    int parent = hufftree[i].parent;
    while (parent != -1)
    {
        if (hufftree[parent].lchild == p)
            code.insert(code.begin(), 0);
        else
            code.insert(code.begin(), 1);
        p = parent;
        parent = hufftree[parent].parent;
    }
    return code;
}
// 译码算法 ----------------------------------------------------------
string HuffmanTree::Decode(vector<int> &source)
{
    string target = "";
    int root = int(hufftree.size() - 1);
    int p = root;
    for (int i=0; i <source.size(); i++) {
        if (source[i] == 0)
            p = hufftree[p].lchild;
        else
            p = hufftree[p].rchild;
        if (hufftree[p].lchild == -1 && hufftree[p].rchild == -1)
        {
            target = target +hufftree[p].data;
            p = root;
        }
    }
    return target;
}
