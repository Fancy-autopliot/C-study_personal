#include<iostream>
#include<string.h>
using namespace std;
// 递增运算符重载
// 作用：通过重载递增运算符，实现自己的整型数据
// 结论：前置递增返回引用，后置递增返回值

class MyInterger{
    friend ostream& operator<<(ostream& out, MyInterger myinteger);
public:
    MyInterger(){
        // 初始化成员变量
        m_Num = 0;
    }
    // 返回引用能够实现链式编程
    // 前置++重载，必须返回引用(返回原来的变量)，不能返回值(返回新的变量)
    MyInterger& operator++(){
        // 先++
        m_Num++;
        // 再返回
        return *this;
    }

    // 后置++重载，返回的为局部变量，函数执行完后局部对象会被释放，因此只能返回值
    // 后置递增耗时，值传递
    MyInterger operator++(int){ // int 代表占位参数，可以用于区分前置和后置递增
        // 记录当前自身的值，再++，返回递增前的值，从而实现先返回再++
        MyInterger temp = *this;    // 先将当前结果记录，再递增返回
        m_Num++;
        return temp;
    }

private:
    int m_Num;
};

// 全局函数实现左移重载
// ostream对象只能有一个
ostream& operator<<(ostream& cout, MyInterger myinteger){
    cout << myinteger.m_Num;
    return cout;
}

// 前置++，先++ 再返回
void test01(){
    MyInterger myinteger;
    cout << ++myinteger <<endl;
    cout << myinteger << endl;
}

// 后置++，先返回 再++
void test02(){
    MyInterger myinteger;
    cout << myinteger++ <<endl;
    cout << myinteger << endl;
}

int main(){
    // test01();
    test02();

    system("pause");
    return 0;
}