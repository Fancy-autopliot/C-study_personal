#include<iostream>
#include<string.h>
using namespace std;
// struct和class的区别
// 在C++中两者的区别在于默认的访问权限不同
// struct默认权限为公共
// class默认权限为私有

class Class{
    int m_Class;    //默认权限  私有
};

struct Struct{
    int m_Struct;   //默认权限  公共
};

int main() {
    // 实例化--通过一个类，创建一个对象的过程
    Class class_01;
    // class_01.m_Class = 100;     //  不可访问
    Struct struct_01;;
    struct_01.m_Struct = 100;
    
    system("pause");
    return 0;
}