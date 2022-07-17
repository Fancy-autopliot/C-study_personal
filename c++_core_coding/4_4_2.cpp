#include<iostream>
#include<string.h>
using namespace std;
// 友元
// 友元的目的：让一个函数或者类 访问另一个类中私有成员
// 友元的关键字：==friend==
// 三种实现方式
//     全局函数做友元   
//     类做友元         √
//     成员函数做友元

class Building;
class GoodGuy{
public:
    GoodGuy();
    void Visit();
// private:
    Building *building;
    
};

class Building{
    friend class GoodGuy;
public:
    Building();
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};


// 类外写成员函数
Building::Building(){
    this->m_SittingRoom = "客厅";
    this->m_BedRoom = "卧室";
}

GoodGuy::GoodGuy(){
    // 创建building对象
    building = new Building;
}

void GoodGuy::Visit(){       // 访问Building中的公有及私有属性
    cout << "your good guy is visiting " << building->m_SittingRoom << endl;
    // 如果没有将该函数设为友元，则无法访问类的私有成员变量
    cout << "your good guy is visiting " << building->m_BedRoom << endl;
}

void test01(){
    GoodGuy gg;
    gg.Visit();
}

int main(){
    test01();
    system("pause");
    return 0;
}