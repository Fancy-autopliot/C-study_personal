#include<iostream>
#include<string.h>
using namespace std;
// 函数调用运算符重载
// 函数调用运算符()也可以重载
// 由于重载后的使用方式非常像函数的调用，因此称为仿函数
// 仿函数没有固定写法，很灵活
// Add() = add  看到类型+()想到是匿名函数对象

class Print{
public:
    // 重载函数调用运算符
    void operator()(string test){
        cout << test << endl;
    }
};

class Add{
public:
 int operator()(int num1, int num2){
     return num1 + num2;
 }
};

void test01(){
    Print print;
    print("Hello, world!");
}

void test02(){
    Add add;
    int res = add(100, 100);
    cout << "res = " << res << endl;

    // 匿名函数对象
    cout << Add()(100, 100) << endl;    // Add() = add  类型+()想到是匿名函数对象
}

int main(){
    test01();
    test02();
    system("pause");
    return 0;
}