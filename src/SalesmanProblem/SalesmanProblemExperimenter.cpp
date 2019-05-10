#include "SalesmanProblemExperimenter.hpp"
#include "SalesmanProblemExperimentResult.hpp"

void SalesmanProblemExperimenter::Experiment(const size_t vertices_count,
                                             const size_t experiments_count,
                                             double width, double height) {
  std::cout << "#################### EXPERIMENTS WITH N == " << vertices_count << " ####################" << std::endl;
  std::cout << "Starting TSP experiment with vertices count == " << vertices_count <<
               ", and experiments count == " << experiments_count << std::endl;

  SalesmanProblemBuilder problem_builder;
  std::vector<SalesmanProblemExperimentResult> results;

  for (size_t i = 0; i < experiments_count; ++i) {
    std::cout << "- - - - - - " << i << " EXPERIMENT- - - - - - " << std::endl;
    const SalesmanProblem problem = problem_builder.GetProblem(height, width, vertices_count);
    std::cout << "Optimal path length: " << problem.optimal_path_length << std::endl;
    std::cout << "Optimal path: ";
    for (auto& vertex : problem.optimal_path) {
      std::cout << vertex.from << " ";
    }
  }
}
