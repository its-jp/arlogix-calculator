#pragma once
#include "linked_list.hpp"
#include "string.hpp"
template <typename T>
class Queue : private LinkedList<T> {
  public:
    Queue() : LinkedList<T>() {};
    void enqueue(const T& data);
    T dequeue();
    bool isEmpty() const;
    String toString() const;
};

#include "queue.inl"
