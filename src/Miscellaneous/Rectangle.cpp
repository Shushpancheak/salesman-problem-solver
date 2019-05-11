#include "Rectangle.hpp"
#include <random>
#include <ctime>

Rectangle::Rectangle(const double width, const double height)
  : points_(0)
  , size_{width, height}
  , random_generator_(time(nullptr))
  , x_distribution_(width / 2)
  , y_distribution_(height / 2) {}

Rectangle::~Rectangle() = default;

size_t Rectangle::GetPointsCount() const {
  return points_.size();
}

std::vector<Point2> Rectangle::GetPoints() const {
  return points_;
}

void Rectangle::AddRandomPoint() {
  points_.push_back({x_distribution_(random_generator_),
                     y_distribution_(random_generator_)});
}
