#include "MstStrategy.hpp"
#include "Miscellaneous/Geometry.hpp"
#include "Graph/GraphAlgos.hpp"
#include <chrono>
#include <stack>


SalesmanProblemSolvedResult MstStrategy::SolveForGraph(
    const std::shared_ptr<Graph>& graph) const {
  const auto start_time = std::chrono::steady_clock::now();

  const ArcGraph arc_graph(graph);
  const std::shared_ptr<Graph> arc_mst =
    std::make_shared<ArcGraph>(MstBuilderBoruvka<true>::BuildMst(arc_graph));
  const ListGraph mst_graph = ListGraph(arc_mst);

  const std::vector<Edge> path = GetHamiltonPath(mst_graph, graph);

  const auto end_time = std::chrono::steady_clock::now();

  return {path, graph_algos::GetPathLength(path),
    static_cast<double>(
       std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count())};
}

std::vector<Edge> MstStrategy::GetHamiltonPath(const ListGraph& double_mst_graph,
                                               const std::shared_ptr<Graph>& graph) {
  const size_t vertices_count = double_mst_graph.GetVerticesCount();
  std::vector<size_t> vertices_path;
  std::vector<int> prev(vertices_count, -1);
  std::vector<size_t> cur_next(vertices_count, 0);
  std::vector<char> visited(double_mst_graph.GetVerticesCount());
  size_t cur_vertex = 0;
  vertices_path.push_back(0);
  prev[0] = 0;
  visited[0] = true;

  // DFS
  std::stack<size_t> dfs_stack;
  dfs_stack.push(0);
  while (!dfs_stack.empty()) {
    cur_vertex = dfs_stack.top();
    std::vector<Edge> next_edges = double_mst_graph.GetNextEdges(cur_vertex);

    if (!visited[cur_vertex]) {
      visited[cur_vertex] = true;
      vertices_path.push_back(cur_vertex);
    }
    if (cur_next[cur_vertex] >= next_edges.size()) {
      dfs_stack.pop();
      continue;
    }
    if (prev[cur_vertex] == next_edges[cur_next[cur_vertex]].to) {
      ++cur_next[cur_vertex];
      continue;
    }

    dfs_stack.push(next_edges[cur_next[cur_vertex]].to);
    prev[next_edges[cur_next[cur_vertex]].to] = cur_vertex;
    ++cur_next[cur_vertex];
  }

  vertices_path.push_back(0);

  return graph_algos::GetPath(vertices_path, graph);
}
