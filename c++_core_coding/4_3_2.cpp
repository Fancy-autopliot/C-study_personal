#include<iostream>
#include<string.h>
using namespace std;
// this指针概念
// 每一个非静态成员函数只会诞生一份函数实例,也就是说多个同类型的对象会共用一块代码
// 如何区分是哪个对象调用自己的呢?
// c++通过提供提问数的对象指针，this指针，解决上述问题

// this指针指向被调用的成员函数所属的对象
// this指针是隐含每一个非静态成员函数内的一种指针，无需定义即可使用
// 用途:1. 当形参和成员变量同名时，可以用this来区分
//      2. 在类的非静态成员函数中返回对象本身，可使用return *this

class Person{
public:
// this指针指向被调用的成员函数所属的对象
    Person (int age){
        this->age = age;
    }
    int age;

    // 返回值是void无法再次调用
    // void PersonAddAge(Person &p){
    // 如果以值的方式返回会创建一个新的对象，新的对象并没有输出。拷贝构造
    // Person PersonAddAge(Person &p){
    Person& PersonAddAge(Person &p){
        this->age += p.age;
        // this指向p2的指针，而*this指向的就是p2这个对象的本体
        return *this;
    }

};

void test01(){
    Person p1(18);
    cout << "age of p1: " << p1.age << endl;
};

void test02(){
    Person p1(10);
    Person p2(10);
    // 当返回值为void时
    // p2.PersonAddAge(p1);
    // 当返回值为class时--链式编程思想
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
    cout << "age of p2: " << p2.age << endl;
}


int main(){
    test01();
    test02();
    system("pause");
    return 0;
}