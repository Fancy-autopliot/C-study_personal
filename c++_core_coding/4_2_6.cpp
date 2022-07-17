#include<iostream>
#include<string.h>
using namespace std;
// 初始化列表
// 作用： c++提供了初始化列表语法，用来初始化属性
// 语法：构造函数():属性1(值1), 属性2(值2)...{}

class Person{
public:
    // 传统的初始化操作
    // Person(int a, int b, int c){
    //     m_a = a;
    //     m_b = b; 
    //     m_c = c;
    // }

    // 初始化列表的方式初始化属性
    Person(int a, int b, int c): m_a(a), m_b(b), m_c(c){}
    void PrintPerson(){
        cout << "m_a = " << m_a << endl;
        cout << "m_b = " << m_b << endl;
        cout << "m_c = " << m_c << endl;
    }

public:
    int m_a;
    int m_b;
    int m_c;
};

void test01(){
    Person p(10, 20, 30);
    cout << "m_a = " << p.m_a << endl;
    cout << "m_b = " << p.m_b << endl;
    cout << "m_c = " << p.m_c << endl;
}

int main(){
    test01();
    Person p(100, 200, 300);
    p.PrintPerson();
    system("pause");
    return 0;
}