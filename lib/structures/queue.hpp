#pragma once
#include "linked_list.hpp"
#include "string/string.hpp"
template <typename T>
class Queue : private LinkedList<T> {
  public:
    Queue() : LinkedList<T>() {};
    void enqueue(const T& data);
    T dequeue();
    T at(int index) const;
    bool isEmpty() const;
    String toString() const;
    int size() const;
};

#include "queue.inl"
