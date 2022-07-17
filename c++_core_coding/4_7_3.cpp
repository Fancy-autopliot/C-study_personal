#include <iostream>
#include <string.h>
using namespace std;
// 多态纯虚函数和抽象类
// 在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容，因此将虚函数改为纯虚函数
// 纯虚函数语法： virtual 返回值类型 函数名 (参数列表) = 0；
// 当类中有了纯虚函数，这个类也称为==抽象类==
// 抽象类的特点：1、无法实例化对象      2、子类必须重写抽象类中的纯虚函数，否则也属于抽象类

// 存在纯虚函数，为抽象类
class Base{
public:
    virtual void func() = 0;
};

// 子类需要重写父类中的纯虚函数
class Son1 : public Base{
public:
    // 如果次数子类不重写父类中的纯虚函数，则子类也属于抽象类，不可进行实例化对象
    virtual void func(){
        cout << "use func of son1" << endl;
    }
};

class Son2 : public Base{
public:
    // 如果次数子类不重写父类中的纯虚函数，则子类也属于抽象类，不可进行实例化对象
    virtual void func(){
        cout << "use func of son2" << endl;
    }
};

void test01(){
    // 以下两行均会报错，因为抽象类无法实例化对象
    // Base base;
    // Base = new base;

    Base *base = NULL;
    base = new Son1;
    base->func();
    delete base;

    base = new Son2;
    base->func();
    delete base;
}

int main()
{
    test01();
    system("pause");
    return 0;
}
