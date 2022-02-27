#ifndef LAB5_TITERATOR_H
#define LAB5_TITERATOR_H

#include <iostream>

template <class item, class T> class TIterator {
public:
    TIterator(std::shared_ptr<item> n) {
        item_ptr = n;
    }

    std::shared_ptr<T> operator *() {
        return item_ptr->polygon;
    }

    std::shared_ptr<T> operator ->() {
        return item_ptr->polygon;
    }

    void operator ++() {
        item_ptr = item_ptr->next;
    }

    TIterator operator ++(int) {
        TIterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator ==(TIterator const& i) {
        return (item_ptr == i.item_ptr);
    }

    bool operator !=(TIterator const& i) {
        return (item_ptr != i.item_ptr);
    }

private:
    std::shared_ptr<item> item_ptr;
};


#endif //LAB5_TITERATOR_H