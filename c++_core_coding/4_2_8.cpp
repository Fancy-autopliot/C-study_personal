#include<iostream>
#include<string.h>
using namespace std;
// 静态成员----静态成员变量
// 静态成员就是在成员变量和成员函数前加上关键字static, 成为静态成员
// 静态成员变量
//     所有对象共享同一份数据
//     在编译阶段分配内存
//     类内声明，类外初始化
// 静态成员变量两种访问方式
//     1、通过对象访问
//     2、通过类名访问

class Person{
public:
    static int m_A;
private:
    // 静态成员变量也是有访问权限的
    static int m_B;
};

int Person::m_A = 100;
int Person::m_B = 200;      // 无论公有和私有均在类外初始化


void test01(){
    Person p1;
    cout << p1.m_A << endl;     // output is 100
    Person p2;
    p2.m_A = 200;
    cout << p1.m_A << endl;     // output is 200
}


void test02(){
    // 静态成员变量，不属于某个对象上，所有对象都共享一份数据
    // 因此静态成员变量有两种访问方式
    // 1、通过对象进项访问
    // Person p1;
    // cout << p1.m_A << endl;

    // 2、通过类名进项访问
    cout << Person::m_A << endl;
    // cout << Person::m_B << endl;     // 类外访问不到私有静态成员变量
}

int main(){
    // test01();
    test02();

    system("pause");
    return 0;
}