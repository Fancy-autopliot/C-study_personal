#include<iostream>
using namespace std;

// 全局变量和静态变量存放在全局区
// 局部变量以及局部常量存放在栈区
// 字符串常量与全局常量存放在常量区

int global_a = 10;
int global_b = 20;

// const修饰的全局变量，全局常量
const int const_a = 10;
const int const_b = 20;

int main() {
    // 全局区

    // 全局变量、静态变量、常量

    // 创建普通局部变量(局部变量在函数内)
    int a = 10;
    int b = 20;
    
    // 在普通变量前面加static, 属于静态变量，静态变量的地址与全局变量的地址很近
    static int static_a = 10;
    static int static_b = 20;

    // 常量，分为字符串常量以及const修饰的常量
    // 字符串常量
    cout << "字符串常量的地址为： " << (unsigned long long)&"Hello World" << endl;

    // const修饰的变量
    // 1. const修饰的全局常量(上方与全局变量放一起)
    cout << "全局常量const_a的地址 " << (unsigned long long)&const_a << endl;
    cout << "全局常量const_b的地址 " << (unsigned long long)&const_b << endl;

    // 2. const修饰的局部常量
    int const_local_a = 10;
    int const_local_b = 20;

    cout << "全局变量global_a的地址 " << (unsigned long long)&global_a << endl;
    cout << "全局变量global_b的地址 " << (unsigned long long)&global_b << endl;

    cout << "静态变量static_a的地址 " << (unsigned long long)&static_a << endl;
    cout << "静态变量static_b的地址 " << (unsigned long long)&static_b << endl;

    cout << "局部常量const_local_a的地址 " << (unsigned long long)&const_local_a << endl;
    cout << "局部常量const_local_b的地址 " << (unsigned long long)&const_local_b << endl;

    cout << "局部变量a的地址 " << (unsigned long long)&a << endl;
    cout << "局部变量b的地址 " << (unsigned long long)&b << endl;

    system("pause");
    return 0;
}