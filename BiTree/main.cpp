//
//  main.cpp
//  BiTree
//
//  Created by Yucheng on 2018/11/6.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "BiTree.cpp"
using namespace std;
int Menu();

int main(int argc, const char * argv[]) {
    vector<string> vs = {"HYC1", "HYC2", "HYC3", "*", "*", "HYC4", "*", "*", "HYC5", "HYC6", "*", "*", "*"};
    BiTree<string> stree(vs, "*");
    stree.PreOrder();
    cout << endl;
    stree.InOrder();
    cout << endl;
    stree.PostOrder();
    cout << endl;
    cout << "Height: " << stree.Height() << "  #Nodes: " << stree.Count() << endl;
    /*a b d * * e * * c f * * *
    ifstream in;
    in.open("input_data.txt");
    if (!in ) {
        cout << "Cannot open input file!\n";
        exit(1);
    }
    
    vector<char> pre;
    vector<char> pre_;
    vector<char> mid_;
    BiNode<char> * t0 = new BiNode<char>;
    BiNode<char> * t1 = new BiNode<char>;
    while (1) {
        switch (Menu()) {
            case 1:
                int num1;
                char temp0;
                in >> num1;
                for (int i=0; i<num1; i++)
                {
                    in >> temp0;
                    pre.push_back(temp0);
                }
                static BiTree<char> p(pre, '*');
                break;
            case 2:
                int num2;
                char temp1;
                in >> num2;
                for (int i=0; i<num2; i++) {
                    in >> temp1;
                    pre_.push_back(temp1);
                }
                for (int i=0; i<num2; i++) {
                    in >> temp1;
                    mid_.push_back(temp1);
                }
                static BiTree<char> q(pre_, mid_);
                p = q;
                break;
            case 3:
                p.PreOrder();
                break;
            case 4:
                p.InOrder();
                break;
            case 5:
                p.PostOrder();
                break;
            case 6:
                p.LevelOrder();
                break;
            case 7:
                cout << "\t结点数为： " << p.Count() << "\n\t树的层数为： " << p.Height() << endl;
                break;
            case 8:
                char temp2;
                cout << "\t请输入要查找的字符： ";
                cin >> temp2;
                t0 = p.Search(temp2);
                if (t0 == NULL)
                    cout << "\t未查询到字符的结点。。。" << endl;
                else
                    cout << "\t包含需要查询的字符已存放。。。" << endl;
                break;
            case 9:
                cout << "\t在使用此功能前请先运行功能 #8 来寻找相应的结点。" << endl;
                t1 = p.SearchParent(t0);
                if (t1 == NULL)
                    cout << "\t未找到父结点。。。" << endl;
                else
                    cout << "\t父结点的数据为： " << t1->data << endl;
                break;
            default:
                exit(0);
                break;
        }
    }*/
    return 0;
}

// 菜单
int Menu()
{
    int choice;
    cout << "二叉树菜单：" << endl;
    cout << "1.输入二叉树的数据（先序）..." << endl;
    cout << "2.输入二叉树的数据（先序+中序）..." << endl;
    cout << "3.先序遍历二叉树..." << endl;
    cout << "4.中序遍历二叉树..." << endl;
    cout << "5.后序遍历二叉树..." << endl;
    cout << "6.层次遍历二叉树..." << endl;
    cout << "7.输出二叉树的结点总数和层数..." << endl;
    cout << "8.查找二叉树的数据..." << endl;
    cout << "9.查找二叉树的某结点的父结点..." << endl;
    cout << "输入你的选项：";
    cin >> choice;
    return choice;
}
