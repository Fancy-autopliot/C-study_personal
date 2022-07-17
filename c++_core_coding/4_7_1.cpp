#include <iostream>
#include <string.h>
using namespace std;
// 多态---- C++面向对象的三大特性之一 (封装，继承，多态)
// 多态分为两类：静态多态和动态多态
// 静态多态:函数重载 和 运算符重载属于静态多态, 复用函数名
// 动态多态:派生类和虚函数实现运行时多态
// 静态多态和动态多态的 区别
// 静态多态的函数地址早绑定 -- 编译阶段确定函数地址
// 动态多态的函数地址晚绑定 -- 运行阶段确定函数地址

// 总结：多态的满足条件： 1、有继承关系     2、子类重写父类中的虚函数
// 多态使用条件：父类指针或 引用指向子类对象
// 重写：函数返回值类型  函数名  参数列表  完全一致称为重写

class Animal{
public:
    // speak函数就是虚函数
    // 函数前面加上virtual关键字,变成虚函数,那么编译器在编译的时候就不能确定函数调用了
    virtual void speak(){
        cout << "the animal is speaking " << endl;
    }
};

class Cat : public Animal{
public:
    void speak(){
        cout << "the cat is speaking " << endl;
    }
};

class Dog : public Animal{
public:
    virtual void speak(){
        cout << "the dog is speaking " << endl;
    }
};

// 我们希望传入什么对象，那么就调用什么对象的函数
// 如果函数地址在编译阶段就能确定，那么就是静态联编
// 如果函数地址在运行阶段才能确实，那么就是动态联编
void DoSpeak(Animal &animal){       // 父类的引用指向子类对象
    animal.speak();
}

// 动态多态满足条件：
// 1、有继承关系
// 2、子类 重写 父类中的虚函数，父类中speak函数(virtual)，子类也有speak函数
// 多态的使用：父类指针或引用指向子类对象
void test01(){
    Animal animal;
    DoSpeak(animal);

    Cat cat;
    DoSpeak(cat);

    Dog dog;
    DoSpeak(dog);
}

void test02() {
    // 不加virtual关键字时，成员函数不占用内存，sizeof为1
    // 加了virtual关键字后，sizeof变成8  64位操作系统(32位系统的size为4)，此时占内存的为指针vftpr(virtual function pointer)虚函数指针
    cout << "size of animal = " << sizeof(Animal) << endl;
    cout << "size of cat = " << sizeof(Cat) << endl;
}

int main()
{
    // test01();
    test02();
    system("pause");
    return 0;
}
