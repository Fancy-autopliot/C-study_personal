#include<iostream>
using namespace std;

// 引用做函数返回值
// 作用：引用是可以作为函数的返回值存在的
// 注意：不要返回局部变量引用的
// 函数调用作为左值

int& test01(){
    int a = 10;  // 局部变量存放在四区中的栈区
    return a;
}

int& test02(){
    static int a = 10; // 静态变量存放在全局区，全局区数据在程序结束后释放
    return a;
}

int main() {
    // int &ref01 = test01();
    // 不能返回局部变量引用
    // cout << "ref01: " << ref01 << endl; 

    int &ref02 = test02();
    cout << "ref02: " << ref02 << endl; 

    test02() = 100;  // 相当于a = 100;
    cout << "ref02: " << ref02 << endl; 

    system("pause");
    return 0;
}