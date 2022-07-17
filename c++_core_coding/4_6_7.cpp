#include <iostream>
#include <string.h>
using namespace std;
// 多继承语法
// C++允许一个类继承多个类
// 语法：class 子类 : 继承方式 父类1, 继承方式 父类2...
// 多继承可能会引发父类中有同名成员出现，需要加作用域区分
// C++实际开发中不建议采用多继承

class Base1{
public:
    Base1(){
        m_A = 100;
    }
public:
    int m_A;
};

class Base2{
public:
    Base2(){
        m_A = 200;
    }
public:
    int m_A;
};

class Son : public Base1, public Base2{
public:
    Son(){
        m_C = 300;
        m_D = 400;
    }
public:
    int m_C;
    int m_D;
};

void test01(){
    Son son;
    cout << "size of son = " << sizeof(Son) << endl;
    cout << "son base1 m_A = " << son.Base1::m_A << endl;
    cout << "son base2 m_A = " << son.Base2::m_A << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}
