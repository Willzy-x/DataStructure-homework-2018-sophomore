//
//  main.cpp
//  SeqStack
//
//  Created by Yucheng on 2018/9/29.
//  Copyright © 2018 Yucheng. All rights reserved.
//
#define N 100
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include "SeqStack.cpp"
using namespace std;
void Transform(int num, int s);
void Transform_with_Stack(int num, int c);
bool matchParenthesis(char* str);
bool matchP(char* str, int state);
bool judgeStack(char* str);
bool judge(char* str, int state, int len);
int optrToInt(char op);
char Precede(char prep_op, char p);
double operate(double left, char op, double right);
double Expression_Eval();
void PrintBack();


char pred[7][7] = {{'>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '>'},
    {'<', '<', '<', '<', '<', '=', ' '},
    {'>', '>', '>', '>', ' ', '>', '>'},
    {'<', '<', '<', '<', '<', ' ', '='}
};
static SeqStack<int, N> s0;
static SeqStack<char, N> s1;
static SeqStack<char, N> s2;
int main(int argc, const char * argv[]) {
    
//    int num, c;
//    cout << "Please input the Decimal digit: ";
//    cin >> num;
//    cout << "\nPlease input the conversion number: ";
//    cin >> c;
//    Transform_with_Stack(num, c);
//    cout << "\n";
//    Transform(num, c);

//    char eg[100];
//    cout << "Please input the expression: ";
//    cin >> eg;
//    cout << matchParenthesis(eg) << "\n" << matchP(eg, 0);
//
//    char es[100];
//    cout << "please input the sequence: ";
//    cin >> es;
//    long n = strlen(es);
//    cout << "\nHere's the result: " << judge(es, 1, n) << endl;
//
//    cout << "Here's the value of the expression: " << Expression_Eval() << endl;
    PrintBack();
    return 0;
}

//递归实现数制转换
void Transform(int num, int s)
{
    int k;
    if(num != 0){
        Transform(num/s, s);
        k = num % s;
        if (k < 10)
        {
            cout << k;
        }
        else
        {
            char m = k - 10 + 'A';
            cout << m;
        }
    }
    else
        return;
}
//栈实现递归转换
void Transform_with_Stack(int num, int c)
{
    int k;
    //入栈
    while (num != 0)
    {
        s0.Push(num%c);
        num /= c;
    }
    //出栈
    while (!s0.isEmpty())
    {
        k = s0.Pop();
        if (k < 10)
        {
            cout << k;
        }
        else
        {
            char m = k - 10 + 'A';
            cout << m;
        }
    }
}
//栈实现括弧匹配
bool matchParenthesis(char* str)
{
    for (int i=0; i < strlen(str); i++)
    {
        switch (str[i])
        {
            //左括号
            case '(':
                s1.Push('(');
                break;
            case '[':
                s1.Push('[');
                break;
            case '{':
                s1.Push('{');
                break;
            //右括号
            case ')':
                if (s1.isEmpty() || s1.Top() == ')')
                {
                    return false;
                    
                }
                else if(s1.Top() == '(')
                {
                    s1.Pop();
                }
                break;
            case ']':
                if (s1.isEmpty() || s1.Top() == ']')
                {
                    return false;
                    
                }
                else if(s1.Top() == '[')
                {
                    s1.Pop();
                }
                break;
            case '}':
                if (s1.isEmpty() || s1.Top() == '}')
                {
                    return false;
                    
                }
                else if(s1.Top() == '{')
                {
                    s1.Pop();
                }
                break;
            default:
                break;
        }
    }
    if (s1.isEmpty()) {
        return true;
    }
    else return false;
}
//递归实现匹配括号
bool matchP(char* str, int state)
{
    if (*str == '\0') {
        if (state == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(state<0)
        return false;
    if(*str == '(' || *str == '[' || *str == '{')
    {
        return matchP(str+1, state+1);
    }
    else if(*str == ')' || *str == ']' || *str == '}')
    {
        return matchP(str+1, state-1);
    }
    else
    {
        return matchP(str+1, state);
    }
}
//栈实现回文判断
bool judgeStack(char* str)
{
    for (int i=0; i < strlen(str); i++) {
        if (i < strlen(str)/2)
        {
            s2.Push(str[i]);
        }
        else
        {
            if (str[i] != s2.Pop()) {
                return false;
            }
        }
    }
    return true;
}
//递归实现回文判断
bool judge(char* str, int state, int len)
{
    char* t = str;
    while (*(t + state) != '\0') {
        t++;
    }
    if (state == len/2 + 1) {
        return true;
    }
    if (*str != *t) {
        return false;
    }
    else
    {
        return judge(str+1, state+1, len);
    }
}

//表达式求值
//算符转换
int optrToInt(char op)
{
    if (op == '+') return 0;
    else if (op == '-') return 1;
    else if (op == '*') return 2;
    else if (op == '/') return 3;
    else if (op == '(') return 4;
    else if (op == ')') return 5;
    else if (op == '@') return 6;
    else {
        cerr << "Invalid input!!\n";
        exit(1);
    }
}
//算符间的优先关系
char Precede(char prep_op, char p)
{
    int a = optrToInt(prep_op);
    int b = optrToInt(p);
    return pred[a][b];
}
//运算操作
double operate(double left, char op, double right)
{
    switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            if (right == 0.0) {
                cerr << "Left can't be divided by 0!!\n";
                exit(1);
            }
            return left / right;
        default:
            cerr << "Invalid input!!\n";
            exit(1);
    }
}
//表达式计算
double Expression_Eval()
{
    SeqStack<char, 100> OPTR;
    SeqStack<double, 100> OPND;
    OPTR.Push('@');
    string eg; double temp = 0; double countNeg = 0.1; bool flagD = false, flagT = false, flagNeg = false;
    cout << "Please input the expression:  ";
    cin >> eg;
    for (int i=0; i<=eg.length(); i++) {
        if (i == eg.length()) {//到字符串末尾时独立判断，相当于@的作用
            double b = OPND.Pop(); double a = OPND.Pop();
            char prep_op1 = OPTR.Pop();
            OPND.Push(operate(a, prep_op1, b));
            continue;
        }
        
        if (eg.at(i) == '-'){
            flagNeg = true;
        }
        
        
        if (eg.at(i) >= '0' && eg.at(i) <= '9') {
            if (flagD) {//小数点后
                temp += (eg.at(i) - '0') * countNeg;
                countNeg /= 10;
            }
            else {//小数点前
                temp *= 10;
                temp += eg.at(i) - '0';
            }
            flagT = true;
            
        }
        else if (eg.at(i) == '.') {//判断小数点
            flagD = true;
        }
        else{
            char prep_op = OPTR.Top();
            //
            if (flagNeg) temp *= -1;
            flagNeg = false;
            //
            if (flagT) OPND.Push(temp);
            flagT = false;
            flagD = false; countNeg = 0.1;//在取到下一个数字前重置
            switch (Precede(prep_op, eg.at(i))) {
                case '<':
                    OPTR.Push(eg.at(i));
                    break;
                case '=':
                    OPTR.Pop();
                    break;
                case '>':
                    double b = OPND.Pop(); double a = OPND.Pop();
                    prep_op = OPTR.Pop();
                    OPND.Push(operate(a, prep_op, b));
                    i--;
                    break;
            }
               temp = 0;
        }
    }
    return OPND.Top();
}
//打印后缀表达式
void PrintBack()
{
    SeqStack<char, 100> OPTR;
//    SeqStack<double, 100> OPND;
    OPTR.Push('@');
    string str;
    cout << "Please input:  ";
    cin >> str;
    for (int i=0; i<str.length()+1; i++) {
        if (i == str.length() && OPTR.Top() != '@') {
            cout << OPTR.Pop() << endl;
            continue;
        }
        else if (i == str.length()) continue;
        
        if (str.at(i) >= '0' && str.at(i) <= '9') {
            cout << str.at(i) << " ";
        }
        else if (str.at(i) == '('){
            OPTR.Push(str.at(i));
        }
        else if (str.at(i) == ')'){
            while (OPTR.Top() != '(') {
                cout << OPTR.Pop() << " ";
            }
            OPTR.Pop();
        }
        else{
            char prep_op = OPTR.Top();
            switch (Precede(prep_op, str.at(i))) {
                case '<':
                    OPTR.Push(str.at(i));
                    break;
                case '>':
                    cout << OPTR.Pop() << " ";
                    i--;
                    break;
                case '=':
                    cout << OPTR.Pop() << " ";
                    i--;
                    break;
                default:
                    cerr << "Invalid input!\n";
                    exit(1);
            }
        }
    }
}
