#ifndef TQUEUE_H
#define TQUEUE_H

#include "queueitem.h"
#include <memory>

template <typename T> class TQueue {
public:
    TQueue();
    TQueue(const TQueue& other);
    void Push(std::shared_ptr<T> &&trapezoid);
    void Pop();
    std::shared_ptr<T>& Top();
    bool Empty();
    size_t Length();
    template <class A> friend std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue);
    void Clear();
    virtual ~TQueue();
private:
    std::shared_ptr<TQueueItem<T>> head, tail;
};

#endif // TQUEUE_H