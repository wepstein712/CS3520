#ifndef INT_ARRAY_ALGORITHMS_CXXTEST_H
#define INT_ARRAY_ALGORITHMS_CXXTEST_H

#include <cxxtest/TestSuite.h>
#include <iostream>
#include "IntArrayAlgorithms.hpp"

class IntArrayAlgorithmsTestSuite : public CxxTest::TestSuite
{
  IntArray* a = new IntArray(0);
  IntArray* b = new IntArray{1, 5, 7, 9, 10};
  IntArray* c = new IntArray{2, 3, 4, 6, 8};
  IntArray* d = new IntArray{3, 7, 1, 2, 8, 9, 4, 6};
  IntArray* e = new IntArray{3, 1, 2};
  IntArray* f = new IntArray{1, 2, 3};
  IntArrayAlgorithms* algo = new IntArrayAlgorithms;

  void init() {
  a = new IntArray(0);
  b = new IntArray{1, 5, 7, 9, 10};
  c = new IntArray{2, 3, 4, 6, 8};
  d = new IntArray{3, 7, 1, 2, 8, 9, 4, 6};
  e = new IntArray{3, 1, 2};
  f = new IntArray{1, 2, 3};

  }

public:

  void testSwap(void) {
    init();
    algo->swap(*a, *b);
    TS_ASSERT_EQUALS(b->size(), 0);
    algo->swap(*a, *b);
  }


  void testContains(void) {
    init();
    TS_ASSERT_EQUALS(algo->contains(*b, 1), true);
    TS_ASSERT_EQUALS(algo->contains(*c, 1200), false);
  }

  void testSort(void) {
    init();
   // TS_ASSERT_EQUALS(algo->sort(*b), *b);
    algo->sort(*e);
    TS_ASSERT_EQUALS(*e, *f);
    e[0] = 3;
    e[1] = 1;
    e[2] = 2;

  // algo->sort(*d);
  // TS_ASSERT_EQUALS(d[7], 9);
  // d = new IntArray{3, 7, 1, 2, 8, 9, 4, 6};
  }

  void testSum(void) {
    init();
    TS_ASSERT_EQUALS(algo->sum(*a), 0);
    TS_ASSERT_EQUALS(algo->sum(*b), 32);
  }

  void testProduct(void) {
   init();
    TS_ASSERT_EQUALS(algo->product(*a), 1);
    TS_ASSERT_EQUALS(algo->product(*e), 6);
}


  void testBasics(void) {
    TS_ASSERT(1+1 > 1);
    TS_ASSERT_EQUALS(1+1, 2);
    TS_ASSERT_EQUALS(sizeof(int), 4);
    //TS_ASSERT_EQUALS(a.size, (size_t)4);
  } 
  void test_REMOVEME() {}

};

#endif
