//
//  main.cpp
//  Ds2
//
//  Created by Yucheng on 2018/9/12.
//  Copyright © 2018年 Yucheng. All rights reserved.
//
#include <fstream>
#include <iostream>
#include "SeqList.cpp"
#include "Good.h"
using namespace std;
void showPrompt();
void showResult();
int  GoodsMenu();

int main(){
    //文件输入
    ifstream in;
    in.open("input1.txt", ios::in);
    if(!in){
        cout << "Cannot open file!\n";
        return 1;
    }
    string line;
    //文件输出
    ofstream out;
    out.open("output.txt",ios::out);
    if(!out){
        cout << "Cannot open file!\n";
        return 1;
    }
    
    
    int id, i;
    Good goods[5];
    SeqList<Good, 10> sg;
    while (1) {
        int choice = GoodsMenu();
        if (choice == 0) {
            break;
        }
        switch (choice) {
            case 1: cout << "Please input the ID, price, storeage and name: ";
                for (i=0; i<5; i++) {
                    in >> goods[i];
                    sg.Insert(sg.ListLength()+1, goods[i]);
                }
                cout << "Insertion succeeded!\n";
                break;
            case 2: cout << "Please input the good's ID that you want inquire about: ";
                cin >> id;
                cout << "The good's name is: " << sg.Get(id).getName() << endl;
                cout << "The good's price is: " << sg.Get(id).getPrice() << endl;
                break;
            case 3: cout << "Please input the good's ID and price: ";
                int order, price;
                cin >> order >> price;
                sg.Get(order).changePrice(price);
                break;
            case 4: cout << "Current goods' info: \n";
                sg.PrintSeqList();
                break;
            case 5: cout << "Here's the sorted list: \n";
                sg.InsertionSort();
                sg.PrintSeqList();
                for (i=0; i<sg.ListLength(); i++) {
                    out << sg.Get(i+1);
                }
                break;
            default:
                exit(0);
                break;
        }
    }
//    //商品示例
//
//    Good gd[5] = {
//      Good(10, "Apple", 10, 20),
//      Good(9, "Banana", 20, 30),
//      Good(3, "Coffee", 30, 40),
//      Good(7, "Laptop", 4999.9, 100),
//      Good(4, "Chocolate", 50, 200)
//    };
//    SeqList<Good, 50> seq1(gd, 5);
//    int a;
//    cout << "\nPlease input the ID of the good that you want to modify: ";
//    cin >> a;
//    Good temp(a,"",0,0);
//    seq1.modify(temp);//按商品代号修改商品库存展示
//    seq1.PrintSeqList();//打印展示
//    seq1.DeleteAppointed(Good(3,"cof",10,20));//删除指定编号展示
//    seq1.InsertionSort();//排序展示
//    seq1.PrintSeqList();
//    //int 示例
//    int arr[] = {2,4,5,6,3,3,4,6,7,4};
//    int arr2[] = {3,4,5,2,37,9};
//    int arr3[16];
//    SeqList<int, 100> seq0(arr2, 6);
//    SeqList<int, 100> seq(arr, 10);
//    SeqList<int, 100> seqt(arr3, 16);
//    cout << "This is a DEMO:\n";
//    showPrompt();
//    int choice;
//    while (true) {
//        cout << "\n\tPlease input your choice: ";
//        cin >> choice;
//        int pos, item;
//        switch (choice) {
//            case 1://:D
//                cout << "\nThe length is: " << seq.ListLength() << endl;
//                break;
//            case 2://:D
//                cout << "\nPlease input the position: ";
//                cin >> pos;
//                cout << "\n" << seq.Get(pos) << endl;
//                break;
//            case 3://:D
//                cout << "\nPlease input the item ";
//                cin >> item;
//                cout << "\n" << seq.Locate(item) << endl;
//                break;
//            case 4://:D
//                seq.PrintSeqList();
//                cout << endl;
//                break;
//            case 5://:D
//                cout << "\nPlease input your data you want to insert(int pos, T data): ";
//                cin >> pos >> item;
//                seq.Insert(pos, item);
//                showResult();
//                seq.PrintSeqList();
//                cout << endl;
//                break;
//            case 6://:D
//                cout << "\nPlease input the position of the item you want to delete: ";
//                cin >> pos;
//                cout << "Confirm: " << seq.Delete(pos) << endl;
//                break;
//            case 7://:D
//                cout << "\nYou are going to delete the smallest data: ";
//                cout << "Confirm: " << seq.DeleteMin() << endl;
//                showResult();
//                seq.PrintSeqList();
//                cout << endl;
//                break;
//            case 8://:D
//                cout << "\nPlease input the item you want to delete: ";
//                cin >> item;
//                seq.DeleteAppointed(item);
//                showResult();
//                seq.PrintSeqList();
//                break;
//            case 9://:D
//                cout << "\nPlease input the range of items you want to delete(low, high): ";
//                int low, high;
//                cin >> low >> high;
//                seq.DeleteRange(low, high);
//                showResult();
//                seq.PrintSeqList();
//                break;
//            case 10://:D
//                cout << "\nRearrange the Sequence by the first item: ";
//                seq.Sorting();
//                showResult();
//                seq.PrintSeqList();
//                break;
//            case 11://:D
//                seq.InsertionSort();
//                cout << "\nHere is the sorted sequence: ";
//                seq.PrintSeqList();
//                cout << endl;
//                break;
//            case 12://:D
//                showResult();
//                seq.DeleteRepetition();
//                seq.PrintSeqList();
//                cout << endl;
//                break;
//            case 13://Merge with seq0
//                showResult();
//                seq.InsertionSort();
//                seq0.InsertionSort();
//                seq.Merge(seq0).PrintSeqList();
//                break;
//            case 14:
//                exit(0);
//                break;
//            default:
//                exit(0);
//                break;
//        }
//    }
    return 0;
}

void showPrompt(){
    cout << "Here's your choices:\n";
    cout << "1. Get the length of the sequence.\n";
    cout << "2. Get item according to position.\n";
    cout << "3. Get the positon according to item.\n";
    cout << "4. Print the sequece\n";
    cout << "5. Insert the item to the appointed position.\n";
    cout << "6. Delete the item according to position.\n";
    cout << "7. Delete the smallest item.\n";
    cout << "8. Delete the appointed items.\n";
    cout << "9. Delete the items according to a range (s,t).\n";
    cout << "10.Sort the sequence by the first item.\n";
    cout << "11.Sort the sequence ascendingly.\n";
    cout << "12.Delete the repeated items.\n";
    cout << "13.Merge 2 List.\n";
    cout << "14.Exit the program.\n";
}

void showResult(){
    cout << "\nHere's the result:\n";
}

int GoodsMenu(){
    int n;
    cout << "Here's your choices:\n";
    cout << "1. Input the Good's info: \n";
    cout << "2. Get the item according to its ID:\n";
    cout << "3. Change the price of the good(input ID and price). \n";
    cout << "4. Print the Goods one by one.\n";
    cout << "5. Sort the list according to its ID.\n";
    cout << "Please enter your choice: ";
    cin >> n;
    return n;
}
