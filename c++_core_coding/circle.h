#pragma once

using namespace std;

#include "point.h"

class Circle{
public:
    void SetRadius(float r);
    void SetCenter(Point point);
    double GetRadius();
    Point GetCenter();
    
private:
    double radius;
    Point circle_center;
};