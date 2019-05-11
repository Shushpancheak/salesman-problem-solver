#pragma once
#include <vector>
#include "Graph.hpp"
#include <memory>

namespace graph_algos {
  double GetPathLength(const std::vector<Edge>& edges);
  double GetPathLength(const std::vector<size_t>& vertices, 
                       const std::shared_ptr<Graph>& graph,
                       bool cycled = true);
  std::vector<Edge> GetEdgePath(const std::vector<size_t>& vertices,
                            const std::shared_ptr<Graph>& graph,
                            bool cycled = true);
}
