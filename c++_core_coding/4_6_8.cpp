#include <iostream>
#include <string.h>
using namespace std;
// 菱形继承
// 菱形继承概念：
// 1、两个派生类继承同一个基类
// 2、又有某个类同时继承者两个派生类
// 这种继承被称为菱形继承，或者钻石继承
// 结论：菱形继承带来的主要问题是子类继承了两份相同的数据，导致资源浪费
// 利用虚继承可以解决菱形继承问题   采用虚基类指针

class Animal{
public:
    int m_Age;
};

// 直接继承
// class Sheep : public Animal {};
// class Tuo : public Animal {};

// 继承前加virtual关键字后，变为虚继承
// 此时公共的父类Animal成为虚基类
// 第一次继承Animal类
class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};
// 第二次继承Sheep和Tuo类
class SheepTuo : public Sheep, public Tuo {};

void test01(){
    SheepTuo sheeptuo;
    sheeptuo.Sheep::m_Age = 100;
    sheeptuo.Tuo::m_Age = 200;

    cout << "sheeptuo.Sheep::m_age = " << sheeptuo.Sheep::m_Age << endl;
    cout << "sheeptuo.Tuo::m_age = " << sheeptuo.Tuo::m_Age << endl;
    cout << "sheeptuo.m_age = " << sheeptuo.m_Age << endl;
}

// 直接继承后sheeptuo存在两份m_Age,此时会出现访问目标不明确的问题
// void test02(){
//     SheepTuo sheeptuo;
//     cout << sheeptuo.m_Age << endl;
// }


int main()
{
    test01();
    system("pause");
    return 0;
}
