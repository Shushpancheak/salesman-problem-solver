#pragma once
#include <vector>

struct Edge {
  size_t from;
  size_t to;

  double weight;
};

// Oriented Graph.
class Graph {
public:
  virtual ~Graph() = default;

  virtual size_t GetVerticesCount() const = 0;
  virtual std::vector<Edge> GetNextEdges(size_t from) const = 0;
  virtual void AddEdge(const Edge& edge) = 0;
  virtual void AddEdge(Edge&& edge) = 0;
};