//
//  main.cpp
//  BiSortTree
//
//  Created by Yucheng on 2018/12/11.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#include "BiSortTree.h"
using namespace std;
int menu();

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {61, 86, 70, 53, 67, 52, 88}, n;
    BiSortTree b0(a, 7);
    while (1)
    {
        switch (menu())
        {
            case 1:
                cout << "You want to insert: ";
                cin >> n;
                b0.Insert(n);
                cout << "Finished" << endl;
                break;
            case 2:
                cout << "You want to delete: ";
                cin >> n;
                b0.Delete(n);
                cout << "Finished" << endl;
                break;
            case 3:
                cout << "Please input the number that you want to look up: ";
                cin >> n;
                cout << "Number " << n << " exists: ";
                if (b0.Search(n))
                    cout << "True" << endl;
                else
                    cout << "False" << endl;
                break;
            default:
                exit(0);
        }
    }
    // std::cout << "Hello, World!\n";
    return 0;
}

int menu()
{
    int choice;
    cout << "Here're the options: " << endl;
    cout << "0.Exit the program" << endl;
    cout << "1.Insert a Node" << endl;
    cout << "2.Delete a Node" << endl;
    cout << "3.Search a Node" << endl;
    cout << "Please give us your choice: ";
    cin >> choice;
    return choice;
}
