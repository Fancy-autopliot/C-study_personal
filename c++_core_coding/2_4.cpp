#include<iostream>
using namespace std;

// 引用的本质
// 引用的本质在c++内部实现是一个指针常量.
// (指针常量，指针不可以变，但指针指向的值可以修改)
// 指针常量：int * const cp_a = &a;
// 常量指针：const int * p_ca = &a;

// 发现是引用，转换为int* const ref = &a;
void func(int& ref){
    ref = 100;  // ref是引用，转换为*ref = 100;
}


int main() {
    int a = 10;

    // 自动转换为int* const ref = &a;
    // 指针常量是指针指向不可改，也说明为什么引用不可更改
    int& ref = a;
    cout << "ref = " << ref << endl;
    ref = 20; //内部发现ref是引用，自动帮我们转换为：*ref = 20;

    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;

    func(a);

    system("pause");
    return 0;
}