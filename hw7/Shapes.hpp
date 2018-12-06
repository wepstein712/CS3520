#ifndef SHAPES_H
#define SHAPES_H

#include "Vector2D.hpp"
#include <ostream>

/*
 * Interface for a polymorphic shape.
 *
 * Should not be possible to instatiate, copy, or move.
 * IShape must be a C++ interface-style class (no member variables; member functions have no implementations).
 *
 * Given IShape * o, Vector2D v, std::ostream os, the following should be defined:
 *  o->display(os): streams shape description (not followed by a newline) to given stream and returns stream
 *  o->translate(v): translates shape by v
 */
class IShape {
public:
  IShape(const IShape&) = delete;
  void operator=(const IShape&) = delete;

  virtual std::ostream& display(std::ostream& os) const {};
  virtual void translate(Vector2D v) {};

private:
 //nothing cause abstract
 
};





/*
 * Circle shape class; subclass of IShape.
 *
 * Should not be possible to copy or assign.
 *
 * Circle display format "Circle(cx cy; radius)"
 */
class Circle : public IShape {
public:
  Circle(Circle & c) = delete;
  void operator=(const Circle c) = delete;

  //no instructions for constructing circle, left to defaults

  std::ostream& display(std::ostream& os) const; 
  void translate(Vector2D v);

private:
  Vector2D m_center; // center point of circle
  double m_radius; // radius of circle
};





/*
 * Triangle shape class; subclass of IShape.
 *
 * Stores the points in a dynamically allocated array.
 *
 * Should not be possible to copy or move.
 *
 * Triangle display format: "Triangle(ax ay; bx by; cx cy)"
 */
class Triangle : public IShape {
public:
  Triangle(Triangle& c) = delete;
  void operator=(const Triangle&) = delete;
 
 // constructors not specified in instructions
 

  std::ostream& display(std::ostream& os) const;
  void translate(Vector2D v);

private:
  Vector2D * m_points; // pointer to dynamic length-three array containing points
};

#endif
