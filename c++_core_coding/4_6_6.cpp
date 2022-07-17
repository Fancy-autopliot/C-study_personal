#include <iostream>
#include <string.h>
using namespace std;
// 继承同名静态成员处理方式
// 问题：继承中同名的静态成员在子类对象上如何进行访问
// 静态成员与非静态成员出现同名，处理方式一致
// 访问子类同名成员,直接访问即可
// 访问父类同名成员,需要加作用域

class Base
{
public:
    static void func(){
        cout << "Base - static func" << endl;
    }

    static void func(int a){
        cout << "Base - static func(int a)" << endl;
    }

public:
    static int m_A;
    static int m_B;
};

// static静态成员变量需要在类内声明，类外初始化
int Base::m_A = 100;
int Base::m_B = 200;

// 公共继承
class Son : public Base
{
public:
    static void func(){
        cout << "Son - static func" << endl;
    }

    // static void func(int a){
    //     cout << "Son - static func(int a)" << endl;
    // }
public:
    static int m_A;
};
int Son::m_A = 88;

// 静态成员的访问方式：1、通过类名进行访问Class::variate(function)
//                   2、通过对象进行访问Class class; class.variate(function)

// 1、通过类名进行访问
void test01()
{
    // 第一个::代表通过类名方式访问，第二个::代表访问父类作用域下
    Son::m_B = 222;     // 修改子类的m_B，为什么基类中的m_B也会变化？？？
    // cout << "m_A in Base by class name = " << Base::m_A << endl;
    // cout << "m_A in Base of Son by class name = " << Son::Base::m_A << endl;
    // cout << "m_B in Son by class name = " << Son::m_A << endl;

    cout << "m_B in Base by class name = " << Base::m_B << endl;
    cout << "m_B in Base of Son by class name = " << Son::Base::m_B << endl;

    Son::func();
    // Son::func(10);

    Son::Base::func();      // Base::func()是直接访问基类的成员，而Son::Base::func是访问子类中继承基类的成员+
    Son::Base::func(100);
}

// 2、通过对象进行访问
void test02()
{
    Son son;
    cout << "m_A in Base by object  = " << son.Base::m_A << endl;
    cout << "m_A in Son by object = " << son.m_A << endl;

    son.func();
    // son.func(10);

    son.Base::func();
    son.Base::func(100);
}

int main()
{
    test01();
    // test02();
    system("pause");
    return 0;

}
