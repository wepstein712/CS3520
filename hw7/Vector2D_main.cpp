#include "Vector2D.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

int
main() {
  
  {
    // initialized to zero
    Vector2D v1;
    cout << setprecision(2) << v1 << endl;
  }
  
  {
    // element-wise initialized
    Vector2D v1(1.1, 2.1);
    cout << setprecision(2) << v1 << endl;
  }

  {
    // copy constructor
    Vector2D v0(2.2, 3.1);
    Vector2D v1(v0);
    cout << setprecision(2) << v1 << endl;
  }

  {
/*    // copy assignment
    Vector2D v1;
    Vector2D v2;
    v1 = v2 = Vector2D(3.3, 4.1);
    v2 = Vector2D(4.4, 5.1);
    cout << setprecision(2) << v1 << endl;
    cout << setprecision(2) << v2 << endl;
  }
*/

  {
    // set elements
    Vector2D v1(3.3, 4.1);
    v1.setX(5.5);
    v1.setY(6.1);
    cout << setprecision(2) << v1 << endl;
  }

  {
    // get elements
    Vector2D v1(6.6, 7.1);
    cout << setprecision(2) << v1.getX() << " " << v1.getY() << endl;
  }

  {
    // element access
    Vector2D v1;
    v1[0] = 8.8;
    v1[1] = 9.1;
    cout << setprecision(2) << v1 << endl;

    try {
      v1[2] = 0.0;
    } catch (const out_of_range & e) {
      cout << "caught exception" << endl;
    }

    const Vector2D & cv1 = v1;
    cout << setprecision(2) << cv1[0] << " " << cv1[1] << endl;

    try {
      cout << cv1[2] << endl;
    } catch (const out_of_range & e) {
      cout << "caught exception" << endl;
    }
  }
/*
  
    // testing (in)equality
    Vector2D v1(1, 2);
    Vector2D v2(3, 4);
    cout << (v1 == v2) << " " << (v1 == v1) << endl;
    cout << (v1 != v2) << " " << (v1 != v1) << endl;
  }

  {
    // element-wise negation
    cout <<  -Vector2D(-1.1, -2.1) << endl;
  }

  {
    // addition
    Vector2D v1(Vector2D(1.1, 2.1) + Vector2D(1.1, 1.0));
    cout << setprecision(2) << v1 << endl;
    
    v1 += Vector2D(1.1, 1.0);
    cout << setprecision(2) << v1 << endl;
  }

  {
    // subtraction
    Vector2D v1(Vector2D(5.5, 6.1) - Vector2D(1.1, 1.0));
    cout << setprecision(2) << v1 << endl;
    
    v1 -= Vector2D(-1.1, -1.0);
    cout << setprecision(2) << v1 << endl;
  }

  {
    // multiplication
    Vector2D v1(1.1, 2.2);
    cout << 2.0 * v1 << endl;
    cout << v1 * 3.0 << endl;
    v1 *= 4.0;
    cout << v1 << endl;
  }

  {
    // division
    Vector2D v1(8.8, 2.2);
    cout << v1 / 2 << endl;
    try {
      cout << v1 / 0 << endl;
    } catch (const invalid_argument & e) {
      cout << "caught exception" << endl;
    }

    v1 /= 2;
    cout << v1 << endl;
    try {
      v1 /= 0;
      cout << v1 << endl;
    } catch (const invalid_argument & e) {
      cout << "caught exception" << endl;
    }
    cout << v1 << endl;
  }
*/  
}
