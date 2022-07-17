#include<iostream>
#include<string.h>
using namespace std;
// 关系运算符重载
// 作用：重载关系运算符，可以让两个自定义运算符进行比较操作

class Person{
public:
    Person(string name, int age){
        m_name = name;
        m_age = age;
    }

    //重载==关系运算符
    bool operator==(Person &p){
        if (this->m_name == p.m_name && this->m_age == p.m_age){
            return true;
        }
        else{
            return false;
        }
    }

    //重载!=关系运算符
    bool operator!=(Person &p){
        if (this->m_name != p.m_name || this->m_age != p.m_age){
            return true;
        }
        else{
            return false;
        }
    }
public:
    string m_name;
    int m_age;
};

// ==重载案例
void test01(){
    Person p1("Tom", 18);
    Person p2("James", 18);
    if (p1 == p2){
        cout << "p1 is equal to p2" << endl;
    }
    else{
        cout << "p1 is not equal to p2" << endl;
    }
}

// !=重载案例
void test02(){
    Person p1("Tom", 18);
    Person p2("Tom", 18);
    if (p1 != p2){
        cout << "p1 is not equal to p2" << endl;
    }
    else{
        cout << "p1 is equal to p2" << endl;
    }
}


int main(){
    test01();
    test02();
    system("pause");
    return 0;
}