#include <vector>
#include <iostream>

int dfs(int pos, int parent, std::vector<std::vector<int>>& g, std::vector<int>& a) {
    int cnt = 0;
    for (int i = 0; i < g[pos].size(); ++i) {
        if (g[pos][i] == parent) continue;
        cnt += dfs(g[pos][i], pos, g, a);
    }
    if (cnt == 0 && a[pos] % 12 == 0) return 0;

    return 12 - (cnt + a[pos]) % 12;
}

int main() {
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> g(n, std::vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v; std::cin >> u >> v; --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        std::vector<int> b = a;
        int val = dfs(i, -1, g, b);
        if (val % 12 == 0 || val == 11) {
            cnt++;
        }
    }
    std::cout << cnt << '\n';
}