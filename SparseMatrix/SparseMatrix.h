//
//  SparseMatrix.h
//  SparseMatrix
//
//  Created by Yucheng on 2018/10/25.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#ifndef SparseMatrix_h
#define SparseMatrix_h
#include <iostream>
using namespace std;
// 三元组数据定义
template <class T>
struct Triple {
    int r, c;
    T elem;
    
    friend istream& operator >> (istream& in, Triple <T>& t) {
        in >> t.r >> t.c >> t.elem;
        return in;
    }
};
// 稀疏矩阵定义
template <class T>
class SparseMatrix {
    vector< Triple<T> > triList;
    int rows, cols, num;
    
public:
    SparseMatrix();
    SparseMatrix(Triple <T> * tlist, int rs, int cs, int n);
    void trans(SparseMatrix & B);
    SparseMatrix& plus(SparseMatrix & B);
    SparseMatrix& mult(SparseMatrix & B);
    void print();
    SparseMatrix& operator+(SparseMatrix & B);
    SparseMatrix& operator*(SparseMatrix & B);
};

#endif /* SparseMatrix_h */
