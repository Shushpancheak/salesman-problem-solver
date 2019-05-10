#include "SalesmanProblemSolver.hpp"
#include <utility>

SalesmanProblemSolver::SalesmanProblemSolver(
    std::shared_ptr<SalesmanProblemStrategy> strategy)
  : strategy_(std::move(strategy)) {}

SalesmanProblemSolvedResult SalesmanProblemSolver::Solve(
    const SalesmanProblem& problem) const {
  return strategy_->SolveForGraph(problem.graph);
}
