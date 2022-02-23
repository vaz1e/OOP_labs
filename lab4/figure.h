#pragma once
class Figure
{
public:
    virtual float centerx() = 0;
    virtual float centery() = 0;
    virtual float area() const = 0;
    virtual void print() = 0;
};