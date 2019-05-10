#include "MstStrategy.hpp"
#include "Miscellaneous/Geometry.hpp"
#include "Graph/GraphAlgos.hpp"
#include <chrono>


SalesmanProblemSolvedResult MstStrategy::SolveForGraph(
    const std::shared_ptr<Graph>& graph) const {
  const auto start_time = std::chrono::steady_clock::now();

  const ArcGraph arc_graph(graph);
  const std::shared_ptr<Graph> arc_mst =
    std::make_shared<ArcGraph>(MstBuilderBoruvka<true>::BuildMst(arc_graph));
  const ListGraph mst_graph = ListGraph(arc_mst);

  const std::vector<Edge> path = GetHamiltonPath(mst_graph);

  const auto end_time = std::chrono::steady_clock::now();

  return {path, graph_algos::GetPathLength(path),
    std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()};
}

std::vector<Edge> MstStrategy::GetHamiltonPath(const ListGraph& double_mst_graph) const {
  std::vector<size_t> vertices_path;
  std::vector<char> visited(double_mst_graph.GetVerticesCount());

  size_t cur_vertex = 0;
  visited[0] = true;

  // DFS
  while (true) {
    std::vector<Edge> next_edges = double_mst_graph.GetNextEdges()
  }
}
