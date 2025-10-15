#include "linked_list.hpp"
#include "queue.hpp"
#include <stdexcept>
#include <string>

template <typename T>
void Queue<T>::enqueue(const T& data){
  this->addNodeLast(new Node<T>(data));
}

template <typename T>
T Queue<T>::dequeue(){
  Node<T>* node = this->popNodeFirst();
  if(!node) throw std::runtime_error("Queue Underflow");
  T data = node->data; //copy by value
  delete node;
  return data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
  return this->size() == 0;
}

template <typename T>
String Queue<T>::toString() const {
  return LinkedList<T>::toString();
}

template <typename T>
T Queue<T>::at(int index) const {
  return LinkedList<T>::at(index);
}

template <typename T>
int Queue<T>::size() const {
  return LinkedList<T>::size();
}
