//
//  main.cpp
//  LinkList
//
//  Created by Yucheng on 2018/9/18.
//  Copyright © 2018年 Yucheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "LinkList.cpp"
#include "Student.h"
using namespace std;
void showResult();
int StudentMenu();

int main(int argc, const char * argv[]) {
    //文件输入
    ifstream in;
    in.open("File.txt");
    if(!in){
        cout << "Cannot open file!\n";
        exit(1);
    }
    //文件输出
    ofstream out;
    out.open("output1.txt");
    if (!out) {
        cout << "Cannot open file!\n";
        exit(1);
    }
    
    Student temp(0,"",0);//用于输入的对象
    Student s[5];//Linklist的构造函数的参数之一
    
    int t;
    int i, n = 5;
    string tem;
    while (true) {
        int choice = StudentMenu();
        switch (choice) {
            case 1:
                for (i=0; i<5; i++) {
                    in >> s[i];
                }
                static LinkList<Student> l1(s, 5);
                break;
            case 2:
                cout << "Please input the student your want to delete: ";
                cin >> t;
                cout << "This is the info that you want to delete: ";
                cout << l1.Delete(t);
                n--;
                break;
            case 3:
                cout << "Please input the student's ID your want to search: ";
                cin >> t;
                cout << l1.Get(t);
                break;
            case 4:
                cout << "Please input thr student's ID: ";
                cin >> i;
                cout << "\nPlease input the ID, gender and name: ";
                cin >> temp;
                cout << "Confirm: " << temp << endl;
                l1.changeInfo(i, temp);
                showResult();
                l1.PrintLinkList();
                break;
            case 5:
                showResult();
                l1.PrintLinkList();
                for (i=0; i<n; i++) {
                    out << l1.Get(i+1);
                }
                break;
            case 6:
                cout << "Please input the student's info: ";
                cin >> temp;
                l1.Append(temp);
                showResult();
                l1.PrintLinkList();
                n++;
                break;
            default:
                exit(0);
                break;
        }
    }
    return 0;
}
    /*
    int a[] = {0,1,4,7,9,11,13,29,31,40};
    int b[] = {2,3,5,8,10,12};
    LinkList<int> l1(a, 10);
    LinkList<int> l2(b, 6);
    LinkList<int> l0;
    cout << "This is the Length of l1: " << l1.ListLength() << endl;//链表长度示例
    cout << "This is the fourth element of l1: " << l1.Get(4) << endl;//查找示例
    cout << "Number 11 is at this position: " << l1.Locate(11) << endl;//定位示例
    l1.Insert(8, 16);
    cout << "Here's the result after Insertion:\n ";//插入示例
    l1.PrintLinkList();
    l1.Delete(8);
    cout << "Here's the result after Delete:\n ";//删除示例
    l1.PrintLinkList();
    showResult();
    cout << "Print: ";
    l1.PrintLinkList();//遍历示例
    l1.Merge(l2);//合并示例
    showResult();
    cout << "Merge: ";
    l1.PrintLinkList();
    showResult();
    l1.getMiddleNode(l0);
    cout << "Seperate from middle:  ";//分段示例
    l0.PrintLinkList();
     */
    

void showResult()
{
    cout << "\nHere's the result: \n";
}

int StudentMenu()
{
    int c;
    cout << "Welcome to the system, here're the options:\n";
    cout << "1.Create the List.\n";
    cout << "2.Delete a studdent.\n";
    cout << "3.Search a student.\n";
    cout << "4.Modify a stundent's info.\n";
    cout << "5.Print the list.\n";
    cout << "6.Append a student.\n";
    cout << "\tPlease enter your choice: ";
    cin >> c;
    return c;
}
