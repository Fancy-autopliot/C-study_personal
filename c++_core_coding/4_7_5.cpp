#include <iostream>
#include <string.h>
using namespace std;
// 虚析构与纯虚析构
// 问题：多态使用时，如果子类中有属性开辟到退去，那么父类指针在释放时无法调用到子类的析构代码
// 解决方式：将父类中的析构函数改为虚析构或者纯虚析构
// 虚析构与纯虚析构共性：
// 1、可以解决父类指针释放子类对象
// 2、都需要有具体的函数实现
// 虚析构和纯虚析构的区别：
// 如果是纯虚析构，该类为抽象类，无法实例化对象
// 虚析构语法：virtual ~类名(){}
// 纯虚析构语法： virtual ~类名()=0;    类名::~类名(){}

// 总结：
// 1、虚析构和纯虚析构就是用来解决通过父类指针释放子类对象
// 2、如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
// 3、拥有纯虚析构的类也属于抽象类，无法实例化

class Animal{
public:
    Animal(){
        cout << "Animal的构造函数调用" << endl;
    }
    virtual void speak() = 0;
    // 在析构函数前加virtual，变为虚析构函数
    // 利用虚析构可以解决父类指针释放子对象时不干净的问题
    // virtual ~Animal(){
    //     cout << "Animal的虚析构函数调用" << endl;
    // }
    // 纯虚析构     纯虚析构和虚析构只能有一个
    virtual ~Animal() = 0;
};

Animal::~Animal(){
    cout << "Animal的纯虚析构函数调用" << endl;
}

// 与包含纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类，无法实例化对象
class Cat : public Animal{
public:
    Cat(string name){
        cout << "cat的构造函数调用" << endl;
        m_Name = new string(name);
    }
    virtual void speak(){
        cout << *m_Name << " cat is speaking" << endl;
    }
    ~Cat(){
        if (m_Name != NULL){
            cout << "cat的析构函数调用" << endl;
            delete m_Name;
            m_Name = NULL;
        }
        
    }
public:
    string *m_Name;
};

void test01(){
    Animal *animal = new Cat("Tom");
    animal->speak();
    // 父类指针在析构时候，不会调用子类中的析构函数，导致子类如果有堆区属性，出现内存泄露
    delete animal;      // delete删除的是指针纸箱的堆区内存，但指针本身未被删除
}

int main()
{
    test01();
    system("pause");
    return 0;
}
