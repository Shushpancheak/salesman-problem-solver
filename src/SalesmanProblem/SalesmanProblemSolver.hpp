#pragma once
#include <memory>
#include "SalesmanProblemStrategy.hpp"
#include "SalesmanProblemSolvedResult.hpp"
#include "SalesmanProblem.hpp"

class SalesmanProblemSolver {
public:
  explicit SalesmanProblemSolver(std::shared_ptr<SalesmanProblemStrategy> strategy);
  SalesmanProblemSolvedResult Solve(const SalesmanProblem& problem) const;

private:
  std::shared_ptr<SalesmanProblemStrategy> strategy_;
};
