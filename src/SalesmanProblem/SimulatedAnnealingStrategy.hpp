#pragma once
#include "SalesmanProblemStrategy.hpp"
#include <random>

class SimulatedAnnealingStrategy : public SalesmanProblemStrategy {
public:
  explicit SimulatedAnnealingStrategy(double init_temp = 10.0, double min_temp = 0.00001);
  SalesmanProblemSolvedResult SolveForGraph(const std::shared_ptr<Graph>& graph) const override;

  private:
  double LowerTemperature(size_t iteration) const;
  std::vector<size_t> GetPathWithRandomSwap(
    const std::vector<size_t>& path, std::mt19937& rng) const;
  std::vector<size_t> GetRandomPath(const std::shared_ptr<Graph>& graph, std::mt19937& rng) const;
  double GetTransitionProbability(double length_diff, double current_temperature) const;
  bool GetChance(double probability, std::mt19937& rng) const;

  const double init_temp_;
  const double min_temp_;
};
