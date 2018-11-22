//
//  SparseMatrix.cpp
//  SparseMatrix
//
//  Created by Yucheng on 2018/10/25.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <stdio.h>
#include "SparseMatrix.h"
#include <iostream>
#include <vector> // 需要独立include
using namespace std;
// 无参构造函数
template <class T >
SparseMatrix<T>::SparseMatrix()
{
    rows = 0; cols = 0; // 行数、列数
    num = 0; // 非零元素个数
}
// 含参构造函数
template <class T>
SparseMatrix<T>::SparseMatrix(Triple<T> * tlist, int rs, int cs, int n)
{
    triList.reserve(n); // 预先分配空间
    for (int i = 0; i < n; i++) {
        triList[i] = tlist[i];
    }
    rows = rs;
    cols = cs;
    num = n;
}
// 转置矩阵
template <class T>
void SparseMatrix<T>::trans(SparseMatrix<T> &B) {
    B.rows = cols;
    B.cols = rows;
    B.num = num;
    B.triList.resize(num);
    if(num == 0)
        return;
    
    vector<int> cnum(cols, 0);
    vector<int> copt(cols, 0);
    for (int i = 0; i < num; i++) {
        cnum[triList[i].c]++;
    } // 处理每列多少个元素数组
    
    for (int i = 1; i < cols; i++) {
        copt[i] = cnum[i-1] + copt[i-1];
    } // 处理每列首元素位置数组
    
    for (int i = 0; i < num; i++) {
        int col = triList[i].c; // 当前元素的列位置
        int q = copt[col]; // 当前列的这一元素应该在的位置
        B.triList[q].r = triList[i].c;
        B.triList[q].c = triList[i].r;
        B.triList[q].elem = triList[i].elme;
        copt[col]++;
    }
}
// 矩阵加法
template <class T>
SparseMatrix<T>& SparseMatrix<T>::plus(SparseMatrix<T> & B)
{
    if (B.rows != rows || B.cols != cols) {
        cerr << "#rows or #columns are not equal!\n";
        exit(1);
    }
    vector<int> posA(num);
    vector<int> posB(B.num);
    for (int i = 0; i < num; i++) {
        int ri = triList[i].r;
        int cj = triList[i].c;
        posA[i] = ri * rows + cj;
    } // 计算A矩阵元素应出现的位置
    for (int i = 0; i < B.num; i++) {
        int ri = B.triList[i].r;
        int cj = B.triList[i].c;
        posB[i] = ri * B.rows + cj;
    } // 计算B矩阵元素应出现的位置
    SparseMatrix<T> * temp = new SparseMatrix<T>;
    temp->rows = rows;
    temp->cols = cols;
    /*
    预分配空间出现问题
    temp.triList.resize(num + B.num); // 最多有 n1 + n2 个非零元素
     */
    int a = 0, b = 0;
    while (a < num && b < B.num)
    {
        if (posA[a] < posB[b]) { // 判断两个矩阵的元素的位置前后
            temp->triList.push_back(triList[a]); // 在前面的元素被放入新矩阵
            a++; // 被放入的那个矩阵往后迭代
            temp->num++;
        }
        else if (posA[a] == posB[b]) { // 若两个矩阵的位置一样
            Triple<T> nt;
            nt.r = triList[a].r;
            nt.c = triList[a].c;
            nt.elem = triList[a].elem + B.triList[b].elem;
            temp->triList.push_back(nt);
            a++; b++; // 同时往后迭代
            temp->num++;
        }
        else {
            temp->triList.push_back(B.triList[b]);
            b++;
            temp->num++;
        }
    }
    while (a != num) { // 将未比较的A矩阵元素放入新矩阵
        temp->triList.push_back(triList[a]);
        a++;
        temp->num++;
    }
    while (b != B.num) { // 将未必较的B矩阵元素放入新矩阵
        temp->triList.push_back(B.triList[b]);
        b++;
        temp->num++;
    }
    
    this->triList = temp->triList;
    this->num = temp->num;
    return *this;
}
// 矩阵乘法
template <class T>
SparseMatrix<T>& SparseMatrix<T>::mult(SparseMatrix<T> & B)
{
    if (cols != B.rows) {
        cerr << "Cannot Multiply!\n";
        exit(1);
    }
    SparseMatrix<T> * temp = new SparseMatrix<T>;
    temp->rows = rows;
    temp->cols = B.cols;
    T tem[B.cols];
    vector<int> Brnum(B.rows, 0);
    vector<int> Bropt(B.rows, 0);
    for (int i = 0; i < B.num; i++) {
        Brnum[B.triList[i].r]++;
    } // 计算B矩阵中每行的元素个数
    for (int i = 1; i < B.rows; i++) {
        Bropt[i] = Bropt[i-1] + Brnum[i-1];
    } // 计算B矩阵每行首个非零元素的个数
    int r = 0; // 计算新矩阵中的非零元素个数
    int p = 0; // 指示当前A矩阵中非零元素的位置
    int q = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            tem[j] = 0;
        }
        while (i == triList[p].r) { // 如果A矩阵中此元素的行标是i
            int k = triList[p].c; // 获取A矩阵中第p个非零元素的列值
            int t;
            if (k < B.rows)
                t = Bropt[k+1]; // 在相应的行中查找
            else
                t = B.num; // 特殊情况， 需要在Bropt[B.rows-1] 到 B.num 之间去查找
            // 将B中第k行的每一列非零元素与A中非零元素记录到累加器中
            for (q = Bropt[k]; q < t; q++) { // 在B矩阵的k行中查找非零元素
                int j = B.triList[q].c; // 记录下非零元素的列标
                tem[j] += triList[p].elem * B.triList[q].elem;
            }
            p++; // 迭代A矩阵中下一个元素
        }
        // 此时A矩阵中一行的乘法完成
        for (int j = 0; j < B.cols; j++) {
            if (tem[j] != 0) {
                Triple<T> nt;
                nt.r = i; nt.c = j;
                nt.elem = tem[j];
                temp->triList.push_back(nt);
                r++;
            }
        }
    }
    temp->num = r;
    // 将temp回传给原矩阵， 在函数退出后temp将被释放
    this->triList = temp->triList;
    this->num = temp->num;
    this->rows = temp->rows;
    this->cols = temp->cols;
    
    return *this;
}

