#include<iostream>
#include<string.h>
using namespace std;
// 继承
// 继承方式：公共继承，保护继承， 私有继承
// 总结：所有的继承方式都无法访问基类的私有权限
// 1、公共继承时，基类的成员权限不变
// 2、保护继承时，基类的成员权限全部变为保护权限
// 3、私有继承时，基类的成员权限全部变成私有权限，类内可访问
class Base1{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

// 公共继承
class Son1 : public Base1{
public:
    void func(){
        m_A = 10;       // 父类中的  公共权限成员，到子类中依然是  公共权限
        m_B = 20;       // 父类中的  保护权限成员，到子类中依然是  保护权限
        // m_C = 30;    // 父类中的  私有权限成员，子类访问不到

    }
};
// 公共继承测试 
void test01(){
    Son1 son1;
    son1.m_A = 100;         // 由于是公共权限，故类外可以访问
    // son1.m_B = 200;      // 保护权限在类外无法访问
}

// 保护继承
class Son2 : protected Base1{
public:
    void func(){
        m_A = 10;       // 父类中的  公共权限成员，到子类中变成了  保护权限
        m_B = 20;       // 父类中的  保护权限成员，到子类中依然是  保护权限
        // m_C = 30;    // 父类中的  私有权限成员，子类访问不到

    }
};
// 保护继承测试 
void test02(){
    Son2 son2;
    // son2.m_A = 100;      // 保护权限在类外无法访问
    // son1.m_B = 200;      // 保护权限在类外无法访问
}

// 私有继承
class Son3 : private Base1{
public:
    void func(){
        m_A = 10;       // 父类中的  公共权限成员，到子类中变成了  私有权限
        m_B = 20;       // 父类中的  保护权限成员，到子类中依然是  私有权限
        // m_C = 30;    // 父类中的  私有权限成员，子类访问不到

    }
};
// 私有继承测试 
void test03(){
    Son3 son3;
    // son2.m_A = 100;      // 私有权限在类外无法访问
    // son1.m_B = 200;      // 私有权限在类外无法访问
}

// 私有继承的私有继承
class GrandSon : private Son3{
public:
    void func() {
        // 由于Son3为私有继承，其中的成员均为私有权限，故通过私有继承Son3的Grandson3其中的成员都无法访问，均为私有权限
        // m_A = 100;
        // m_B = 200;
    }
};

int main(){
    test01();
    cout << "------------------------------------------" << endl;
    test02();
    cout << "------------------------------------------" << endl;
    test03();
    system("pause");
    return 0;

}
