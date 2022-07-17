#include<iostream>
#include<string.h>
using namespace std;
// 友元
// 友元的目的：让一个函数或者类 访问另一个类中私有成员
// 友元的关键字：==friend==
// 三种实现方式
//     全局函数做友元   
//     类做友元         
//     成员函数做友元   √
// 同一个类下的成员函数拥有不同的访问权限
class Building;
class GoodGuy{
public:
    GoodGuy();
    void Visit();       // 让该函数可以访问Building中的私有成员
    void Visit_01();    // 无法访问私有成员
private:
    Building *building;
};

class Building{
    // 只给类中的一个成员函数赋予友元
    friend void GoodGuy::Visit();
public:
    // 构造函数的声明，实际写到类外
    Building();
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};



// 类外写构造函数以及成员函数
Building::Building(){
    this->m_SittingRoom = "客厅";
    this->m_BedRoom = "卧室";
}

GoodGuy::GoodGuy(){
    // 创建building对象
    building = new Building;     // 将数据写到堆区，因为析构函数会释放内存
}

void GoodGuy::Visit(){       // 访问Building中的公有及私有属性
    cout << "your good guy is visiting " << building->m_SittingRoom << endl;
    // 如果没有将该函数设为友元，则无法访问类的私有成员变量
    cout << "your good guy is visiting " << building->m_BedRoom << endl;
}

void GoodGuy::Visit_01(){
    cout << "your good guy is visiting_02 " << building->m_SittingRoom << endl;
    // 如果没有将该函数设为友元，则无法访问类的私有成员变量, 故访问私有类时会报错
    // cout << "your good guy is visiting_02 " << building->m_BedRoom << endl;
}

void test01(){
    GoodGuy gg;
    gg.Visit();
    gg.Visit_01();
}

int main(){
    test01();
    system("pause");
    return 0;
}