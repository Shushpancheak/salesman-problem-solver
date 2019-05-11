#include "SalesmanProblemExperimenter.hpp"
#include "SalesmanProblemExperimentResult.hpp"
#include "SalesmanProblemSolver.hpp"
#include "MstStrategy.hpp"

void SalesmanProblemExperimenter::Experiment(const size_t vertices_count,
    const size_t experiments_count, const double width, const double height) const {
  std::cout << std::endl << std::endl <<
    "#################### EXPERIMENTS WITH N == " << vertices_count << " ####################" << std::endl;
  std::cout << "Starting TSP experiment with vertices count == " << vertices_count <<
               ", and experiments count == " << experiments_count << std::endl;

  SalesmanProblemBuilder problem_builder;
  SalesmanProblemSolver problem_solver =
    SalesmanProblemSolver(std::make_shared<MstStrategy>());
  std::vector<SalesmanProblemExperimentResult> results;

  for (size_t i = 0; i < experiments_count; ++i) {
    std::cout << std::endl <<
                 "- - - - - - " << i << " EXPERIMENT- - - - - - " << std::endl;
    const SalesmanProblem problem = problem_builder.GetProblem(height, width, vertices_count);
    std::cout << "Optimal path length: " << problem.optimal_path_length << std::endl;
    std::cout << "Optimal path: ";
    for (auto& vertex : problem.optimal_path) {
      std::cout << vertex.from << " ";
    }
    std::cout << std::endl;
    std::cout << "Time taken: " << problem.time_taken << " ms." << std::endl;

    const auto solved_result = problem_solver.Solve(problem);

    std::cout << std::endl << "Calculated path length: " <<
                 solved_result.path_length << std::endl;
    std::cout << "Path: ";
    for (auto& vertex : solved_result.path) {
      std::cout << vertex.from << " ";
    }
    std::cout << std::endl;
    std::cout << "Time taken to calculate: " << solved_result.time_taken << " ms." << std::endl;

    std::cout << std::endl << "So, calculated path is " <<
      solved_result.path_length / problem.optimal_path_length <<
      " times longer than optimal." << std::endl;

    results.push_back({problem.optimal_path_length, solved_result.path_length});
  }

  std::cout << std::endl << std::endl;
  std::cout << "==== EXPERIMENTS RESULTS WITH N == " << vertices_count << " ====" << std::endl;

  double average_quality = 0;
  for (auto& result : results) {
    average_quality += result.calculated_path_length / result.optimal_path_length;
  }
  average_quality /= results.size();

  double standard_deviation = 0;
  for (auto& result : results) {
    standard_deviation += geometry::Sqr(
        result.calculated_path_length / result.optimal_path_length - average_quality);
  }
  standard_deviation /= results.size();
  standard_deviation = sqrt(standard_deviation);

  std::cout << "Average quality: " << average_quality << std::endl;
  std::cout << "Standard deviation: " << standard_deviation << std::endl;
}
