#include<iostream>
using namespace std;
// 函数占位参数
// C++中函数的形参列表里可以有占位参数，用来做占位，调用参数时必须填补该位置
// 语法：返回值类型 函数名(数据类型){}
// 占位参数还可以有默认参数
// 当前阶段占位参数用不上，后续有用

// 占位参数
void func(int a, int){
    cout << "this is a function" << endl;
}
int main() {

    func(10, 10);

    system("pause");
    return 0;
}