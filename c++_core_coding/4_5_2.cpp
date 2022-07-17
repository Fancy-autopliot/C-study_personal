#include<iostream>
#include<string.h>
using namespace std;
// 左移运算符重载
// 作用：可以输出自定义数据类型
// 总结：重载左移运算符配合友元可以实现输出自定义数据类型

class Person{
    friend ostream& operator<<(ostream& out, Person& p);
public:
    Person(){};
    Person(int a, int b){
        this->m_A = a;
        this->m_B = b;
    }
    // 不使用成员函数重载，成员函数实现不了 p << cout ，不是我们要的效果

private:
    int m_A;
    int m_B;
};

// 全局函数实现左移重载
// ostream对象只能有一个， cout 属于 ostream类中的对象
// 本质operator << (cout, p) ,简化为cout << p;
// 运算符重载前为ostream, 重载后仍应该为该类型
ostream& operator<<(ostream& cout, Person& p){
    cout << "a: " << p.m_A;// << endl;
    cout << "b: " << p.m_B;// << endl;
    return cout;
}

void test01(){
    Person p1(10, 20);
    cout << p1 << "Hello World" << endl;    // 链式编程
}

int main(){
    test01();
    system("pause");
    return 0;
}