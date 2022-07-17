#include <iostream>
#include <string.h>
using namespace std;
// 继承同名成员处理方式
// 问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或者父类中同名的数据
// 访问子类同名成员,直接访问即可
// 访问父类同名成员,需要加作用域
// 总结: 1、子类对象可以直接访问到子类中的同名对象
//      2、 子类对象加作用域可以访问到父类中的同名对象
//      3、 当子类与父类拥有同名的成员函数时，子类会 隐藏 父类中同名成员函数，通过增加作用域可以访问到父类中的同名函数

class Base
{
public:
    Base(){
        m_A = 100;
    }
    
    void func(){
        cout << "this is a function for Base" << endl;
    }

    void func(int a){
        cout << "this is another function for Base" << endl;
    }
public:
    int m_A;
};

// 公共继承
class Son : public Base
{
public:
    Son(){
        m_A = 80;
    }
    // 子类函数与父类函数同名
    void func(){
        cout << "this is a function for Son" << endl;
    }

    void func(int a){
        cout << "this is another function for Son" << endl;
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
public:
    // 子类对象与父类对象同名
    int m_A;
};

void test01()
{
    Son son;
    cout << "m_A in Base = " << son.Base::m_A << endl;
    cout << "m_A in Son = " << son.m_A << endl;

    // 当子类与父类拥有同名的成员函数时，子类会隐藏父类中同名成员函数，通过增加作用域可以访问到父类中的同名函数
    son.func();
    son.func(10);

    son.Base::func();
    son.Base::func(100);


}

int main()
{
    test01();
    system("pause");
    return 0;

}
