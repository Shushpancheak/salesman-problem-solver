#pragma once

#include "Graph.hpp"
#include <memory>

class ArcGraph : public Graph {
public:
  explicit ArcGraph(size_t vertices_count);
  ArcGraph(ArcGraph&& graph) = default;
  explicit ArcGraph(const std::shared_ptr<Graph>& graph);
  ~ArcGraph();

  size_t GetVerticesCount() const override;
  // O(n)
  std::vector<Edge> GetNextEdges(size_t from) const override;
  std::vector<Edge> GetEdgesAll() const;
  void AddEdge(const Edge& edge) override;
  void AddEdge(Edge&& edge) override;

private:
  std::vector<Edge> arc_list_;
  size_t vertices_count_;
};
