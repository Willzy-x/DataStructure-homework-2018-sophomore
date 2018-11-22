//
//  main.cpp
//  KMP
//
//  Created by Yucheng on 2018/10/18.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#define MaxSize 100
void getnext(char *t);
int KMPmatching(char *s, char *t);

static int next1[MaxSize];//无法取名为next。
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    char s1[MaxSize] = "";
    char s2[MaxSize] = "";
    cout << "Please input the first string: ";
    cin.getline(s1, MaxSize);
    cout << "Please input the second string: ";
    cin.getline(s2, MaxSize);
    getnext(s2);
    int ans = KMPmatching(s1, s2);
    if (ans != -1)
        cout << "The first occurrence is: " << ans << "\n";
    else
        cout << "Cannot find the sub string\n";
    return 0;
}
// Candidate found by name lookup is 'std::__1::next'
// 产生歧义？
void getnext(char *t)
{
    int j = 0;
    int k = -1;
    int m = int(strlen(t));
    next1[0] = -1;
    while (j < m-1)
    {
        if (k == -1 || t[j] == t[k]) {
            j++;
            k++;
            next1[j] = k;
        }
        else {
            k = next1[k];
        }
    }
}

int KMPmatching(char *s, char *t)
{
    int i = 0;
    int j = 0;
    int n = int(strlen(s));
    int m = int(strlen(t));
    while (i < n && j < m) {
        if (s[i] == t[j] || j == -1) {
            i++;
            j++;
        }
        else {
            j = next1[j];
        }
    }
    if (j >= m)
        return i - m;
    else
        return -1;
}
