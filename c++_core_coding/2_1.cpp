#include<iostream>
using namespace std;

// 引用----给变量起别名
// 语法：数据类型 &别名 = 原名
// 注意事项：
//          1.引用必须要初始化； int &b; 该写法未初始化，错误
//          2.引用一旦初始化，就不可以更改。

int main() {
    // 创建变量
    int a = 100;
    // 创建引用
    int &b = a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    b = 104;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // 创建一个新的变量
    int c = 99;

    // 该操作为赋值，是允许的
    b = c;
    cout << "b = " << b << endl;

    // 该操作是更改引用，是不允许的
    // int &b = c;

    system("pause");
    return 0;
}