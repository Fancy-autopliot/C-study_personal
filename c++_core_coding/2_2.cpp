#include<iostream>
using namespace std;

// 引用做函数参数----函数传参时，可以利用引用的技术让形参修饰实参(地址传递)
// 优点：可以简化指针修改实参

// 交换函数

// 1.值传递
void swap01(int a, int b) {     // 此处a, b均为形参
    int temp = a;
    a = b;
    b = temp;
    // cout << "swap01_a = " << a << endl;     // 80, 形参发生了改变
    // cout << "swap01_b = " << b << endl;     // 18
}

// 2.地址传递
void swap02(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "swap02_a = " << *a << endl;     
    cout << "swap02_b = " << *b << endl;
}

// 3.引用传递
void swap03(int &a, int &b){    //理解为int &a = a;
    int temp = a;
    a = b;
    b = temp;
    cout << "swap03_a = " << a << endl;     
    cout << "swap03_b = " << b << endl;
}

int main() {
    // 创建变量
    int a = 18;
    int b = 80;
    // swap01(a, b);   //值传递，形参不会修饰实参,下面的输出不会发生数据交换
    // swap02(&a, &b); //地址传递，形参会修饰实参的
    swap03(a, b);   //引用传递，形参会修饰实参的

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    system("pause");
    return 0;
}