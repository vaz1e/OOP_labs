#include <iostream>
#include <memory>
#include "trapezoid.h"
#include "stack.h"
int main(void){
	TStack<std::shared_ptr<Trapezoid>> stack;
	std::shared_ptr<Trapezoid> tr(new Trapezoid(1, 2, 3, 4));


	std::cout << stack << std::endl;

	std::shared_ptr<Trapezoid> t;

	std::cout << "Enter n: ";
	int n; std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> *tr;	
		std::cout << *tr << std::endl;
		stack.Push(std::shared_ptr<Trapezoid>(new Trapezoid(*tr)));
		std::cout << stack;
		std::cout << std::endl;
	}
	return 0;   
}