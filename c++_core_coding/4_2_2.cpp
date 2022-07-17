#include<iostream>
#include<string.h>
using namespace std;
// 构造函数的分类及调用
// 两种分类方式：
//  1. 按参数分为：有参构造和无参构造
//  2. 按类型分为：普通构造和拷贝构造
// 三种调用方式：
// 1.括号法     2.显示法        3.隐式转换法

class Person{
public:
    // 1. 无参类型(默认)--普通构造
    Person(){
        cout << "Constructor function without parameter" << endl;
    }

    // 2. 有参类型--普通构造
    Person(int a){
        age = a;
        cout << "Constructor function with parameter" << endl;
    }

    // 3. 拷贝构造
    Person(const Person &p){        // 将一个类的属性全部拷贝过来
        age = p.age;
        cout << "Constructor function with copy version" << endl;
    }

    ~Person(){
        cout << "Destructor function has been called" << endl;
    }

public:
    int age;
};

// 调用方式
// 1. 括号法
// 注意事项
// 调用无参构造函数的时候不能加(),加了括号编译器会认为是函数声明  错误：Person p1()
void testPerson01(){
    Person p1;          // 默认构造函数的调动
    Person p2(10);      // 有参构造函数调用
    Person p3(p2);      // 拷贝构造函数调用
}


// 2. 显示法
// 注意事项
// 不要利用拷贝构造函数，初始化匿名对象，编译器会认为Person(p3) 等价于 Person p3; 会误认为是对象的声明
void testPerson02(){
    Person p1;
    Person p2 = Person(10);     // 有参构造
    Person p3 = Person(p2);     // 拷贝构造

    // Person(10);     // 匿名对象，特点：当前行执行结束后，系统会立即回收掉匿名对象
    // cout << "Testing " << endl;
}

// 3. 隐式转换法
void testPerson03(){
    Person p1;
    Person p2 = 10;
    Person p3 = p2;
}

int main(){
    testPerson01();
    testPerson02();
    testPerson03();

    system("pause");
    return 0;
}