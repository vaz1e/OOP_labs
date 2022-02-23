#include <iostream>
#include <memory>
#include "rectangle.h"
#include "mylist.h"
#include <algorithm>

void print_rect_and_area(std::shared_ptr<Rectangle> rect){
    std::cout << *rect << "Area is equal " << rect->Area() << std::endl;
}

int main(void)
{
    TLinkedList<Rectangle> list;
    std::shared_ptr<Rectangle> ptr = std::shared_ptr<Rectangle>(new Rectangle(1,2,3,4));
    list.InsertLast(ptr);
    ptr = std::shared_ptr<Rectangle>(new Rectangle(2,3,5,6));
    list.InsertLast(ptr);
    ptr = std::shared_ptr<Rectangle>(new Rectangle(1,0,100,6));
    list.Insert(ptr,0);
    std::for_each (list.begin(),list.end(), print_rect_and_area);
    std::cout<<std::endl;
    std::cout<< *list[2] << std::endl;
    list.Remove(1);
    std::for_each (list.begin(),list.end(), print_rect_and_area);
    return 0;
}