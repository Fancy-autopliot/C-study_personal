#include<iostream>
#include<string.h>
using namespace std;
// 封装
// 意义：
// 1、将属性和行为作为一个整体，表现生活中的事物
// 类中的属性和行为统一成为  成员
// 属性--成员属性，成员变量
// 行为--成员函数，成员方法
// 语法：class 类名{    访问权限: 属性  /  行为};

// Example_01: 设计一个圆类，求圆的周长
// 公式： 2 * PI * 半径
const double PI = 3.14;     // 圆周率

// class代表设计一个类，类后面紧跟着就是类名称
class Circle{
    // 访问权限
    // 公共权限
public:
    // 属性--一般为变量
    int m_radius;       // 半径

    // 行为--采用函数
    // 获取圆的周长
    double CalculateCircumFerence(){
        return 2 * PI * m_radius;
    }
};      // 类定义的花括号末尾需要加 ;

// Example_02: 设计一个类，属性包含学生姓名和学号，可以给姓名和学号赋值并显示出来
class Students{
public:
    string m_name;
    int m_id;
public:
  void SetName(string name){
      m_name = name;
  }
  void SetId(int id){
      m_id = id;
  }
  void ShowInfo(){
      cout << "Name: " << m_name << endl;
      cout << "ID: " << m_id << endl;
  }

};

// 将属性和行为加以权限控制

int main() {
    // 实例化--通过一个类，创建一个对象的过程
    // 通过圆类，创建具体的圆(对象)
    Circle c1;
    // 给圆对象 的属性进行赋值
    c1.m_radius = 10;
    // 输出
    cout << "the Circumference = " << c1.CalculateCircumFerence() << endl;

    Students student;
    student.SetName("James");
    student.SetId(2020111907);
    student.ShowInfo();
    system("pause");
    return 0;
}