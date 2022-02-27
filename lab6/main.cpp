
#include <iostream>
#include "trapezoid.h"
#include "queue.h"
#include "stack.h"
void TestTStack()
{
	TStack<Trapezoid> stack;
	Trapezoid trap(1,2,3,4);
	stack.Push(trap);
	while (!stack.IsEmpty())
	{
		std::cout << stack.Top() << std::endl;
		stack.Pop();
	}
}
void TestAllocationBlock()
{
	TAllocationBlock allocator(sizeof(int), 3);

	int *a1 = nullptr;
	int *a2 = nullptr;
	int *a3 = nullptr;

	a1 = (int *)allocator.allocate();
	*a1 = 1;
	std::cout << "a1 pointer value:" << *a1 << std::endl;

	a2 = (int *)allocator.allocate();
	*a2 = 2;
	a3 = (int *)allocator.allocate();
	*a3 = 3;
	std::cout << "a2 pointer value:" << *a2 << std::endl;
	allocator.deallocate(a1);
	allocator.deallocate(a2);
	allocator.deallocate(a3);
}
int main()
{
	TestAllocationBlock();
	TestTStack();
	return 0;
}