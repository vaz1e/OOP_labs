#ifndef TREEELEM_H
#define TREEELEM_H

#include <memory>
#include "fiveanglefig.h"


class TreeElem{
public:
    TreeElem();
    TreeElem(const Fiveanglefigure octagon);

    const Fiveanglefigure& get_fig() const;
    int get_count_fig() const;
    TreeElem* get_left() const;
    TreeElem* get_right() const;
    
    void set_fig(const Fiveanglefigure& octagon);
    void set_count_fig(const int count);
    void set_left(TreeElem* to_left);
    void set_right(TreeElem* to_right);

    virtual ~TreeElem();
private:
    Fiveanglefigure fig;
    int count_fig;
    TreeElem* t_left;
    TreeElem* t_right;
};

#endif