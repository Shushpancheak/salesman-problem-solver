#include "SalesmanProblemBuilder.hpp"
#include "Graph/GraphAlgos.hpp"

void SalesmanProblemBuilder::FillWithRandomPoints(Rectangle& rect, const size_t points_count) {
  for (size_t i = 0; i < points_count; ++i) {
    rect.AddRandomPoint();
  }
}

void SalesmanProblemBuilder::ConstructArcGraphOnPoints(SalesmanProblem& prob, const Rectangle& rect) const {
  const size_t points_count = rect.GetPointsCount();
  std::vector<Point2> points = rect.GetPoints();
  prob.graph = std::make_shared<ListGraph>(points_count);

  for (size_t i = 0; i < points_count; ++i) {
    for (size_t j = i + 1; j < points_count; ++j) {
      prob.graph->AddEdge({i, j, geometry::GetLength(points[i], points[j])});
    }
  }
}

void SalesmanProblemBuilder::FindOptimalPath(SalesmanProblem& problem) const {
  const std::shared_ptr<Graph> graph = problem.graph;
  
  std::vector<size_t> current_permutation;
  for (size_t i = 0; i < graph->GetVerticesCount(); ++i) {
    current_permutation.push_back(i);
  }
  const std::vector<size_t> initial_permutation = current_permutation;
  std::vector<size_t> optimal_vertices = current_permutation;
  double min_length = graph_algos::GetPathLength(current_permutation, graph);

  std::next_permutation(current_permutation.begin(), current_permutation.end());

  while (current_permutation != initial_permutation) {
    const double length = graph_algos::GetPathLength(current_permutation, graph);
    if (length < min_length) {
      min_length = length;
      optimal_vertices = current_permutation;
    }

    std::next_permutation(current_permutation.begin(), current_permutation.end());
  }

  problem.optimal_path = graph_algos::GetPath(optimal_vertices, graph);
  problem.optimal_path_length = min_length;
}

SalesmanProblemBuilder::SalesmanProblemBuilder() = default;

SalesmanProblem SalesmanProblemBuilder::GetProblem(
  const double height, const double width, const size_t points_count) {
  SalesmanProblem problem;
  Rectangle rect(width, height);

  FillWithRandomPoints(rect, points_count);
  ConstructArcGraphOnPoints(problem, rect);
  FindOptimalPath(problem);

  return problem;
}
