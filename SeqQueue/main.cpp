//
//  main.cpp
//  SeqQueue1
//
//  Created by Yucheng on 2018/10/11.
//  Copyright © 2018 Yucheng. All rights reserved.
//

#include <iostream>
#include "SeqQueue1.cpp"
#include "SeqQueue2.cpp"
#include "SeqQueue3.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    SeqQueue1<int, 11> s1;//因为第一种队列牺牲了一个空间所以要额外加一个空间
    SeqQueue2<int, 10> s2;
    SeqQueue3<int, 10> s3;
    
    for (int i=0; i<10; i++)
    {
        s1.EnQueue(i);
        s2.EnQueue(i);
        s3.EnQueue(i);
    }
    cout << "s1's first item is : " << s1.GetQueue() << endl;
    cout << "s2's first item is : " << s2.GetQueue() << endl;
    cout << "s3's first item is : " << s3.GetQueue() << endl;
    if (!s1.Empty()) cout << "s1 is full!" << endl;
    if (!s2.Empty()) cout << "s2 is full!" << endl;
    if (!s3.Empty()) cout << "s3 is full!" << endl;
    
    cout << "s3's lenght is : " << s3.GetLen() << endl;
    for (int i=0; i<10; i++)
    {
        cout << s1.DeQueue() << s2.DeQueue() << s3.DeQueue() << endl;
    }
    if (s1.Empty()) cout << "s1 is empty!" << endl;
    if (s2.Empty()) cout << "s2 is empty!" << endl;
    if (s3.Empty()) cout << "s3 is empty!" << endl;
    return 0;
}
