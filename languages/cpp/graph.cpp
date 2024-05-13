#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using graph_t = std::unordered_map<std::string, std::vector<std::string>>;
using graph_wt =
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>>;
using visited_t = std::unordered_set<std::string>;

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
