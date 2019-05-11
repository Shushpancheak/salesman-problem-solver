#pragma once
#include <memory>
#include "Graph/Graph.hpp"

struct SalesmanProblem {
  std::shared_ptr<Graph> graph;
  double optimal_path_length;
  std::vector<Edge> optimal_path;
  // In ms. time taken to find exact optimal path.
  double time_taken;
};
