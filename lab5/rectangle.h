#pragma once
#include <iostream>
class Rectangle
{
public:
    Rectangle(float x1, float y1, float first_side, float second_side)
    {
        x = x1;
        y = y1;
        this->first_side = first_side;
        this->second_side = second_side;
    }
    float Area(){
        return first_side*second_side;
    }
    friend std::ostream& operator<<(std::ostream& os, Rectangle& rect){
        os << "Rectangle: left lower corner coords " << "(" << rect.x << "," << rect.y << ")."  << "First side is " << rect.first_side << " and second side is " << rect.second_side << std::endl;
    }
private:
    float x;
    float y;
    float first_side;
    float second_side;
};