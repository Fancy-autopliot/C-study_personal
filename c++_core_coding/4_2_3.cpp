#include<iostream>
#include<string.h>
using namespace std;
// 拷贝构造函数的调用时机
// 1. 使用一个已经创建完毕的对象来初始化一个新的对象
// 2. 值传递的方式给函数参数传值
// 3. 以值方式返回局部对象 

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
    // 4. 析构函数
    ~Person(){
        cout << "Destructor function has been called" << endl;
    }
public:
    int age;
};

// 1. 使用一个已经创建完毕的对象来初始化一个新的对象
void testPerson01(){
    Person p1(10);      // 有参构造函数调用
    Person p2(p1);      // 拷贝构造函数调用
    cout << "p2 age: " << p2.age << endl;
}

// 2. 值传递的方式给函数参数传值
void Dowork01(Person p){      // 值传递会拷贝一个临时的副本

}
void testPerson02(){
    Person p;
    Dowork01(p);
}

// 3. 以值方式返回局部对象
Person Dowork02(){
    Person p1;
    cout << (int *)&p1 << endl;
    return p1;
}
void testPerson03(){
    Person p = Dowork02();
    cout << (int *)&p << endl;
}

int main(){
    testPerson01();
    // testPerson02();
    // testPerson03();

    system("pause");
    return 0;
}