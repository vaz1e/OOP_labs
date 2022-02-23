#pragma once
#include "figure.h"
#include <iostream>
class Fiveanglefigure : public Figure
{
public:
    Fiveanglefigure(float a, float b, float length):x1(a),y1(b),side(length){};
    Fiveanglefigure():x1(0),y1(0),side(0){};
    float centerx();
    float centery();
    float area() const;
    void print();
    friend bool operator==(const Fiveanglefigure& fig_1,const Fiveanglefigure& fig_2);
    friend bool operator!=(const Fiveanglefigure& fig_1,const Fiveanglefigure& fig_2);
    friend std::istream& operator>> (std::istream &in, Fiveanglefigure &fig){
        std::cout<<"Введите сторону:";
        in >> fig.side;
        std::cout<<"Введите координаты нижнего угла:";
        in >> fig.x1 >>fig.y1;
        return in;
    }
private:
    float x1, y1;
    float side;
};