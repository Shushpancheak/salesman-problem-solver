#pragma once
#include "Miscellaneous/Rectangle.hpp"
#include "Graph/ListGraph.hpp"
#include "Graph/ArcGraph.hpp"
#include "Miscellaneous/Geometry.hpp"
#include "SalesmanProblem.hpp"

class SalesmanProblemBuilder {
public:
  SalesmanProblemBuilder();
  SalesmanProblem GetProblem(
    double height, double width, size_t points_count) const;

private:
  static void FillWithRandomPoints(Rectangle& rect,
                            size_t points_count);
  void ConstructListGraphOnPoints(SalesmanProblem& prob,
                                 const Rectangle& rect) const;
  void FindOptimalPath(SalesmanProblem& problem) const;
};
