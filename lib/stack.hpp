#pragma once

#include "linked_list.hpp"
#include "string.hpp"
template <typename T>
class Stack : LinkedList<T> {
  public:
    Stack() : LinkedList<T>() {};
    void push(const T& data);
    T pop();
    T peek() const;
    bool isEmpty() const;
    String toString() const;
};

#include "stack.inl"
