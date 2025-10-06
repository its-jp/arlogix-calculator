#pragma once 
#include <stdio.h>
#include "node.hpp"
#include <iostream>
#include "string.hpp"
template <typename T>
class LinkedList {
  public:
    LinkedList();
    LinkedList(const LinkedList<T>& l);

    void addNodeLast(Node<T>* node);
    void addNodeFirst(Node<T>* node);

    Node<T>* popNodeLast();
    Node<T>* popNodeFirst();
    void removeNodeLast();
    void removeNodeFirst();

    String toString() const;
    T at(int index) const;
  protected:    
    Node<T>* head;
};

#include "linked_list.inl"
