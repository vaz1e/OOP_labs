#include "queue.h"
#include "trapezoid.h"
#include <vector>

template <class T>
TQueue<T>::TQueue() : head(nullptr), tail(nullptr) {
    std::cout << "Default queue created" << std::endl;
}

template <class T>
TQueue<T>::TQueue(const TQueue& other) {
    head = other.head;
    tail = other.tail;
    std::cout << "Queue copied" << std::endl;
}

template <class T>
void TQueue<T>::Push(std::shared_ptr<T> &&trapezoid) {
    std::shared_ptr<TQueueItem<T>> other(new TQueueItem<T>(trapezoid));

    if (tail == nullptr) {
        head = tail = other;
        std::cout << "Added one trapezoid to tail. " << "Coordinates: " << *other->item << ". Area = " << other->item->Area() << std::endl;
        return;
    }
    tail->SetNext(other);
    tail = other;
    tail->next = nullptr;
    std::cout << "Added one trapezoid to tail. " << "Coordinates: " << *other->item << ". Area = " << other->item->Area() << std::endl;
}

template <class T>
void TQueue<T>::Pop() {
    if (head == nullptr)
        return;

    std::cout << "Removed one trapezoid from head."  << "Coordinates: " << *head->item << ". Area = " << head->item->Area() << std::endl;

    head = head->GetNext();

    if (head == nullptr)
        tail = nullptr;
}

template <class T>
std::shared_ptr<T>& TQueue<T>::Top() {
    return head->item;
}

template <class T>
bool TQueue<T>::Empty() {
    return (head == nullptr) && (tail == nullptr);
}


template <class T>
size_t TQueue<T>::Length() {
    if (head == nullptr && tail == nullptr)
        return 0;
    std::shared_ptr<TQueueItem<T>> temp = head;
    int counter = 0;
    while (temp != tail->GetNext()) {
        temp = temp->GetNext();
        counter++;
    }
    return counter;
}


template <class T>
std::ostream& operator<<(std::ostream& os, const TQueue<T>& queue) {
    std::shared_ptr<TQueueItem<T>> temp = queue.head;
    std::vector<std::shared_ptr<TQueueItem<T>>> v;

    os << "Queue: ";
    os << "=> ";
    while (temp != nullptr) {
        v.push_back(temp);
        temp = temp->GetNext();
    }
    for (int i = v.size() - 1; i >= 0; --i) 
        os << *v[i] << " ";
    os << "=>";
    return os;
}

template <class T>
void TQueue<T>::Clear() {
    for (int i = 0; i < this->Length(); i++) {
        this->Pop();
    }
    std::cout << "Queue was cleared but still exist" << std::endl;
}

template <class T>
TQueue<T>::~TQueue() {
    std::cout << "Queue was deleted" << std::endl;
}

template class TQueue<Trapezoid>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Trapezoid>& queue);