#pragma once
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class Point{
public:
    void SetPosition(float x, float y);
    double GetPositionsX();
    double GetPositionsY();

private:
    double p_x;
    double p_y;
};