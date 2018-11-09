#ifndef INT_ARRAY_CXXTEST_H
#define INT_ARRAY_CXXTEST_H

#include <cxxtest/TestSuite.h>
#include <iostream>
#include "IntArrayAlgorithms.hpp"

class IntArrayTestSuite : public CxxTest::TestSuite
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


  void destroy() {
    delete a; delete b; delete c; delete d; delete e; delete f; delete algo;
  }
public:

  void testDefaultConstructor(void) {
    IntArray* test = new IntArray();
    TS_ASSERT_EQUALS(a->size(), 0);
    delete test;
  }

  void testSizeConstruction(void) {
    IntArray* test = new IntArray(10);
    TS_ASSERT_EQUALS(test->size(), 10);
    TS_ASSERT_EQUALS(test[2], 0);
    delete test;
  }

  void testListConstruction(void) {
    IntArray* test = new IntArray{};
    TS_ASSERT_EQUALS(test->size(), 0);
    IntArray* test2 = new IntArray{1, 2, 3};
    TS_ASSERT_EQUALS(test2->size(), 3);
    delete test;
    delete test2;
  }


  void testCopyConstructor(void) {
    init();
    IntArray* test = new IntArray(*e);
    TS_ASSERT_EQUALS(test->size(), 3);
    delete test;

  }
 
  void testMoveConstructor(void) {
    init();
  //  IntArray* test(e);
  //  TS_ASSERT_EQUALS(*test,*e);
  //  delete & test;
  }

  void testDelete(void) {
    init();
    TS_ASSERT(b->ptr() != 0);
    delete b;
    TS_ASSERT_EQUALS(b->ptr()[0] == 1,false );
  } 

  void testSize(void) {
    init();
    TS_ASSERT_EQUALS(a->size(), 0);
    TS_ASSERT_EQUALS(b->size(), 5);
  }

  void testEqualOp(void) {
    init();
    a = d;
    TS_ASSERT_EQUALS(a->ptr()[0], 3);
    f = f;
    TS_ASSERT_EQUALS(f->ptr()[2], 3);
    e = f;
    TS_ASSERT_EQUALS(e->ptr()[1], f->ptr()[1]);
  }

  void testIndexOp(void) {
    init();
     size_t sz = 3;
    TS_ASSERT_EQUALS((*b)[sz], 9);
    sz = 100;
    TS_ASSERT_THROWS((*b)[sz],std::out_of_range);
    const IntArray* delta = new IntArray{1, 2};
    TS_ASSERT_EQUALS((*delta)[0], 1);
    TS_ASSERT_THROWS((*delta)[5], std::out_of_range);
  }


  void testBoolEqualityOp(void) {
    init();
    TS_ASSERT_EQUALS(*a, *a);
    TS_ASSERT_EQUALS(*a == *b, false);
    TS_ASSERT_EQUALS(*e == *f, false);
    TS_ASSERT_EQUALS(*f, *f);
  }


  void testInequalityOp(void) {
    init(); 
    TS_ASSERT_DIFFERS(*a, *b);
    TS_ASSERT_EQUALS(*a != *a, false);
  }

  void test_REMOVEME() {
    destroy();
  }

};

#endif
