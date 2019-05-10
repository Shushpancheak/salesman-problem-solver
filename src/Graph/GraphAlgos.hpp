#pragma once
#include <vector>
#include "Graph.hpp"
#include <memory>

namespace graph_algos {
  double GetPathLength(const std::vector<Edge>& edges);
  double GetPathLength(const std::vector<size_t>& vertices, 
                       const std::shared_ptr<Graph>& graph);
  std::vector<Edge> GetPath(const std::vector<size_t>& vertices,
                            const std::shared_ptr<Graph>& graph);
}
