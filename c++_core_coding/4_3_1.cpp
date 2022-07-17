#include<iostream>
#include<string.h>
using namespace std;
// C++对象模型和this指针
// 成员变量 和 成员函数分开存储
// 在C++中，类内的成员变量和成员函数分开存储
// 只有非静态成员变量才属于类的对象上

class Person{
public:

};

class Dog{
public:
    int m_a;                 // 非静态成员变量，属于类的对象上
    static int m_b;          // 静态成员变量，不属于类的对象上，故增加一个静态成员变量不会增加内存
    void func1(){ }          // 非静态成员函数，不属于类的对象上
    static void func2(){ }   // 静态成员函数，不属于类的对象上
};

int Dog::m_b = 0;

void test01(){
    Person p1;
    // 查看空对象占用的内存空间
    // 空对象占用内存空间为1，C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    // 每个空对象也应该有一个独一无二的内存地址
    cout << "size of p1: " << sizeof(p1) << endl;
};

void test02(){
    Dog d1;
    // 查看非空对象占用的内存空间
    
    cout << "size of d1: " << sizeof(d1) << endl;
};


int main(){
    test01();
    test02();
    system("pause");
    return 0;
}