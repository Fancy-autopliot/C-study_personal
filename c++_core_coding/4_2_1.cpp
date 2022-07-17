#include<iostream>
#include<string.h>
using namespace std;
// 对象的初始化和清理

class Person{
public:
    // 1. 构造函数 进行初始化操作
    Person(){
        cout << "Person is successed used" << endl;
    }

    // 2. 析构函数 进行清理的操作
    ~Person(){
        cout << "Clear!" << endl;
    }
};

void testPerson(){
    Person p1;       // 在栈上的数据，该函数执行完后会释放这个对象
}

int main(){
    testPerson();
    Person p1;          // 如果在此处调用，该对象不会被释放，因为存在system("pause")
                        // 但是按任意键结束后会释放该函数

    system("pause");
    return 0;
}