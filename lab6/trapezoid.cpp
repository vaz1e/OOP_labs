#include "trapezoid.h"
#include <cmath>

Trapezoid::Trapezoid()
    : len_ab(0.0),
      len_bc(0.0),
      len_cd(0.0),
      len_da(0.0) {
}

Trapezoid::Trapezoid(double ab, double bc, double cd, double da) 
    : len_ab(ab),
      len_bc(bc),
      len_cd(cd),
      len_da(da) {
}


Trapezoid::Trapezoid(std::shared_ptr<Trapezoid>& other)
    : Trapezoid(other->len_ab, other->len_bc, other->len_cd, other->len_da) {
}




Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this == &other)
        return *this;
    
    len_ab = other.len_ab;
    len_bc = other.len_bc;
    len_cd = other.len_cd;
    len_da = other.len_da;
    std::cout << "Trapezoid copied" << std::endl;
    return *this;  
}

std::ostream& operator<<(std::ostream& os, const Trapezoid& obj){
    os << obj.len_ab <<" " << obj.len_bc << " " << obj.len_cd << " " << obj.len_da;
    return os; 
}

bool Trapezoid::operator==(const Trapezoid& other) {
    if (this->len_ab == other.len_ab &&
        this->len_bc == other.len_bc &&
        this->len_cd == other.len_cd &&
        this->len_da == other.len_da) {
        std::cout << "Trapezoids are equal" << std::endl;        
        return 1;
    } else {
        std::cout << "Trapezoids are not equal" << std::endl; 
        return 0;
    }
}
size_t Trapezoid::VertexesNumber() {
    return 4;
}

double Trapezoid::Area() {
    double p = (len_ab + len_bc + len_cd + len_da) / 2;
    return (len_bc + len_da) *
           std::sqrt((p - len_bc) *
                     (p - len_da) *
                     (p - len_da - len_ab) *
                     (p - len_da - len_cd)) /
           std::abs(len_bc - len_da);
}

Trapezoid::~Trapezoid() {

    std::cout << "Trapezoid deleted" << std::endl;
}

TAllocationBlock Trapezoid::block(sizeof(Trapezoid), 1000);

void *Trapezoid::operator new(size_t size) {
    return block.allocate();
}

void Trapezoid::operator delete(void *ptr) {
    block.deallocate(ptr);
}