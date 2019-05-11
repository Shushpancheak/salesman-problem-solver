#include "GraphAlgos.hpp"

double graph_algos::GetPathLength(const std::vector<Edge>& edges) {
  double result = 0;
  for (auto const& edge : edges) {
    result += edge.weight;
  }
  return result;
}

double graph_algos::GetPathLength(const std::vector<size_t>& vertices,
                                  const std::shared_ptr<Graph>& graph) {
  return GetPathLength(GetPath(vertices, graph));
}

std::vector<Edge> graph_algos::GetPath(const std::vector<size_t>& vertices,
                                       const std::shared_ptr<Graph>& graph) {
  std::vector<Edge> path;
  for (size_t i = 0; i < vertices.size(); ++i) {
    for (auto const& edge : graph->GetNextEdges(vertices[i])) {
      if (edge.to == vertices[(i + 1) % vertices.size()]) {
        path.push_back(edge);
        break;
      }
    }
  }
  return path;
}
