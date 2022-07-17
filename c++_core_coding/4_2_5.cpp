#include<iostream>
#include<string.h>
using namespace std;
// 深拷贝与浅拷贝
// 面试经典问题
// 浅拷贝：简单的复制拷贝操作
// 深拷贝：在堆区重新申请空间，进行拷贝操作--利用new

// 浅拷贝带来的问题：堆区内存重复释放
// 此时应当由用户提供深拷贝构造函数解决该问题,及在堆区创建新的内存
// 总结：如果属性有在堆区开辟的，一定要自己提供深拷贝构造函数，防止浅拷贝带来的问题

class Person{
public:
    // 1. 无参类型(默认)--普通构造
    Person(){
        cout << "Constructor function without parameter" << endl;
    }

    // 2. 有参类型--普通构造
    Person(int a, int h){
        age = a;
        height = new int(h);    // 利用new将数据存储到堆区，new创建的数据会返回该数据对应类型的指针
        cout << "Constructor function with parameter" << endl;
    }

    // 3. 拷贝构造
    Person(const Person &p){        // 将一个类的属性全部拷贝过来
        age = p.age;
        // height = p.height;      // 编译器默认执行该行代码--浅拷贝
        height = new int(*p.height);    // 深拷贝操作

        cout << "Constructor function with copy version" << endl;
    }

    // 4. 析构函数
    ~Person(){
        // 析构代码，将堆区开辟的数据做释放操作
        // 避免出现野指针,采用置空操作
        if (height != NULL){
            delete height;
            height = NULL;
        }
        cout << "Destructor function has been called" << endl;
    }
public:
    int age;
    int *height;
};

void test01(){
    Person p1(18, 160);
    cout << "p1 的年龄为： "  << p1.age << "p1 的身高为： " << *p1.height << endl;  // *p1.height解析指针
    Person p2(p1);
    cout << "p2 的年龄为： "  << p2.age << "p2 的身高为： " << *p2.height << endl;
}

int main(){
    test01();

    system("pause");
    return 0;
}