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
