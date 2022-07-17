#include <iostream>
#include <string.h>
using namespace std;
// 继承中的构造和析构顺序
// 子类继承父类后，当创建子类对象，也会调用父类的构造函数
// 问题：父类和子类的构造与析构顺序谁先谁后？
// 结论: 先调用父类的构造函数，再调用子类的构造函数
//       先调用子类的析构函数，再调用父类的析构函数
class Base
{
public:
    Base(){
        cout << "Base的构造函数" << endl;
    }
    ~Base(){
        cout << "Base的析构函数" << endl;
    }
};

// 公共继承
class Son : public Base
{
public:
    Son(){
        cout << "Son的构造函数" << endl;
    }
    ~Son(){
        cout << "Son的析构函数" << endl;
    }
};

void test01()
{
    Son son;
}

int main()
{
    test01();
    system("pause");
    return 0;

}
