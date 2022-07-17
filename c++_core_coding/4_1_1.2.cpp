#include<iostream>
#include<string.h>
using namespace std;
// 封装
// 意义：
// 2、类在设计时，可以把属性和行为放在不同的权限下，加以控制
// 成员函数的访问权限同样
// 访问权限有三种：
//      1.pulic(公共权限)           成员  类内可以访问，类外可以访问
//      2.protected(保护权限)       成员  类内可以访问，类外不可以访问      儿子也可以访问父亲中的保护内容
//      3.private(私有权限)         成员  类内可以访问，类外不可以访问      儿子无法访问父亲的私有内容       学习到继承时会考虑两者区别

class Person{
public:
    // 公共权限
    string m_Name;
protected:
    // 保护权限
    string m_Car;
private:
    // 私有权限
    int m_Password;

public:
    void func(){
        m_Name = "Justin";
        m_Car = "Mercedes Benz";
        m_Password = 557026;
        cout << "name: " << m_Name << endl;
        cout << "car: " << m_Car << endl;
        cout << "password: " << m_Password << endl;
    }

};

int main() {
    // 实例化--通过一个类，创建一个对象的过程
    Person P1;
    P1.m_Name = "IronMan";
    // P1.m_car = "Geely";     // 保护权限内容，在类外访问不到
    // P1.m_Password = 123456; // 私有权限内容，在类外访问不到
    P1.func();
    system("pause");
    return 0;
}