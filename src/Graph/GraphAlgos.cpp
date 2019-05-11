#include "GraphAlgos.hpp"

double graph_algos::GetPathLength(const std::vector<Edge>& edges) {
  double result = 0;
  for (auto const& edge : edges) {
    result += edge.weight;
  }
  return result;
}

double graph_algos::GetPathLength(const std::vector<size_t>& vertices,
                                  const std::shared_ptr<Graph>& graph, bool cycled) {
  return GetPathLength(GetEdgePath(vertices, graph));
}

std::vector<Edge> graph_algos::GetEdgePath(const std::vector<size_t>& vertices,
                                       const std::shared_ptr<Graph>& graph, bool cycled) {
  std::vector<Edge> path;

  const size_t for_max = cycled ? vertices.size() : vertices.size() - 1;

  for (size_t i = 0; i < for_max; ++i) {
    for (auto const& edge : graph->GetNextEdges(vertices[i])) {
      if (edge.to == vertices[(i + 1) % vertices.size()]) {
        path.push_back(edge);
        break;
      }
    }
  }
  return path;
}
