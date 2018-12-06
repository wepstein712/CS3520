#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <memory>

// class representing a double-ended queue as a doubly-linked list
template<typename T>
class Deque {
private:
  // forward declaration for iterator
  struct Node;

public:
  // const iterator over deque
  class const_iterator {
  public:
    // TODO: implement iterator functions
    const_iterator(const Node * n) {
      node = std::weak_ptr<Node> (n);
    } // construct from a Node pointer
    const_iterator(const const_iterator & it) {
      node = std::weak_ptr<Node> (it.node);
    } // copy iterator
    const_iterator & operator++() {
      if (node->next) { node = node->next; }
      return this;
    } // move the iterator to the next item, return new value
    const_iterator operator++(int) {
      if (node->next) { node = node->next; return std::make_shared<const_iterator> (node->prev); }
      else { return this; }
    } // move the iterator to the next item, return old value
    const T & operator*() const {
      return node->item;
    }  // dereference to get the current item
    bool operator==(const const_iterator & it) {
     return node == it.node;
    } // compare iterators
    bool operator!=(const const_iterator & it) {
     return node != it.node;
    } // compare iterators

    // types for STL algorithms
    typedef T value_type;
    typedef const T & reference;
    typedef const T * pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef void difference_type;

  private:
    // TODO: update pointer types
    const std::weak_ptr<Node> node;
  };

  Deque() = default;
  ~Deque() = default;

  bool empty() const; // return true if the deque is empty, false otherwise
  void debug_print() const; // print the contents of the list to stdout

  void push_front(const T & t); // push an element onto the front of the deque
  void push_back(const T & t); // push an element onto the back of the deque

  void pop_front(); // pop an element (if any) off the front of the deque
  void pop_back(); // pop an element (if any) off the back of the deque

  const_iterator cbegin() const; // return a const iterator to the beginning of the deque
  const_iterator cend() const; // return a const iterator to the ending of the deque (i.e. "one off the end")

private:
  Deque(const Deque &) = delete;
  Deque & operator=(const Deque &) = delete;

  struct Node {
    T item; // item for this node
    
    // TODO: update pointer types
    std::shared_ptr<Node> next; // pointer to next node (null if tail)
    std::shared_ptr<Node> prev; // pointer to previous node (null if head)
  };

  // TODO: update pointer types
  std::weak_ptr<Node> m_head; // pointer to head node
  std::weak_ptr<Node> m_tail; // pointer to tail node
};




template<typename T>
bool Deque<T>::empty() const
{
  return !m_head;
}

template<typename T>
void Deque<T>::debug_print() const
{
  std::cout << "deque contents:";
  for (auto node = m_head; node; node = node->next) {
    std::cout << " " << node->item;
  }
  std::cout << std::endl;
}

template<typename T>
void Deque<T>::push_front(const T & t) {
  // TODO: allocate a new node and add it to the front of the list, updating head and tail as needed
  auto nn = std::shared_ptr<Node> (t);
  nn->next = m_head;
  m_head.prev = std::shared_ptr<Node> (*nn);
  m_head = std::weak_ptr<Node> (*nn);
}

template<typename T>
void Deque<T>::push_back(const T & t) {
  // TODO: allocate a new node and add it to the front of the list, updating head and tail as needed
  auto nn = std::shared_ptr<Node> (t);
  nn->prev = m_tail;
  m_tail.next = std::shared_ptr<Node> (*nn);
  m_tail = std::weak_ptr<Node> (*nn);

}

template<typename T>
void Deque<T>::pop_front() {
  // TODO: remove front node from the list
  if (!empty()) {
    m_head = m_head.next;
    m_head.prev = nullptr;
  }
}

template<typename T>
void Deque<T>::pop_back() {
  // TODO: remove back node from the list
  if (!empty()) {
    m_tail = m_tail.prev;
    m_tail.next = nullptr;
  }
}

template<typename T>
typename Deque<T>::const_iterator Deque<T>::cbegin() const
{
  // TODO: return iterator
  return std::make_shared<const_iterator> (m_head);
}

template<typename T>
typename Deque<T>::const_iterator Deque<T>::cend() const
{
  // TODO: return iterator
  return std::make_shared<const_iterator> (m_tail);
}

// utility functions for range-based for loops
template <typename T>
typename Deque<T>::const_iterator
begin(const Deque<T> & d) {
  return d.cbegin();
}

template <typename T>
typename Deque<T>::const_iterator
end(const Deque<T> & d) {
  return d.cend();
}

#endif
