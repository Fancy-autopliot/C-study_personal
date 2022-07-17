#include<iostream>
#include<string.h>
using namespace std;
// 运算符重载
// 概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
// 加号运算符重载
// 总结：对于内置的数据类型的表达式的运算符是不可改变的
//      不要滥用运算符重载
// 三种：1、成员函数+号运算符重载
//      2、 全局函数+号运算符重载
//      3、运算符重载也可以发生函数重载

class Person{
public:
    Person(){};
    Person(int a, int b){
        this->m_A = a;
        this->m_B = b;
    }
    // 1、成员函数实现 + 号运算符重载，返回值是Person类
    // Person operator+(const Person& p){
    //     Person temp;
    //     temp.m_A = this->m_A + p.m_A;
    //     temp.m_B = this->m_B + p.m_B;
    //     return temp;
    // }
public:
    int m_A;
    int m_B;
};

// 2、通过全局函数实现 + 号运算符重载，全局函数不能使用this指针
Person operator+(const Person& p1, const Person& p2){
    Person temp(0, 0);
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}

// 3、运算符重载，可以发生函数重载
Person operator+(const Person& p1, int val){
    Person temp;
    temp.m_A = p1.m_A + val;
    temp.m_B = p1.m_B + val;
    return temp;
}


void test01(){
    
    Person p1;
    Person p2;
    p1.m_A = 10;
    p1.m_B = 20;
    p2.m_A = 15;
    p2.m_B = 25;

    // 1、成员函数方式，成员函数进行重载调用的本质为
    // Person p3 = p1.operator+(p2);
    // 2、全局函数重载本质调用：
    Person p3 = operator+(p1, p2);
    // 简化后如下
    // Person p3 = p1 + p2;
    cout << "p3 m_A = " << p3.m_A << endl;
    cout << "p3 m_B = " << p3.m_B << endl;

    // 3、运算符重载中的函数重载
    Person p4 = p1 + 100;
    cout << "p43 m_A = " << p4.m_A << endl;
    cout << "p43 m_B = " << p4.m_B << endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}