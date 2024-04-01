#include <iostream>
#include <vector>

void dfs(int pos, int parent, std::vector<std::vector<int>>& g, std::vector<bool>& visited) {
    visited[pos] = true;
    for (int i = 0; i < g[pos].size(); ++i) {
        if (parent != g[pos][i]) dfs(g[pos][i], pos, g, visited);
    }
}

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    std::vector<std::vector<int>> g(n, std::vector<int>());
    for (int i = 0; i < n; ++i) {
        int tmp; std::cin >> tmp; --tmp;
        g[i].push_back(tmp);
        g[tmp].push_back(i);
    }

    int cnt = 0;
    std::vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cnt++;
            dfs(i, -1, g, visited);
        }
    }

    std::cout << cnt << '\n';
}