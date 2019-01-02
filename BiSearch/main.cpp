//
//  main.cpp
//  test
//
//  Created by Yucheng on 2018/10/25.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#include "string.h"
#define INFINITY 0x7fffffff
using namespace std;
int BiSearch_1(int a[], int n, int k);
int BiSearch_2(int a[], int low, int high, int k);


int main(int argc, const char * argv[]) {
    int test_case[] = {5, 13, 19, 21, 23, 29, 32, 35, 37, 42, 46, 49, 56};
    int len = 13;
    int n;
    while (1)
    {
        cout << "Please a number: ";
        cin >> n;
        cout << "Result of s1: " << BiSearch_1(test_case, len, n) << endl;
        cout << "Result of s2: " << BiSearch_2(test_case, 0, len-1, n) << endl;
    }
    return 0;
}
// 非递归二分查找
int BiSearch_1(int a[], int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if(a[mid] == k)
            return mid;
        else if(a[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
// 递归二分查找
int BiSearch_2(int a[], int low, int high, int k)
{
    if(low > high)
        return -1;
    else
    {
        int mid = (low + high) / 2;
        if (a[mid] == k)
            return mid;
        else
            if (a[mid] > k)
                return BiSearch_2(a, low, mid-1, k);
            else
                return BiSearch_2(a, mid+1, high, k);
    }
}
