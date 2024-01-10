#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=940

void dfs(int pos, std::vector<std::vector<int>>& g, std::vector<bool>& visited) {
    visited[pos] = true;
    for (int i = 0; i < g[pos].size(); ++i) {
        int u = g[pos][i];
        if (visited[u]) continue;
        dfs(u, g, visited);
    }
}

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    std::vector<std::vector<int>> rev_g(n, std::vector<int>());

    for (int i = 0; i < n - 1; ++i) {
        int x, y; std::cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
        rev_g[y].push_back(x);
    }
    
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 0) {
            std::vector<bool> visited(n, false);
            dfs(i, rev_g, visited);
            bool f = true;
            for (int j = 0; j < n; ++j) {
                f &= visited[j];
            }
            if (f) {
                std::cout << i + 1 << '\n';
                return 0;
            }
        }
    }

    std::cout << -1 << '\n';
}