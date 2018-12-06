#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <initializer_list>
#include <stdlib.h>

// a class representing an array of integers
class IntArray final {
public:
  IntArray(); // construct an empty array
  IntArray(size_t sz); // consruct an array with sz elements initialized to 0
  IntArray(const std::initializer_list<int> & lst); // construct an array containing the elements in lst
  IntArray(const IntArray & o); // copy constructor
  IntArray(IntArray && o); // move constructor
  ~IntArray(); // destructor

  const int * ptr() const; // get direct pointer to array
  size_t size() const; // get size of array

  IntArray & operator=(const IntArray & o); // copy assignment operator
  IntArray & operator=(IntArray && o); // move assignment operator

  int & operator[](size_t ind); // get a reference to the element at index ind; throws out_of_range if the index is invalid
  const int & operator[](size_t ind) const; // get a const reference to the element at index ind; throws out_of_range if the index is invalid

  friend bool operator==(const IntArray & lhs, const IntArray & rhs);
  friend bool operator!=(const IntArray & lhs, const IntArray & rhs);

  friend class IntArrayAlgorithms;

private:
  int * m_arr; // pointer to array holding elements
  size_t m_sz; // size of the array
};

#endif
