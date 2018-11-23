//
//  main.cpp
//  Recursion_eg
//
//  Created by Yucheng on 2018/9/30.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
using namespace std;
static int op[10];
int Fib(int n, int a, int b);
int Yanghui(int n, int k);
int shoot(int shot, int score);
inline void swap(int& a, int& b);
void Print(int n[], int s, int e);
char** Gray(int n);

int main(int argc, const char * argv[]) {//🦔
    // insert code here...
    int n;
    cout << "Please input your number: ";
    cin >> n;
    //斐波那契数列数列展示
    cout << "\nHere's the fib: " << Fib(n, 1, 1) << endl;
    //杨辉三角展示
    cout << "Here's the Yanghui:\n ";
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            int temp = Yanghui(i, j);
            if (temp != 0) {
                cout << temp << " ";
            }
        }
        cout << endl;
    }
    //打靶展示
    cout << "Shooting results:" << shoot(10, 90) << endl;
    //全排列展示
    for (int k=0; k<4; k++) {
        op[k] = k+1;
    }
    cout << "output: ";
    Print(op, 0, 3);
    //格雷码展示
    cout << "\nPlease input gray code number: ";
    int x;
    cin>>x;
    int m = 1;
    for(int i=0; i<x; i++)
        m*=2;
    char** p = Gray(x);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<x; j++)
        {
            cout<<p[i][j];
            
        }
        cout<<endl;
    }
    return 0;
}

//递归实现斐波那契数列
int Fib(int n, int a, int b)
{
    if (n > 2) {
        return Fib(n-1, a+b, a);
    }
    return a;
}
//杨辉三角形的递归
int Yanghui(int n, int k)
{
    if (k == 1 || k == n)
    {
        return 1;
    }
    if (k < 1 || k > n) {
        return 0;
    }
    else
    {
        return Yanghui(n-1, k-1) + Yanghui(n-1, k);
    }
}
//打靶
int shoot(int shot, int score)
{
    if (score < 0|| score > shot * 10)
    {
        return 0;
    }
    if ( shot == 0)
    {
        return 1;
    }
    else
    {
        int temp = 0;
        for (int i = 0; i <= 10; i++) {
            temp += shoot(shot - 1, score-i);
        }
        return temp;
    }
}
//交换函数
inline void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
//打印全排列
void Print(int n[], int s, int e)
{
    if(s == e)
    {
        for(int i=0; i <= e; i++)
            cout << n[i];
        cout << endl;
    }
    else
    {
        for (int i=s; i <= e; i++) {
            swap(n[s], n[i]);
            Print(n, s+1, e);
            swap(n[s], n[i]);
        }
    }
}
//递归实现格雷码
char** Gray(int n)
{
    int temp = 1;
    for (int i=0; i<n; i++)
        temp*=2;//n位格雷码一共有2^n个码字
    char **graycode = new char*[temp];//动态申请2^n *n大小的数组，存放格雷码
    for (int i=0; i<temp; i++)
    {
        graycode[i]=new char[n];//动态申请二维数组
    }
    if (n==1)
    {//递归终止条件
        graycode[0][0]='0';
        graycode[1][0]='1';
        return graycode;
    }
    char** p = Gray(n-1);
    for (int i=0; i<temp/2; i++)
    {
        graycode[i][0] = '0';
        graycode[i+temp/2][0] = '1';
        for (int j=1; j<n; j++) {
            graycode[i][j] = p[i][j-1];
            graycode[temp-i-1][j] = p[i][j-1];
        }
    }
    return graycode;
}

