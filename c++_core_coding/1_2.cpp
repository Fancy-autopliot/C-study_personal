#include<iostream>
using namespace std;
// 栈区存放局部变量以及形参，程序结束后会自动释放

int* func(int b) { // b为形参，同样存放在栈区
    b = 100;
    int a = 10; //局部变量,存放在栈区，栈区的数据在函数执行完后自动释放
    return a;  //该操作为返回局部变量的地址，由于值被释放，所以编译会报错
}

int main() {
    // 接受func函数的返回值
    int * p = func(1);

    // 由于栈区的数据已经被释放，故此处编译会报错
    cout << *p << endl;
    cout << *p << endl;
    
    system("pause");
    return 0;
}