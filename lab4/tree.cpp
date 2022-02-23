#include "tree.h"
#include <stdexcept>

TBinaryTree::TBinaryTree() {
    t_root = nullptr;
}

void TBinaryTree::Push(const Fiveanglefigure& fig) {
    TreeElem* curr = t_root;
    if (curr == nullptr)
        t_root = new TreeElem(fig);
    
    while (curr)
    {
        if (curr->get_fig() == fig)
        {
            curr->set_count_fig(curr->get_count_fig() + 1);
            return;
        }
        if (fig.area() < curr->get_fig().area())
            if (curr->get_left() == nullptr)
            {
                curr->set_left(new TreeElem(fig));
                return;
            }
        if (fig.area() >= curr->get_fig().area())
            if (curr->get_right() == nullptr && !(curr->get_fig() == fig))
            {
                curr->set_right(new TreeElem(fig));
                return;
            }
        if (curr->get_fig().area() > fig.area())
            curr = curr->get_left();
        else
            curr = curr->get_right();
    }
}

size_t TBinaryTree::Count(const Fiveanglefigure& octagon) {
    size_t count = 0;
    TreeElem* curr = t_root;
    
    while (curr)
    {
        if (curr->get_fig() == octagon)
            count = curr->get_count_fig();
        if (octagon.area() < curr->get_fig().area())
        {
            curr = curr->get_left();
            continue;
        }
        if (octagon.area() >= curr->get_fig().area())
        {
            curr = curr->get_right();
            continue;
        }
    }
    return count;
}

void Pop_List(TreeElem* curr, TreeElem* parent);
void Pop_Part_of_Branch(TreeElem* curr, TreeElem* parent);
void Pop_Root_of_Subtree(TreeElem* curr, TreeElem* parent);
void TBinaryTree::Pop(const Fiveanglefigure& octagon) {

    TreeElem* curr = t_root;
    TreeElem* parent = nullptr;

    while (curr && curr->get_fig() != octagon)
    {
        parent = curr;
        if (curr->get_fig().area() > octagon.area())
            curr = curr->get_left();
        else
            curr = curr->get_right();
    }

    if (curr == nullptr)
        return;

    curr->set_count_fig(curr->get_count_fig() - 1);

    if(curr->get_count_fig() <= 0)
    {
        if (curr->get_left() == nullptr && curr->get_right() == nullptr)
        {
            Pop_List(curr, parent);
            return;
        }
        if (curr->get_left() == nullptr || curr->get_right() == nullptr)
        {
            Pop_Part_of_Branch(curr, parent);
            return;
        }
        if (curr->get_left() != nullptr && curr->get_right() != nullptr)
        {
           Pop_Root_of_Subtree(curr, parent);
           return;
        }
    }
}

void Pop_List(TreeElem* curr, TreeElem* parent) {
    if (parent->get_left() == curr)
                parent->set_left(nullptr);
            else
                parent->set_right(nullptr);
    delete(curr);
}

void Pop_Part_of_Branch(TreeElem* curr, TreeElem* parent) {
    if (parent) {
        if (curr->get_left()) {
            if (parent->get_left() == curr)
                parent->set_left(curr->get_left());

            if (parent->get_right() == curr)
                parent->set_right(curr->get_left());
    
            curr->set_right(nullptr);
            curr->set_left(nullptr);
            delete(curr);
            return;
        }

        if (curr->get_left() == nullptr) {
            if (parent && parent->get_left() == curr)
                parent->set_left(curr->get_right());

            if (parent && parent->get_right() == curr)
                parent->set_right(curr->get_right());

            curr->set_right(nullptr);
            curr->set_left(nullptr);
            delete(curr);
            return;
        }
    }
}

void Pop_Root_of_Subtree(TreeElem* curr, TreeElem* parent) {
    TreeElem* replace = curr->get_left();
    TreeElem* rep_parent = curr;
    while (replace->get_right())
    {
        rep_parent = replace;
        replace = replace->get_right();
    }

    curr->set_fig(replace->get_fig());
    curr->set_count_fig(replace->get_count_fig());
    
    if (rep_parent->get_left() == replace)
        rep_parent->set_left(nullptr);
    else
        rep_parent->set_right(nullptr);
    delete(replace);
    return;
}

bool TBinaryTree::Empty() {
    return t_root == nullptr ? true : false;
}

void Tree_out (std::ostream& os, TreeElem* curr);
std::ostream& operator<<(std::ostream& os, const TBinaryTree& tree) {
    TreeElem* curr = tree.t_root;
    Tree_out(os, curr);
    return os;
}

void Tree_out (std::ostream& os, TreeElem* curr) {
    if (curr)
    {
        if(curr->get_fig().area() >= 0) 
            os << curr->get_count_fig() << "*" << curr->get_fig().area();
        if(curr->get_left() || curr->get_right()) 
        {
            os << ": [";
            if (curr->get_left())
                Tree_out(os, curr->get_left());
            if(curr->get_left() && curr->get_right())
                os << ", ";
            if (curr->get_right())
                Tree_out(os, curr->get_right());
            os << "]";
        }
    }
}

void recursive_clear(TreeElem* curr);
void TBinaryTree::Clear() {
    if (t_root->get_left())
        recursive_clear(t_root->get_left());
    t_root->set_left(nullptr);
    if (t_root->get_right())
        recursive_clear(t_root->get_right());
    t_root->set_right(nullptr);
    delete t_root;
    t_root = nullptr;
}

void recursive_clear(TreeElem* curr){
    if(curr)
    {
        if (curr->get_left())
            recursive_clear(curr->get_left());
        curr->set_left(nullptr);
        if (curr->get_right())
            recursive_clear(curr->get_right());
        curr->set_right(nullptr);
        delete curr;
    }
}

TBinaryTree::~TBinaryTree() {
}