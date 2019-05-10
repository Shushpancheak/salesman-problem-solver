#pragma once
#include "SalesmanProblemSolvedResult.hpp"
#include "SalesmanProblem.hpp"

class SalesmanProblemStrategy {
public:
  virtual ~SalesmanProblemStrategy() = 0;

  virtual SalesmanProblemSolvedResult
    SolveForGraph(const std::shared_ptr<Graph>& graph) const;
};
