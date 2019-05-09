#include "ListGraph.hpp"
#include <algorithm>

ListGraph::ListGraph(const size_t vertices_count)
  : list_(vertices_count) {}

ListGraph::ListGraph(const std::shared_ptr<Graph>& graph)
  : list_(graph->GetVerticesCount()) {
  const size_t vertices_count = list_.size();

  for (size_t i = 0; i < vertices_count; ++i) {
    list_[i] = graph->GetNextEdges(i);
  }
}

ListGraph::~ListGraph() = default;

size_t ListGraph::GetVerticesCount() const {
  return list_.size();
}

std::vector<Edge> ListGraph::GetNextEdges(size_t from) const {
  return from >= list_.size() ? std::vector<Edge>() : list_[from];
}

void ListGraph::AddEdge(const Edge& edge) {
  if (std::max(edge.from, edge.to) >= list_.size()) {
    return;
  }
  list_[edge.from].push_back(edge);
}

void ListGraph::AddEdge(Edge&& edge) {
  if (std::max(edge.from, edge.to) >= list_.size()) {
    return;
  }
  list_[edge.from].push_back(std::move(edge));
}


