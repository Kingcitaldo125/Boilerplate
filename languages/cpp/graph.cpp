#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using graph_t = std::unordered_map<std::string, std::vector<std::string>>;
using matrix_t = std::vector<std::vector<int>>;
using graph_wt =
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>>;
using visited_t = std::unordered_set<std::string>;

std::vector<std::pair<int, int>>
get_von_neumann_neighbors(matrix_t &matrix, const int x, const int y) {
  std::vector<std::pair<int, int>> neighbors;
  const int row_length = static_cast<int>(matrix.at(0).size());
  const int col_length = static_cast<int>(matrix.size());

  for (int i = x - 1; i < x + 2; ++i) {
    if (i < 0 || i == x || i >= row_length) {
      continue;
    }

    neighbors.push_back(std::make_pair(i, y));
  }

  for (int j = y - 1; j < y + 2; ++j) {
    if (j < 0 || j == y || j >= col_length) {
      continue;
    }

    neighbors.push_back(std::make_pair(x, j));
  }

  return neighbors;
}

std::vector<std::pair<int, int>> get_moore_neighbors(matrix_t &matrix,
                                                     const int x, const int y) {
  std::vector<std::pair<int, int>> neighbors;
  const int row_length = static_cast<int>(matrix.at(0).size());
  const int col_length = static_cast<int>(matrix.size());

  for (int i = x - 1; i < x + 2; ++i) {
    for (int j = y - 1; j < y + 2; ++j) {
      if (i < 0 || i == x || i >= row_length) {
        continue;
      }

      if (j < 0 || j == y || j >= col_length) {
        continue;
      }

      neighbors.push_back(std::make_pair(i, j));
    }
  }

  return neighbors;
}

bool bfs(graph_t &graph, const std::string &start, const std::string &end) {
  std::list<std::string> mq;
  visited_t visited;

  mq.push_back(start);

  while (mq.size() > 0) {
    auto front = mq.front();
    mq.pop_front();

    visited.insert(front);

    if (front == end)
      return true;

    for (const auto &neighbor : graph[front]) {
      if (visited.find(neighbor) == visited.end()) {
        mq.push_back(neighbor);
      }
    }
  }

  return false;
}

bool dfs_help(graph_t &graph, visited_t &visited, const std::string &start,
              const std::string &end) {
  if (start == end) {
    return true;
  }

  for (const auto &neighbor : graph[start]) {
    if (visited.find(neighbor) == visited.end()) {
      visited.insert(neighbor);
      return dfs_help(graph, visited, neighbor, end);
    }
  }

  return false;
}

bool dfs(graph_t &graph, const std::string &start, const std::string &end) {
  visited_t visited;
  return dfs_help(graph, visited, start, end);
}

void app1() {
  graph_t graph;

  graph["A"].push_back("B");
  graph["A"].push_back("C");
  graph["B"].push_back("A");
  graph["B"].push_back("C");
  graph["C"].push_back("A");
  graph["C"].push_back("B");

  std::cout << std::boolalpha << bfs(graph, "A", "C") << "\n";
  std::cout << std::boolalpha << bfs(graph, "A", "D") << "\n";

  std::cout << std::boolalpha << dfs(graph, "A", "C") << "\n";
  std::cout << std::boolalpha << dfs(graph, "A", "D") << "\n";
}

void app2() {
  graph_wt graph;

  graph["A"].push_back(std::make_pair(1, "B"));
  graph["A"].push_back(std::make_pair(2, "C"));
  graph["B"].push_back(std::make_pair(1, "A"));
  graph["B"].push_back(std::make_pair(1, "C"));
  graph["C"].push_back(std::make_pair(2, "A"));
  graph["C"].push_back(std::make_pair(1, "B"));
}

int main() { return 0; }
