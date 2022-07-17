#include<iostream>
#include<string.h>
using namespace std;
// 静态成员----静态成员函数

// 静态成员函数
//     所有对象共享同一个函数
//     静态成员函数只能访问静态成员变量
// 静态成员函数两种访问方式
//     1、通过对象访问
//     2、通过类名访问

class Person{
public:
    // 静态成员函数
    static void func1(){
        // 静态的成员函数可以访问静态成员变量，无法访问非静态成员变量
        m_A = 100; 

        // m_B = 666;
        cout << "静态成员函数func1调用" << endl;
    };

    // 静态成员变量
    static int m_A;

    // 非静态成员变量
    int m_B;

private:
    // 静态成员函数存在访问权限
    static void func2(){
        cout << "静态成员函数func2调用" << endl;
    }
};

int Person::m_A = 10;

void test01(){
    // 1、通过对象进项访问
    Person p1;
    p1.func1();

    // 2、通过类名进项访问
    Person::func1();
    // Person::func2();    // 类内无法访问私有静态成员函数
};


int main(){
    test01();

    system("pause");
    return 0;
}