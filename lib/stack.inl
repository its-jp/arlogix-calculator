#include "linked_list.hpp"
#include "stack.hpp"
#include <stdexcept>
#include <string>

template <typename T>
void Stack<T>::push(const T& data) {
  this->addNodeLast(new Node<T>(data));
}

template <typename T>
T Stack<T>::pop() {
  Node<T>* node = this->popNodeLast();
  if(!node) throw std::runtime_error("Stack Underflow");
  T data = node->data;
  delete node;
  return data;
}

template <typename T>
T Stack<T>::peek() const {
  if(this->isEmpty()) throw std::runtime_error("Stack is empty");
  Node<T>* current = this->head;
  while(current->next) {
    current = current->next;
  }
  return current->data;
}

template <typename T>
bool Stack<T>::isEmpty() const {
  return this->head == nullptr;
}

template <typename T>
String Stack<T>::toString() const {
  return LinkedList<T>::toString();
}

template <typename T>
T Stack<T>::at(int index) const {
  return LinkedList<T>::at(index);
}

template <typename T>
int Stack<T>::size() const {
  return LinkedList<T>::size();
}
