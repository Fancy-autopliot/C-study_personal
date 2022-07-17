#include<iostream>
using namespace std;
// 函数默认参数
// 返回值类型  函数名 （参数= 默认值）{}
// 如果我们自己传入数据，将会采用我们自己的数据，如果没有，将采用默认值

// 注意事项
// 1、如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有默认值
// int func1(int a, int b = 10, int c, int d){}  // 错误，c, d 都必须给默认值

// 2、如果函数的声明有默认参数，函数的实现就不能有默认参数
//    声明和实现只能有一个有默认参数
int func2(int a, int b);
int func2(int a = 10, int b = 10){
    return a+b;
}

// int func(int a, int b, int c){
int func(int a, int b = 20, int c = 30){

    return a+b+c;
}

int main() {

    // cout << func(10) << endl;       // 此时a = 10, 补全缺省值, 其余默认值

    // cout << func(10, 30) << endl;   // 此时a = 10, b = 30,有传递进入就用传递的数据

    cout << func2() << endl;        // 函数或者声明中只有一个能有默认值
    system("pause");
    return 0;
}