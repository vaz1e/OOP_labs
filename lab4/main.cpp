#include <iostream>
#include "tree.h"
#include "fiveanglefig.h"
#define SIZE 3
int main()
{
    Fiveanglefigure a[SIZE];
    TBinaryTree tree;
    for (int i = 0; i < SIZE; i++)
    {
        std::cin >> a[i];
        tree.Push(a[i]);
    }
    std::cout << tree << std::endl;
    std::cout << tree.Count(a[0]) << std::endl;
    tree.Pop(a[1]);
    std::cout << tree << std::endl;
    tree.Clear();
    if (tree.Empty())
        std::cout << "Дерево пустое" << std::endl;
    return 0;
}