//
//  HuffmanTree.h
//  HuffmanTree
//
//  Created by Yucheng on 2018/11/20.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#ifndef HuffmanTree_h
#define HuffmanTree_h
using namespace std;
struct HuffmanNode
{
    char data;
    double weight;
    int parent, lchild, rchild;
};

class HuffmanTree
{
private:
    vector< HuffmanNode > hufftree;
    int n;
    void SelectSmall(int &least, int &less, int i);
    
public:
    HuffmanTree(vector< HuffmanNode > &leafs);
    ~HuffmanTree();
    vector< int > GetCode(int i);
    string Decode(vector< int > &source);
};

#endif /* HuffmanTree_h */
