#ifndef TBINARYTREE_H
#define TBINARYTREE_H

#include <iostream>
#include "treeelem.h"
#include "fiveanglefig.h"

class TBinaryTree {
 public:
 TBinaryTree();
 
 void Push(const Fiveanglefigure& octagon);
 size_t Count(const Fiveanglefigure& octagon);
 void Pop(const Fiveanglefigure& octagon);
 bool Empty();
 friend std::ostream& operator<<(std::ostream& os, const TBinaryTree& tree);
 void Clear();
 virtual ~TBinaryTree();
 private:
 TreeElem* t_root;
};

#endif