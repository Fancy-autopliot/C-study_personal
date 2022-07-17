#include<iostream>
using namespace std;
// 函数重载注意事项

// 1、引用作为重载的条件
void func(int &a){      // int &a = 10; 不合法
    cout << "func(int &a)的调用" << endl;
}

void func(const int &a){      // const int &a = 10;  合法
    cout << "func(const int &a)的调用" << endl;
}

// 2、函数重载碰到函数默认参数
void func2(int a, int b = 10){      
    cout << "func2(int a)的调用" << endl;
}

void func2(int a){      
    cout << "func2(int a)的调用" << endl;
}

int main() {
    int a = 10;         // 此时调用int
    func(a);
    func(10);           // 不设置初始值，直接输入func(10),此时调用const
    // func2(10);          // 此时函数重载碰到默认参数，出现二义性，编译报错，尽量避免出现这种情况
    func2(10,17);       // 这种方式明确了函数参数个数

    system("pause");
    return 0;
}