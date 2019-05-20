#include "Geometry.hpp"


double geometry::Sqr(double val) {
  return val * val;
}

double geometry::GetLength(const Point2& p1, const Point2& p2) {
  return sqrt(Sqr(p1.x - p2.x) + Sqr(p1.y - p2.y));
}
