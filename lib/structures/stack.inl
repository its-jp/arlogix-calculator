#include "linked_list.hpp"
#include "stack.hpp"
template <typename T>
void Stack<T>::push(const T& data) {
  Node<T>* node = new Node<T>(data);
  LinkedList<T>::addNodeLast(node);
}

template <typename T>
T Stack<T>::pop() {
  T data = (LinkedList<T>::popNodeLast())->data;
  return data;
}

template <typename T>
T Stack<T>:: at(int index) const {
  return LinkedList<T>::at(index);
}

template <typename T>
T Stack<T>::peek() {
  Node<T>* node = LinkedList<T>::popNodeLast();
  T data = node->data;
  LinkedList<T>::addNodeLast(node);
  return data;
}

template <typename T>
bool Stack<T>::isEmpty() const {
  return LinkedList<T>::isEmpty();
}

template <typename T>
String Stack<T>::toString() const {
  return LinkedList<T>::toString();
}

template <typename T>
int Stack<T>::size() const {
  return LinkedList<T>::size();
}
