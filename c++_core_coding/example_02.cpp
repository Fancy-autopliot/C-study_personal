#include<iostream>
#include<string.h>
#include<math.h>

#include "point.h"
#include "circle.h"
// 如果不添加这两个cpp文件就会报错
#include "point.cpp"
#include "circle.cpp"


using namespace std;
// 练习案例1：设计一个圆类和一个点类
// 计算点和圆的关系

double CalculateDistance(double x, double y, double x1, double y1){
    double a = pow((x1 - x), 2);
    double b = pow((y1 - y), 2);
    double d = sqrt(a+b);
    return d;
}

// 判断点和圆的位置关系
void IsInCircle(Circle &c, Point &p){
    double distance = CalculateDistance(c.GetCenter().GetPositionsX(), c.GetCenter().GetPositionsY(),
                                        p.GetPositionsX(), p.GetPositionsY());
    if (distance < c.GetRadius()){
        cout << "The Point is in the circle" << endl;
    }
    else if(distance > c.GetRadius()){
        cout << "The Point is outside the circle" << endl;
    }
    else{
        cout << "The Point is on the circle" << endl;
    }
    
}

int main(){
    Circle circle;
    Point center;
    
    center.SetPosition(0, 0);
    circle.SetRadius(5);
    circle.SetCenter(center);

    Point point;
    point.SetPosition(10, 10);

    IsInCircle(circle, point);
    
    system("pause");
    return 0;
}