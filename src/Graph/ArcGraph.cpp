#include "ArcGraph.hpp"
#include <algorithm>

ArcGraph::ArcGraph()
  : arc_list_(0)
  , vertices_count_(0) {}

ArcGraph::ArcGraph(const size_t vertices_count) 
  : arc_list_(0)
  , vertices_count_(vertices_count) {}
  
ArcGraph::ArcGraph(const std::shared_ptr<Graph>& graph) {
  vertices_count_ = graph->GetVerticesCount();
  arc_list_.reserve(vertices_count_);

  for (size_t i = 0; i < vertices_count_; ++i) {
    for (auto& edge : graph->GetNextEdges(i)) {
      arc_list_.push_back(edge); 
    }
  }
}

ArcGraph::~ArcGraph() = default;

size_t ArcGraph::GetVerticesCount() const {
  return vertices_count_;
}

std::vector<Edge> ArcGraph::GetNextEdges(size_t from) const {
  std::vector<Edge> result;
  for (auto& edge : arc_list_) {
    if (edge.from == from) {
      result.push_back(edge);
    }
  }

  return result;
}

std::vector<Edge> ArcGraph::GetEdgesAll() const {
  return arc_list_;
}

void ArcGraph::AddEdge(const Edge& edge) {
  vertices_count_ = std::max({vertices_count_, edge.from, edge.to});
  arc_list_.push_back(edge);
}

void ArcGraph::AddEdge(Edge&& edge) {
  vertices_count_ = std::max({vertices_count_, edge.from, edge.to});
  arc_list_.push_back(std::move(edge));
}
