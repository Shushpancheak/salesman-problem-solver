#pragma once
#include "SalesmanProblemStrategy.hpp"
#include "Graph/ArcGraph.hpp"
#include "GraphAlgorithms/MstBuilderBoruvka.hpp"
#include "Graph/ListGraph.hpp"

class MstStrategy : public SalesmanProblemStrategy {
public:
  SalesmanProblemSolvedResult SolveForGraph(const std::shared_ptr<Graph>& graph) const override;
  
private:
  static std::vector<Edge> GetHamiltonPath(const ListGraph& double_mst_graph,
                                    const std::shared_ptr<Graph>& graph);
};
