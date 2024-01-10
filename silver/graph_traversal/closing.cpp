#include <iostream>
#include <vector>
#include <algorithm>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=644

void dfs(int pos, std::vector<std::vector<int>>& g, std::vector<int>& closed, std::vector<int>& visited, int& found_nodes) {
    if (closed[pos] || visited[pos]) return;
    found_nodes++;
    visited[pos] = true;

    for (int i = 0; i < g[pos].size(); ++i) {
        dfs(g[pos][i], g, closed, visited, found_nodes);
    }
}

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    for (int i = 0; i < m; ++i) {
        int from, to;
        std::cin >> from >> to;
        from--; to--;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    std::vector<int> order(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> order[i];
        order[i]--;
    }
    
    int nodes = n;
    int found_nodes = 0;
    std::vector<int> closed(n, false);
    std::vector<int> visited(n, false);

    dfs(order.back(), g, closed, visited, found_nodes);

    if (found_nodes == nodes) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    for (int i = 0; i < order.size() - 1; ++i) {
        nodes--;
        closed[order[i]] = true;
        found_nodes = 0;
        fill(visited.begin(), visited.end(), false);
        dfs(order.back(), g, closed, visited, found_nodes);
        if (nodes == found_nodes) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}