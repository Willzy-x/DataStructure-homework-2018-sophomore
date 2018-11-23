//
//  main.cpp
//  InBiThrTree
//
//  Created by Yucheng on 2018/11/13.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#include "InBiThrTree.cpp"
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    //a b d * * e * * c f * * *
    vector<char> a = {'a', 'b', 'd', '*', '*', 'e', '*', '*', 'c', 'f', '*', '*', '*'};
    InBiThrTree<char> t(a, '*');
    t.InThreaded();
    BiThrNode<char> * r = t.GetRoot();
    cout << "The parent node of ‘e’: " << t.GetParent(t.GetPrev(r))->data << endl;
//    t.Traverse();
    InBiThrTree<char> t0;
    std::cout << "Hello, World!\n";
    return 0;
}
