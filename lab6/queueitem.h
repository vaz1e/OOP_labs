#ifndef TQUEUE_ITEM_H
#define TQUEUE_ITEM_H
 
#include <memory>
#include "trapezoid.h"
#include "allocationblock.h"

template<typename T> class TQueueItem {
public:
  TQueueItem(const std::shared_ptr<T>& trapezoid);
  TQueueItem(const TQueueItem<T>& other);
  
  std::shared_ptr<TQueueItem<T>> SetNext(std::shared_ptr<TQueueItem> &next);
  std::shared_ptr<TQueueItem<T>> GetNext();
  std::shared_ptr<T> GetTrapezoid() const;
 
  template<typename A> friend std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj);
  void* operator new(size_t size);
  void operator delete(void* p);
  virtual ~TQueueItem();

public:
  std::shared_ptr<T> item;
  std::shared_ptr<TQueueItem<T>> next;
};
 
#endif // TQUEUE_ITEM_H