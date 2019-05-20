#pragma once
#include "Graph/Graph.hpp"

struct SalesmanProblemSolvedResult {
  std::vector<Edge> path;
  double path_length;
  // In milliseconds.
  double time_taken;
};
