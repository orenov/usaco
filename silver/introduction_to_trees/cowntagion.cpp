#include <vector>
#include <iostream>

void dfs(int pos, int parent, std::vector<std::vector<int>>& g, int& cnt) {
    int need = g[pos].size();
    if (parent == -1) need++;
    int cur = 1;
    while (cur < need) {
        cur *= 2;
        cnt++;
    }

    for (int i = 0; i < g[pos].size(); ++i) {
        if (g[pos][i] == parent) continue;
        dfs(g[pos][i], pos, g, cnt);
        cnt++;
    }
}

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v; std::cin >> u >> v; --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt = 0;
    dfs(0, -1, g, cnt);
    std::cout << cnt << '\n';
}