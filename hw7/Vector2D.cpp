#include "Vector2D.hpp"
#include <stdexcept>

  Vector2D::Vector2D() { m_x = 0; m_y = 0; }
  Vector2D::Vector2D(const Vector2D& v) { m_x = v.getX(); m_y = v.getY(); }
  Vector2D::Vector2D(double d1, double d2) { m_x = d1; m_y = d2; }
 /* Vector2D& Vector2D::operator= (const Vector2D v) {
    m_x = v.getX();
    m_y = v.getY();
    return *this;
  } 
 */

  void Vector2D::setX(double x) {
    m_x = x;
  }
 void Vector2D::setY(double y) {
    m_y = y;
  }

 double Vector2D::getX() const {
   return m_x;
 }
 double Vector2D::getY() const {
   return m_y;
 }


  double& Vector2D::operator[](std::size_t i) {
    if (i == 0) { return m_x; } 
    else if (i == 1) { return m_y; }
    else { throw std::out_of_range("Out of bounds index on Vector2D"); }
  }
/*
  double Vector2D::operator[](std::size_t i) const {
    if (i == 0) { return this->m_x; } else { return this->m_y; }
  }
*/
  void Vector2D::operator= (Vector2D v) {
   m_x = v.getX();
   m_y = v.getY();
  }

  bool Vector2D::operator== (const Vector2D& v) const {
   return ((m_x == v.getX()) && (m_y == v.getY()));
  }

  bool Vector2D::operator!= (const Vector2D& v) const {
   return !((m_x == v.getX()) && (m_y == v.getY()));
  }

  void Vector2D::operator-() {
    m_x *= -1;
    m_y *= -1;
  }

   void Vector2D::operator+= (Vector2D v) {
    m_x += v.getX();
    m_y += v.getY();
  }

  void Vector2D::operator-= (Vector2D v) {
    m_x -= v.getX();
    m_y -= v.getY();
  }

  Vector2D Vector2D::operator+ (Vector2D v)  {
    Vector2D* t = new Vector2D(v.getX()+ m_x, v.getY() + m_y);
    return *t;
  }
 
  Vector2D Vector2D::operator- (Vector2D v) {
     Vector2D* t = new Vector2D(m_x - v.getX(), m_y - v.getY());
     return *t;
  }

  void Vector2D::operator*= (double d)  {
    m_x *= d;
    m_y *= d;
  }

  void Vector2D::operator/= (double d)  {
    if (d == 0) { throw std::invalid_argument("division by 0"); } 
    m_x /= d;
    m_y /= d;
  }

  Vector2D Vector2D::operator* (double d) {
    Vector2D* t = new Vector2D(d* m_x, d * m_y);
    return *t;

  }
  Vector2D Vector2D::operator/ (double d) {
    if (d == 0) { throw std::invalid_argument("division by 0"); }
    Vector2D* t = new Vector2D(m_x / d, m_y / d);
    return *t;
  
  }

 /* std::ostream& Vector2D::operator<<(std::ostream& os) {
    os << m_x << " " << m_y;
    return os;
  }
  */
  std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << v.getX()<< " " << v.getY();
   //
    return os;
  }
 
