#include<iostream>
using namespace std;
// 函数重载
// 作用：函数名可以相同，提高复用性

// 函数重载满足条件：
// 1、同一个作用域下
// 2、函数名称相同
// 3、函数参数类型不同，或者个数不同，或者顺序不同

void func(){
    cout << "func的调用01" << endl;
}

void func(int a){
    cout << "func的调用02" << endl;
}

void func(double a){
    cout << "func的调用03" << endl;
}

void func(int a, double b){
    cout << "func的调用04" << endl;
}

void func(double b, int a){
    cout << "func的调用05" << endl;
}

// 注意：函数的返回值不介意作为函数重载的条件,无法重载仅按返回类型区分的函数
// int func(double b, int a){
//     cout << "func的调用05" << endl;
// }

int main() {

    func();
    func(10);
    func(3.1);
    func(5, 1.11);
    func(1.33, 4);

    system("pause");
    return 0;
}