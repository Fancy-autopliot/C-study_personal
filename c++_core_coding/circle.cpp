#include "circle.h"
// #include "point.h"

void Circle::SetRadius(float r){
    radius = r;
}
void Circle::SetCenter(Point point){
    circle_center = point;
}
double Circle::GetRadius(){
    return radius;
}
Point Circle::GetCenter(){
    return circle_center;
}