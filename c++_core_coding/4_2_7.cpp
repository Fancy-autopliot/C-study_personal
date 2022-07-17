#include<iostream>
#include<string.h>
using namespace std;
// 类对象作为类成员
// C++类中的成员可以是另一个类的对象，我们称该成员为对象成员
// B类中有对象A作为成员，A为对象成员
// 当创建B对象时，A与B的构造与析构的顺序
// 当其他类对象作为本类成员时，构造时应当先构造类对象，再构造自身，析构的顺序与构造相反
// 例: 手机这个类作为人这个类的成员,应当先构造手机这个类,人这个类才能完整构造
// 析构则反之,应当人这个类的地址释放后,再释放手机这个类

class Phone{
public:
    Phone(string p_brand, double p_size){
        brand = p_brand;
        size = p_size;
        cout << "Phone的构造函数" << endl;
    };

    ~Phone(){
        cout << "Phone的析构函数" << endl;
    }
    
    // brand
    string brand;
    // size
    double size;
};

class Person{
public:
    Person(string p_name, string p_brand, double p_size): name(p_name), phone(p_brand, p_size){
        cout << "Person的析构函数" << endl;
    }

    ~Person(){
        cout << "Person的析构函数" << endl;
    }

    // name
    string name;
    // phone
    Phone phone;
};

void test01(){
    Person p("justin", "iphone", 6.5);
    cout << p.name << " has " << p.phone.brand << ", it's size is " << p.phone.size << endl;
}

int main(){
    test01();


    system("pause");
    return 0;
}