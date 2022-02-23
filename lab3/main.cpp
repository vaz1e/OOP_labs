#include <iostream>
#include <vector>
#include <math.h>
class Figure
{
public:
    virtual float centerx() = 0;
    virtual float centery() = 0;
    virtual float area() = 0;
    virtual void print() = 0;
};

class Fiveanglefigure : public Figure
{
public:
    Fiveanglefigure(float a, float b, float length) : x1(a), y1(b), side(length){};
    float centerx()
    {
        return x1 + side / 2;
    }
    float centery()
    {
        return y1 + side;
    }
    float area()
    {
        return 5 * side * side / 4 / tan(36 * 3.14 / 180);
    }
    void print()
    {
        std::cout << x1 << " " << y1 << std::endl;
    }

private:
    float x1, y1;
    float side;
};

class Sixanglefigure : public Figure
{
public:
    Sixanglefigure(float a, float b, float length) : x1(a), y1(b), side(length){};
    float centerx()
    {
        return x1 + side / 2;
    }
    float area()
    {
        return 6 * side * side / 4 / tan(30 * 3.14 / 180);
    }
    float centery()
    {
        return y1 + sqrt(3) / 2 * side;
    }
    void print()
    {
        std::cout << x1 << " " << y1 << std::endl;
    }

private:
    int x1, y1;
    int side;
};

class Eightanglefigure : public Figure
{
public:
    Eightanglefigure(float a, float b, float length) : x1(a), y1(b), side(length){};
    float centerx()
    {
        return x1;
    }
    float centery()
    {
        return y1 + side * cos(23 * 3.14 / 180);
    }
    float area()
    {
        return 8 * side * side / 4 / tan(23);
    }
    void print()
    {
        std::cout << x1 << " " << y1 << std::endl;
    }

private:
    float x1, y1;
    float side;
};

int main()
{
    std::vector<Figure *> vect;
    float x1, y1, z1;
    std::cin >> x1 >> y1 >> z1;
    Figure *a = new Fiveanglefigure(x1, y1, z1);
    std::cin >> x1 >> y1 >> z1;
    Figure *b = new Sixanglefigure(x1, y1, z1);
    std::cin >> x1 >> y1 >> z1;
    Figure *c = new Eightanglefigure(x1, y1, z1);
    vect.push_back(a);
    vect.push_back(b);
    vect.push_back(c);
    for (int i = 0; i < vect.size(); i++)
    {
        vect[i]->print();
        std::cout << vect[i]->centerx() << " " << vect[i]->centery() << std::endl
                  << vect[i]->area() << std::endl;
    }
    return 0;
}