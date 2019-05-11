#include "SimulatedAnnealingStrategy.hpp"
#include "Graph/GraphAlgos.hpp"
#include <chrono>
#include <complex>

SimulatedAnnealingStrategy::SimulatedAnnealingStrategy(const double init_temp, const double min_temp)
  : init_temp_(init_temp)
  , min_temp_(min_temp) {}

SalesmanProblemSolvedResult SimulatedAnnealingStrategy::SolveForGraph(
    const std::shared_ptr<Graph>& graph) const {
  const auto start_time = std::chrono::steady_clock::now();
  std::mt19937 rng(time(nullptr));

  std::vector<size_t> current_path = GetRandomPath(graph, rng);
  double current_length = graph_algos::GetPathLength(current_path, graph);

  double current_temp = init_temp_;
  

  for (size_t i = 0; i < 1000000; ++i) {
    std::vector<size_t> new_path = GetPathWithRandomSwap(current_path, rng);
    const double new_length = graph_algos::GetPathLength(new_path, graph);

    if (new_length < current_length) {
      current_path = new_path;
      current_length = new_length;
    } else {
      const double probability = GetTransitionProbability(new_length - current_length, current_temp);

      if (GetChance(probability, rng)) {
        current_path = new_path;
        current_length = new_length;
      }
    }

    current_temp = LowerTemperature(i);
    if (current_temp <= min_temp_) {
      break;
    }
  }

  const auto end_time = std::chrono::steady_clock::now();

  return {graph_algos::GetEdgePath(current_path, graph), current_length,
          static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count())};
}

double SimulatedAnnealingStrategy::LowerTemperature(const size_t iteration) const {
  return init_temp_ * (0.1 / (iteration * iteration));
}

std::vector<size_t> SimulatedAnnealingStrategy::GetPathWithRandomSwap(
    const std::vector<size_t>& path, std::mt19937& rng) const {
  std::vector<size_t> swapped_path = path;

  const std::uniform_int_distribution<std::mt19937::result_type> distribution(0, path.size() - 1);
  
  const size_t first = distribution(rng);
  const size_t second = distribution(rng);

  std::swap(swapped_path[first], swapped_path[second]);

  return swapped_path;
}

std::vector<size_t> SimulatedAnnealingStrategy::GetRandomPath(
    const std::shared_ptr<Graph>& graph, std::mt19937& rng) const {
  std::vector<size_t> current_path;
  const size_t vertices_count = graph->GetVerticesCount();

  for (size_t i = 0; i < vertices_count; ++i) {
    current_path.push_back(i);
  }

  for (size_t i = 0; i < vertices_count * vertices_count; ++i) {
    current_path = GetPathWithRandomSwap(current_path, rng);
  }

  return current_path;
}

double SimulatedAnnealingStrategy::GetTransitionProbability(const double length_diff,
    const double current_temperature) const {
  return std::exp(- length_diff / current_temperature);
}

bool SimulatedAnnealingStrategy::GetChance(const double probability, std::mt19937& rng) const {
  const std::uniform_real_distribution<double> distribution(0, 1);

  return distribution(rng) <= probability;
}
