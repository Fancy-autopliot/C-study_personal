#include <iostream>
#include <string.h>
using namespace std;
// 继承中的对象模型
// 问题：从父类继承过来的成员，哪些属于子类对象中
// 父类中私有成员也会被子类继承，只是编译器给隐藏后无法访问
// 因此子类的内存中包括父类的私有成员，占用内存空间
class Base
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

// 公共继承
class Son : public Base
{
public:
    int m_D;
};

void test01()
{
    cout << "size of son = " << sizeof(Son) << endl;
}

int main()
{
    test01();
    system("pause");
}
