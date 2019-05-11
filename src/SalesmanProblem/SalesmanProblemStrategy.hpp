#pragma once
#include "SalesmanProblemSolvedResult.hpp"
#include "SalesmanProblem.hpp"

class SalesmanProblemStrategy {
public:
  virtual ~SalesmanProblemStrategy() = default;

  virtual SalesmanProblemSolvedResult
    SolveForGraph(const std::shared_ptr<Graph>& graph) const = 0;
};
