#pragma once
#include <vector>
#include "Point2.hpp"
#include <random>

class Rectangle {
public:
  Rectangle(double width, double height);
  ~Rectangle();

  size_t GetPointsCount() const;
  std::vector<Point2> GetPoints() const;
  void AddRandomPoint();

private:
  std::vector<Point2> points_;
  Vector2 size_;

  std::default_random_engine random_generator_;
  std::normal_distribution<double> x_distribution_;
  std::normal_distribution<double> y_distribution_;
};
