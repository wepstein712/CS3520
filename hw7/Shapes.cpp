#include "Shapes.hpp"

  std::ostream& Circle::display(std::ostream& os) const{
    os << "Circle(" << m_center.getX() << "; " << m_center.getY() << "; " << m_radius << ")";
    return os;
  }

  void Circle::translate(Vector2D v) {
    m_center += v;
  }
 
 std::ostream& Triangle::display(std::ostream& os) const {
    os << "Triangle(";
    for (int i = 0; i < 3; i++) {
      os << m_points[i].getX() << " " << m_points[i].getY();
      if (i < 2) { os <<  "; "; }
    }
    os << ")";
    return os;
  }

  void Triangle::translate(Vector2D v) {
    for (int i = 0; i < 3; i++) {
      m_points[i] += v; 
    }
  }

    

