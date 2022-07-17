#include <iostream>
#include <string.h>
using namespace std;
// 多态案例--计算器类
// 案例描述：分别利用普通写法和多态技术，设计实现 两个操作数  进行运算的计算器类
// 多态的优点：1、代码组织结构清晰      2、可读性强     3、利于前期和后期的拓展以及维护
// 多态实现的意义：在普通写法中，如果想开发新的功能，需要修改源码
// 在真实开发中，提倡 开闭原则：对拓展进行开放，对修改进行关闭

// 普通写法
class Calculator{
public:
    int GetResult(string oper){
        if (oper == "+"){
            return m_Num1 + m_Num2;
        }
        else if (oper == "-"){
            return m_Num1 - m_Num2;
        }
        else if (oper == "*"){
            return m_Num1 * m_Num2;
        }
        else{
            cout << "Invalid oper" << endl;
        }
    }
public:
    int m_Num1;
    int m_Num2;
};
void test01(){
    Calculator calculator;
    calculator.m_Num1 = 15;
    calculator.m_Num2 = 25;
    cout << calculator.m_Num1 << " + " << calculator.m_Num2 << " = "<< calculator.GetResult("+") << endl;
    cout << calculator.m_Num1 << " - " << calculator.m_Num2 << " = "<< calculator.GetResult("-") << endl;
    cout << calculator.m_Num1 << " * " << calculator.m_Num2 << " = "<< calculator.GetResult("*") << endl;
}

// 多态实现
// 实现计算器的抽象类--不实现功能
class AbstractCalculator{
public:
    virtual int GetResult(){
        return 0;
    }
public:
    int m_Num1;
    int m_Num2;
};

// 加法计算器类--此时开始实现指定的功能
class AddCalculator : public AbstractCalculator{
public:
    int GetResult(){
        return m_Num1 + m_Num2;
    }
};
// 同理可得减法,乘法等
class SubCalculator : public AbstractCalculator{
public:
    int GetResult(){
        return m_Num1 - m_Num2;
    }
};

class MultipyCalculator : public AbstractCalculator{
public:
    int GetResult(){
        return m_Num1 * m_Num2;
    }
};

void test02(){
    // 父类的指针指向子类的对象
    AbstractCalculator *abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 15; 
    cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->GetResult() << endl;
    // 用该加法计算器后记得销毁
    delete abc;

    // 再调用减法计算器时直接采用父类指针，无需重新创建
    abc = new SubCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 15; 
    cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->GetResult() << endl;

    abc = new MultipyCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 15; 
    cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->GetResult() << endl;

}

int main()
{
    // test01();
    test02();
    system("pause");
    return 0;
}
