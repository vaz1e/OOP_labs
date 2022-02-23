#pragma once
#include <iostream>
// template <class T>
// class Rectangle
// {
// public:
//     Rectangle(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4)
//     {
//         a = std::pair(x1, y1);
//         b = std::pair(x2, y2);
//         c = std::pair(x3, y3);
//         d = std::pair(x4, y4);
//     }

// private:
//     std::pair<T, T> a, b, c, d;
// };
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