#include "point.h"

void Point::SetPosition(float x, float y){
    p_x = x;
    p_y = y;
}
double Point::GetPositionsX(){
    return p_x;
}
double Point::GetPositionsY(){
    return p_y;
}