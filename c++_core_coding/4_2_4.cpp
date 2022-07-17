#include<iostream>
#include<string.h>
using namespace std;
// 构造函数调用规则
// 默认情况下，编译器至少给一个类添加3个函数：
// 1.  默认构造函数(无参构造)    2. 默认析构函数    3. 默认拷贝构造函数，对属性进行值拷贝
// 构造函数调用规则如下：
// 如果用户定义有参构造函数，c++不再提供默认无参构造，但是会提供默认拷贝构造
// 如果用户定义拷贝构造函数，c++不再提供其他构造函数

class Person{
public:
    // 1. 无参类型(默认)--普通构造
    // Person(){
    //     cout << "Constructor function without parameter" << endl;
    // }

    // 2. 有参类型--普通构造
    // Person(int a){
    //     age = a;
    //     cout << "Constructor function with parameter" << endl;
    // }

    // 3. 拷贝构造
    Person(const Person &p){        // 将一个类的属性全部拷贝过来
        age = p.age;
        cout << "Constructor function with copy version" << endl;
    }

    // 4. 析构函数
    ~Person(){
        cout << "Destructor function has been called" << endl;
    }
public:
    int age;
};

// 1. 如果不写拷贝构造函数，编译器会自动添加拷贝构造函数，并且做浅拷贝操作
void test01(){
    Person p1(10);      // 有参构造函数调用
    Person p2(p1);      // 拷贝构造函数调用
    cout << "p2 age: " << p2.age << endl;
}

// 2. 如果定义了有参构造函数，编译器不再提供默认构造函数(无参构造)，会提供浅拷贝构造
void test02(){
    // Person p;           // 由于没有默认构造函数，故此处会报错
    Person p1(20);
    Person p2(p1);         // 用户没有提供拷贝构造时，编译器会提供
    cout << "p2 age: " << p2.age << endl;
}

// 3. 如果用户定义了拷贝构造函数，编译器不再提供有参构造以及默认构造，
// 需要用户自己定义默认构造以及有参构造函数
void test03(){
    // Person p;           // 由于没有默认构造函数，故此处会报错
    // Person p1(20);      // 用户没有提供有参构造，报错
    Person p2(p1);         
    cout << "p2 age: " << p2.age << endl;
} 


int main(){
    // test01();
    test02();
    // test03();

    system("pause");
    return 0;
}