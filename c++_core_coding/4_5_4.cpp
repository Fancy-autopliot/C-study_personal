#include<iostream>
#include<string.h>
using namespace std;
// 赋值运算符重载
// 编译器至少给一个类添加四个函数：
// 1、默认构造函数（无参构造）
// 2、默认析构函数（无参）
// 3、默认拷贝构造函数，对属性进行值拷贝
// 4、赋值运算符operator=,对属性进行值拷贝

// 如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
// 当出现p1 = p2 = p3这样的链式编程，需要在堆区利用new创建数据
// 堆区的数据需要delete进行释放，由于系统提供的默认为浅拷贝，从而会出现堆区数据重复删除
// 因此需要提供深拷贝操作保证正常

class Person{
public:
    Person(int age){
        m_age = new int(age);
    }

    // 重载拷贝构造函数
    Person& operator=(Person &p){
        if(m_age != NULL){
            delete m_age;
            m_age = NULL;
        }
        // 编译器提供的代码为浅拷贝
        // m.age = p.m_age;
        
        // 重构赋值，提供深拷贝
        m_age = new int(*p.m_age);
        // 返回自身，用于链式编程
        return *this;
    }

    // 由于利用new开辟了堆区数据，则需要delete手动释放
    // 此时未进行重载赋值运算符会导致堆区重复释放
    // 利用深拷贝去解决浅拷贝问题
    ~Person(){
        if(m_age != NULL){
            delete m_age;
            m_age = NULL;
        }
    }
    int *m_age;
};

void test01(){
    Person p1(18);
    Person p2(20);
    p2 = p1;
    cout << "p1的age = " << *p1.m_age << endl;
    cout << "p2的age = " << *p2.m_age << endl;
    
}

int main(){
    test01();

    system("pause");
    return 0;
}