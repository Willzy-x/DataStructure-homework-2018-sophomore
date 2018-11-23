//
//  main.cpp
//  HuffmanTree
//
//  Created by Yucheng on 2018/11/20.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include "HuffmanTree.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<HuffmanNode> l = {{'A', 2, -1, -1, -1},
        {'C', 4, -1, -1, -1},
        {'B', 5, -1, -1, -1},
        {'D', 7, -1, -1, -1}
    };
    HuffmanTree h0(l);
    vector<int> code3 = h0.GetCode(0);
    for (int i=0; i<3; i++) {
        cout << code3[i] << " ";
    }
    return 0;
}
