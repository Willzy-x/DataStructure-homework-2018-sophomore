//
//  main.cpp
//  SparseMatrix
//
//  Created by Yucheng on 2018/10/25.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "SparseMatrix.cpp"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int n1, n2; // 分别表示两个矩阵中非零元素的个数
    int r1, r2, c1, c2; // 分别表示两个矩阵的行数和列数
    
    // 文件输入
    ifstream in;
    in.open("input_data.txt");
    if (!in ) {
        cout << "Cannot open input file!\n";
        exit(1);
    }
    
    in >> n1 >> r1 >> c1; // 输入矩阵1的非零元素个数
    cout << "Confirm#: " << n1 << " " << endl;
    Triple<int> t1[n1]; // 输入矩阵1
    for (int i = 0; i < n1; i++) {
        in >> t1[i];
    }
    in >> n2 >> r2 >> c2; // 输入矩阵2的非零元素个数
    cout << "Confirm#: " << n2 << " " << endl;
    Triple<int> t2[n2]; // 输入矩阵2
    for (int i = 0; i < n2; i++) {
        in >> t2[i];
    }
    // 初始化矩阵
    SparseMatrix<int> m1(t1, r1, c1, n1);
    SparseMatrix<int> m2(t2, r2, c2, n2);
    cout << "Here's Matrix 1: " <<  endl;
    m1.print();
    cout << "Here's Matrix 2: " <<  endl;
    m2.print();
    
//    cout << "Sum of Matrix 1 and Matrix 2: " <<  endl;
//    (m1+m2+m1+m2).print();
    cout << "Product of Matrix 1 and Matrix 2: " << endl;
    (m1*m2*m1).print();
    return 0;
}
