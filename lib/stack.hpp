#pragma once

#include "linked_list.hpp"
#include "string.hpp"
template <typename T>
class Stack : LinkedList<T> {
  public:
    Stack() : LinkedList<T>() {};
    void push(const T& data);
    T pop();
    T at(int index) const;
    T peek();
    bool isEmpty() const;
    String toString() const;
    int size() const;
};

#include "stack.inl"
