#include<iostream>
using namespace std;

// 常量引用
// 作用：常量引用主要用来修饰形参，防止误操作
// 在函数形参列表中，可以加const修饰形参，防止形参改变实参



void ShowValue(const int &val){   // 该函数中val为形参,防止形参改变实参
                                  // 为了防止输出过程误操作修改数据，增加const
    // val = 100;  //修改会报错
    cout << "val = " << val << endl;
}


int main() {
    int a = 10;

    // int& ref = 10; // 引用必须为合法区域，不能引用栈区数据
    
    // 加上const后，编译器将代码修改为
    // int temp = 10; const int& ref = temp;
    const int& ref = 10; 
    cout << "ref = " << ref << endl;
    // ref = 20; //加const后为只读状态，ref无法修改

    ShowValue(a);

    system("pause");
    return 0;
}