#pragma once

#include "Graph.hpp"
#include <memory>

class ListGraph : public Graph {
public:
  explicit ListGraph(size_t vertices_count);
  explicit ListGraph(const std::shared_ptr<Graph>& graph);
  ~ListGraph();

  size_t GetVerticesCount() const override;
  std::vector<Edge> GetNextEdges(size_t from) const override;
  void AddEdge(const Edge& edge) override;
  void AddEdge(Edge&& edge) override;

private:
  std::vector<std::vector<Edge>> list_;
};
