#pragma once
#include "Graph/ArcGraph.hpp"
#include "Miscellaneous/Dsu.hpp"

struct MinEdge {
  Edge edge;
  size_t id;
};

template<bool DoubleMst>
class MstBuilderBoruvka {
public:
  static ArcGraph BuildMst(const ArcGraph& graph);
private:
  static Edge GetReversed(const Edge& edge);
};

template<bool DoubleMst>
ArcGraph MstBuilderBoruvka<DoubleMst>::BuildMst(const ArcGraph& graph) {
  const size_t vertices_count = graph.GetVerticesCount();
  const size_t kNoneVertex = UINT_MAX;

  Dsu<size_t, kNoneVertex> dsu;
  for (size_t i = 1; i <= vertices_count; ++i) {
    dsu.MakeSet(i);
  }
  std::vector<Edge> edges = graph.GetEdgesAll();

  // Holds information of the min edge of specific set.
  std::unordered_map<size_t, MinEdge> min_edges;

  size_t components_count = vertices_count;
  ArcGraph result(vertices_count);

  while (components_count > 1) {
    for (size_t edge_id = 0; edge_id < edges.size(); ++edge_id) {
      Edge& edge = edges[edge_id];
      size_t leader1 = dsu.FindLeader(edge.from);
      size_t leader2 = dsu.FindLeader(edge.to);
      if (leader1 != leader2) {
        if (!min_edges.count(leader1) || edge.weight < min_edges[leader1].edge.weight) {
          min_edges[leader1] = {edge, edge_id};
        }
        if (!min_edges.count(leader2) || edge.weight < min_edges[leader2].edge.weight) {
          min_edges[leader2] = {edge, edge_id};
        }
      }
    }
    for (auto& min_edge : min_edges) {
      if (dsu.UniteSets(min_edge.second.edge.from, min_edge.second.edge.to)) {
        --components_count;
        if (components_count == 0) {
          break;
        }
        result.AddEdge(min_edge.second.edge);
        if (DoubleMst) {
          result.AddEdge(GetReversed(min_edge.second.edge));
        }
      }
    }
    min_edges.clear();
  }

  return result;
}

template<bool DoubleMst>
Edge MstBuilderBoruvka<DoubleMst>::GetReversed(const Edge& edge) {
  return {edge.to, edge.from, edge.weight};
}