// 打印稀疏矩阵
template <class T>
void SparseMatrix<T>::print()
{
    vector<int> pos(num);
    for (int i = 0; i < num; i++) {
        int ri = triList[i].r;
        int cj = triList[i].c;
        pos[i] = ri * rows + cj;
    } // 计算矩阵元素应出现的位置
    int count  = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i * rows + j == pos[count]){ // 计算位置是否匹配
                cout << triList[count].elem << " ";
                count++; // 察看下一元素是否匹配
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
// 加法重载
template <class T>
SparseMatrix<T>& SparseMatrix<T>::operator+(SparseMatrix<T> & B)
{
    if (B.rows != rows || B.cols != cols) {
        cerr << "#rows or #columns are not equal!\n";
        exit(1);
    }
    vector<int> posA(num);
    vector<int> posB(B.num);
    for (int i = 0; i < num; i++) {
        int ri = triList[i].r;
        int cj = triList[i].c;
        posA[i] = ri * rows + cj;
    } // 计算A矩阵元素应出现的位置
    for (int i = 0; i < B.num; i++) {
        int ri = B.triList[i].r;
        int cj = B.triList[i].c;
        posB[i] = ri * B.rows + cj;
    } // 计算B矩阵元素应出现的位置
    SparseMatrix<T> * temp = new SparseMatrix<T>;
    temp->rows = rows;
    temp->cols = cols;
    /*
     预分配空间出现问题
     temp.triList.resize(num + B.num); // 最多有 n1 + n2 个非零元素
     */
    int a = 0, b = 0;
    while (a < num && b < B.num)
    {
        if (posA[a] < posB[b]) { // 判断两个矩阵的元素的位置前后
            temp->triList.push_back(triList[a]); // 在前面的元素被放入新矩阵
            a++; // 被放入的那个矩阵往后迭代
            temp->num++;
        }
        else if (posA[a] == posB[b]) { // 若两个矩阵的位置一样
            Triple<T> nt;
            nt.r = triList[a].r;
            nt.c = triList[a].c;
            nt.elem = triList[a].elem + B.triList[b].elem;
            temp->triList.push_back(nt);
            a++; b++; // 同时往后迭代
            temp->num++;
        }
        else {
            temp->triList.push_back(B.triList[b]);
            b++;
            temp->num++;
        }
    }
    while (a != num) { // 将未比较的A矩阵元素放入新矩阵
        temp->triList.push_back(triList[a]);
        a++;
        temp->num++;
    }
    while (b != B.num) { // 将未必较的B矩阵元素放入新矩阵
        temp->triList.push_back(B.triList[b]);
        b++;
        temp->num++;
    }
    
    this->triList = temp->triList;
    this->num = temp->num;
    return *this;
}

// 乘法重载
template <class T>
SparseMatrix<T>& SparseMatrix<T>::operator*(SparseMatrix<T> & B)
{
    if (cols != B.rows) {
        cerr << "Cannot Multiply!\n";
        exit(1);
    }
    SparseMatrix<T> * temp = new SparseMatrix<T>;
    temp->rows = rows;
    temp->cols = B.cols;
    T tem[B.cols];
    vector<int> Brnum(B.rows, 0);
    vector<int> Bropt(B.rows, 0);
    for (int i = 0; i < B.num; i++) {
        Brnum[B.triList[i].r]++;
    } // 计算B矩阵中每行的元素个数
    for (int i = 1; i < B.rows; i++) {
        Bropt[i] = Bropt[i-1] + Brnum[i-1];
    } // 计算B矩阵每行首个非零元素的个数
    int r = 0; // 计算新矩阵中的非零元素个数
    int p = 0; // 指示当前A矩阵中非零元素的位置
    int q = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            tem[j] = 0;
        }
        while (i == triList[p].r) { // 如果A矩阵中此元素的行标是i
            int k = triList[p].c; // 获取A矩阵中第p个非零元素的列值
            int t;
            if (k < B.rows)
                t = Bropt[k+1]; // 在相应的行中查找
            else
                t = B.num; // 特殊情况， 需要在Bropt[B.rows-1] 到 B.num 之间去查找
            // 将B中第k行的每一列非零元素与A中非零元素记录到累加器中
            for (q = Bropt[k]; q < t; q++) { // 在B矩阵的k行中查找非零元素
                int j = B.triList[q].c; // 记录下非零元素的列标
                tem[j] += triList[p].elem * B.triList[q].elem;
            }
            p++; // 迭代A矩阵中下一个元素
        }
        // 此时A矩阵中一行的乘法完成
        for (int j = 0; j < B.cols; j++) {
            if (tem[j] != 0) {
                Triple<T> nt;
                nt.r = i; nt.c = j;
                nt.elem = tem[j];
                temp->triList.push_back(nt);
                r++;
            }
        }
    }
    temp->num = r;
    // 将temp回传给原矩阵， 在函数退出后temp将被释放
    this->triList = temp->triList;
    this->num = temp->num;
    this->rows = temp->rows;
    this->cols = temp->cols;
    
    return *this;
}
