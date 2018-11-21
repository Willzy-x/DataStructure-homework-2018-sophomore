//
//  main.cpp
//  BothStack
//
//  Created by Yucheng on 2018/9/27.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#include "BothStack.cpp"
int main(int argc, const char * argv[]) {
    // insert code here...
    BothStack<int, 20> s;
    for (int i = 0; i<20; i++) {
        s.Push(i%2+1, i);
    }
    while (!s.Empty(1)) {
        cout << s.Pop(1) << " ";
    }
    cout << endl;
    while (!s.Empty(2)) {
        cout << s.Pop(2) << " ";
    }
    std::cout << "Hello, World!\n";
    return 0;
}
