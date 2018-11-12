#include "SeqList.h"
#include <iostream>
#include <fstream>
using namespace std;
//无参构造函数
template <class T, int MaxSize>
SeqList<T, MaxSize>::SeqList(){
    //data = new T[MaxSize];
    length = 0;
}
//含参构造函数
template <class T, int MaxSize>
SeqList<T, MaxSize>::SeqList(T a[], int n){
    if(n > MaxSize){
        cerr << "Illegal Argument!\n";
    }
    for(int i=0; i<n; i++){
        data[i] = a[i];
    }
    length = n;
}
//获取列表长度
template <class T, int MaxSize>
int SeqList<T, MaxSize>::ListLength(){
    return length;
}
//修改元素的值
template <class T, int MaxSize>
void SeqList<T, MaxSize>::modify(T item){
    bool found = false;
    for(int i=0; i<length; i++){
        if(data[i] == item){
            cout << "\nPlease input the rectify value: ";
            cin >> data[i];
            found = true;
        }
    }
    if(!found) cout << "Nothing found!";
}
//查找给定位置的T
template <class T, int MaxSize>
T SeqList<T, MaxSize>::Get(int pos){
    if(pos < 1 || pos > length){
        cerr << "Illegal Search position!\n";
        exit(1);
    }
    return data[pos-1];
}
//定位给定的T
template <class T, int MaxSize>
int SeqList<T, MaxSize>::Locate(T item){
    for(int i=0; i<length; i++){
        if(data[i] == item)
            return (i+1);
    }
    cout << "No such a item!\n";
    return -1;
}
//按顺序打印列表
template <class T, int MaxSize>
void SeqList<T, MaxSize>::PrintSeqList(){
    for(int i=0; i<length; i++){
        cout << data[i] << " ";
    }
}
//在指定位置插入T
template <class T, int MaxSize>
void SeqList<T, MaxSize>::Insert(int i, T item){
    if(length >= MaxSize){
        cerr << "Approached Limit!\n";
        exit(1);
    }
    if(i < 1 || i > length + 1){
        cerr << "Illegal Input!\n";
        exit(1);
    }
    for(int j=length-1; j>=i-1; j--){
        data[j+1] = data[j];
    }
    data[i-1] = item;
    length++;
}
//删除指定位置的T
template <class T, int MaxSize>
T SeqList<T, MaxSize>::Delete(int i){
    if(length == 0){
        cerr << "Approached Limit!\n";
        exit(1);
    }
    if(i < 1 || i > length){
        cerr << "Illegal Input!\n";
        exit(1);
    }
    i = i-1;
    T x = data[i];
    for(int j=i+1; j<length; j++){
        data[j-1] = data[j];
    }
    length--;
    return x;
}
//删除值最小的T
template <class T, int MaxSize>
T SeqList<T, MaxSize>::DeleteMin(){
    if(length <= 0){
        cerr << "The sequence is empty!\n";
        exit(1);
    }
    T min = data[0];
    int pos = 0;
    for(int i=1; i<length; i++){
        if(data[i] < min){
            min = data[i];
            pos = i;
        }
    }
    data[pos] = data[length-1];
    length--;
    return min;
}
//删除值在指定值的T
template <class T, int MaxSize>
void SeqList<T, MaxSize>::DeleteAppointed(T x){
    bool found = false;
    for(int i = 0; i<length; i++){
        if(data[i] == x)
        {
            for(int j=i; j<length-1; j++){
                data[j] = data[j+1];
            }
            found = true;
            length--;
            i--;//因为移位的原因，接下来一个数据会被忽略，所以需要再检查一下当前位置的数据
        }
    }
    
    if(!found)  cout << "Nothing Found!\n";
    else  cout << "Delete completed!\n";
}

//删除值在给定范围的T
template <class T, int MaxSize>
void SeqList<T, MaxSize>::DeleteRange(T s, T t){
    bool found = false;
    if(s >= t){
        cerr << "Illegal Input!\n";
        exit(1);
    }
    
    for (int i=0; i<length; i++) {
        if(data[i] <= t && data[i] >= s){
            SeqList<T, MaxSize>::Delete(i+1);
            found = true;
            i--;//
        }
    }
    
    if(!found)  cout << "Nothing Found!\n";
    else cout << "Delete completed!\n";
}

//删除所有重复的T
template <class T, int MaxSize>
void SeqList<T, MaxSize>::DeleteRepetition(){
    bool ans = false;
    for(int i=0; i<length; i++){
        for(int j=i+1; j<length; j++){
            if(data[i] == data[j]){
                SeqList<T, MaxSize>::Delete(j+1);
                ans = true;
                j--;//
            }
        }
    }
    
    if(ans) cout << "Delete completed!\n";
    else cout << "No need to Delete!\n";
}

//插入排序
template <class T, int MaxSize>
void SeqList<T, MaxSize>::InsertionSort(){
    for (int i=1; i<length; i++) {
        T temp = data[i];
        int j = i-1;
        while(j >= 0 && data[j] > temp){
            data[j+1] = data[j];
            j--;//
        }
        data[j+1] = temp;
    }
    
    cout << "Sort completed!\n";
}

//以a1为界限重新排列
template <class T, int MaxSize>
void SeqList<T, MaxSize>::Sorting(){
    T temp = data[0];
    for(int i=1; i<length; i++){
        if(data[i] < temp){
            T item = data[i];
            Insert(1, item);
            Delete(i+2);
        }
    }
}
//归并两个有序列表
template <class T, int MaxSize>
SeqList<T, MaxSize>& SeqList<T, MaxSize>::Merge(SeqList<T, MaxSize> s){
    if(length + s.ListLength() > MaxSize){
        cerr << "The list is too short to merge!!\n";
        exit(1);
    }
    for(int i=length; i<length+s.ListLength(); i++){
        data[i] = s.Get(i-length+1);
    }
    length+=s.ListLength();
    InsertionSort();
    return *this;
}
