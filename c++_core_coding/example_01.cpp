#include<iostream>
#include<string.h>
using namespace std;
// 练习案例1：设计立方体类
// 设计立方体类(cube)
// 求出立方体的体积和面积
// 分别用全局函数和成员函数判断两个立方体是否相等

class Cube{
public:
    void SetLength(int l){
        length = l;
    }

    double GetLength(){
        return length;
    }

    void SetWidth(int w){
        width = w;
    }

    double GetWidth(){
        return width;
    }

    void SetHeight(int h){
        height = h;
    }

    double GetHeight(){
        return height;
    }

    double CalculateVolume(){
        volume = length * width * height;
        return volume;
    }

    double CalculateArea(){
        area = 2* (length* width + length* height + height*width);
        return area;
    }

    // 利用成员函数盘点两个立方体是否相等
    bool IsSameByClass(Cube &cube){
        if (length == cube.GetLength() && 
            width == cube.GetWidth() && 
            height == cube.GetHeight()){
                return true;
            }
        return false;
    }

private:
    double length;
    double width;
    double height;
    double volume;
    double area;


};

// 利用全局函数判断两个立方体是否相等
bool IsSameShape(Cube &cube_01, Cube &cube_02){
    if (cube_01.GetLength() == cube_02.GetLength() &&
        cube_01.GetWidth() == cube_02.GetWidth() &&
        cube_01.GetHeight() == cube_02.GetHeight()){
            return true;
        }
    return false;
}

int main(){
    
    Cube cube_01;
    cube_01.SetLength(10);
    cube_01.SetWidth(10);
    cube_01.SetHeight(10);

    double a = cube_01.CalculateVolume();
    double b = cube_01.CalculateArea();

    cout << "cube_01_volume: " << a << endl;
    cout << "cube_01_area: " << b << endl;

    Cube cube_02;
    cube_02.SetLength(10);
    cube_02.SetWidth(8);
    cube_02.SetHeight(10);

    double c = cube_02.CalculateVolume();
    double d = cube_02.CalculateArea();

    cout << "cube_02_volume: " << c << endl;
    cout << "cube_02_area: " << d << endl;

    bool ret = IsSameShape(cube_01, cube_02);
    if (ret){
        cout << "cube_01 is same to cube_02" << endl;
    }
    else{
        cout << "cube_01 is different from cube_02" << endl;
    }

    bool ret_ = cube_01.IsSameByClass(cube_02);
    if (ret_){
        cout << "cube_01 is same to cube_02 in member function " << endl;
    }
    else{
        cout << "cube_01 is different from cube_02 in member function" << endl;
    }

    system("pause");
    return 0;
}