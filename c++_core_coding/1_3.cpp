#include<iostream>
using namespace std;
// 堆区数据有程序员管理开辟和释放
// 堆取数据利用new关键字进行开辟内存
// 采用delete释放数据
int * func(){
    // 利用new关键字开辟到堆区
    // 指针本质也是局部变量，放在栈去，但是指针保存的数据是放在堆区的
    int * p = new int (10);
    return p;

}

void test01() {
    // 在堆区开辟数据
    int * p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;

    // 利用关键字delete释放堆区数据
    delete p;
    cout << *p << endl;     // 虽然有输出，但是并不是指针所指向的数据
}

void test02() {
    // 在堆区创建10个整型数据的数组
    int * arr  = new int [10];  // 10代表数组有10个元素

    for (int i = 0; i < 10; i++){
        arr[i] = i + 100;   // 给10个元素赋值
    }
    for (int i = 0; i < 10; i++){
        cout << arr[i] << endl;
    }
    // 释放堆区数组，需要在delete后加[]
    delete [] arr;
}

int main() {
    test01();
    test02();
       
    system("pause");
    return 0;
}