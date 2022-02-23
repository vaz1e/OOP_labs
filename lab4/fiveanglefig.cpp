#include "fiveanglefig.h"
#include <math.h>
#include <iostream>
float Fiveanglefigure::centerx()
{
    return x1 + side / 2;
}
float Fiveanglefigure::centery()
{
    return y1 + side;
}
float Fiveanglefigure::area() const
{
    return 5 * side * side / 4 / tan(36 * 3.14 / 180);
}
void Fiveanglefigure::print()
{
    std::cout << x1 << " " << y1 << std::endl;
}

bool operator==(const Fiveanglefigure& fig_1,const Fiveanglefigure& fig_2){
    if (fig_1.side == fig_2.side && fig_1.x1 ==fig_2.x1 && fig_1.y1 == fig_2.y1) return true;
    return false;
}

bool operator!=(const Fiveanglefigure& fig_1,const Fiveanglefigure& fig_2){
    if (fig_1.side == fig_2.side && fig_1.x1 ==fig_2.x1 && fig_1.y1 == fig_2.y1) return false;
    return true;
}