#include <iostream>
#include <vector>

int dfs(int pos, int parent, std::vector<std::vector<int>>& g, int& diam) {
    int first = 0;
    int second = 0;

    for (int i = 0; i < g[pos].size(); ++i) {
        if (g[pos][i] == parent) continue;
        int tmp = 1 + dfs(g[pos][i], pos, g, diam);
        if (tmp > first) {
            second = first;
            first = tmp;
        } else if (tmp > second) {
            second = tmp;
        }
    }
    diam = std::max(diam, first + second);
    return first;
}

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v; std::cin >> u >> v; --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int diam = 0;
    dfs(0, -1, g, diam);
    std::cout << diam << '\n';
}