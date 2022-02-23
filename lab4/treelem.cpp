#include <iostream>
#include <memory>
#include "treeelem.h"


TreeElem::TreeElem() {
    fig;
    count_fig = 0;
    t_left = nullptr;
    t_right = nullptr;
}

TreeElem::TreeElem(const Fiveanglefigure figure) {
    fig = figure;
    count_fig = 1;
    t_left = nullptr;
    t_right = nullptr;
}

const Fiveanglefigure& TreeElem::get_fig() const{
    return fig;
}
int TreeElem::get_count_fig() const{
    return count_fig;
}
TreeElem* TreeElem::get_left() const{
    return t_left;
}
TreeElem* TreeElem::get_right() const{
    return t_right;
}

void TreeElem::set_fig(const Fiveanglefigure& figure){
    fig = figure;
}
void TreeElem::set_count_fig(const int count) {
    count_fig = count;
}
void TreeElem::set_left(TreeElem* to_left) {
    t_left = to_left;
}
void TreeElem::set_right(TreeElem* to_right) {
    t_right = to_right;
}

TreeElem::~TreeElem() {
}