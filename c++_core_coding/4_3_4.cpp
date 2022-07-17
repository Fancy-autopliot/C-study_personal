#include<iostream>
#include<string.h>
using namespace std;
// const修饰成员函数
// 成员函数加const后成为常函数
// 常函数内不可以修改成员属性
// 成员函数声明时加关键字mutable后，在常函数中依然可以修改

// 常对象
// 声明对象前加const称该对象为常对象
// 常对象只能调用常函数

class Person{
public:
    Person(){}
    // this指针的本质是 指针常量 指针的指向不可以改变
    // 在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
    void ShowPerson() const {
        // m_A = 100;      // 指针指向不可以改变，此时会报错
        m_B = 100;         // 由于声明中加了mutable关键字，故在常函数中仍可修改
    }

    void func(){
        cout << "not const func" << endl;
    }

    int m_A;
    mutable int m_B;
};

void test01(){
    Person p;
    p.ShowPerson();
};

// 常对象
void test02(){
    const Person p;        // 在对象前加const，变为常对象
    // p.m_A = 100;        // 常对象中的常函数，不可以修改
    p.m_B = 100;           // 常对象中的可变，可以修改

    // 常对象只能调用常函数
    p.ShowPerson();
    // p.func();       // 常对象不可以调用普通成员函数，因为普通成员函数可以修改成员变量
}

int main(){
    test01();
    system("pause");
    return 0;
}