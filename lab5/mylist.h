#pragma once
#include <iostream> 
#include <memory>
#include "mlistelem.h"
#include "iter.h"

using namespace std;

template <class T>
class TLinkedList
{
private:
	size_t length;
	shared_ptr<TLinkedListItem<T>> pFirstItem;
	shared_ptr<TLinkedListItem<T>> pLastItem;

public:
	TLinkedList();
	TLinkedList(const TLinkedList& other);
	virtual ~TLinkedList();

	shared_ptr<T> First();
	shared_ptr<T> Last();
	shared_ptr<T> GetItem(size_t position);

	void InsertFirst(shared_ptr<T> pValue);
	void InsertLast(shared_ptr<T> pValue);
	void Insert(shared_ptr<T> pValue, size_t position);

	void RemoveFirst();
	void RemoveLast();
	void Remove(size_t position);

	void Clear();
	bool Empty();
	size_t Length();

	template <class T2>
	friend std::ostream& operator<<(std::ostream& os, const TLinkedList<T2>& list);

	std::shared_ptr<T> operator[](int pos){
		shared_ptr<TLinkedListItem<T>> curr = pFirstItem;
		int cur_pos = 0;
		while(curr){
			if (cur_pos != pos){
				curr = curr->getNextItemPtr();
				cur_pos++;
				continue;
			}
			return curr->getValuePtr();
		}
	throw runtime_error("Out of range");
	};
	TIterator<TLinkedListItem<T>, T> begin();
	TIterator<TLinkedListItem<T>, T> end();
};