#include <iostream>
#include <vector>
#include <iomanip>

void dfs(int pos, int parent, std::vector<std::vector<int>>& g, std::vector<double>& res, double prob, int len) {
    if (g[pos].size() == 1 && pos != 0) {
        res.push_back(prob * len);
        return;
    }

    int p = g[pos].size();
    if (pos != 0) p--;

    for (int i = 0; i < g[pos].size(); ++i) {
        if (g[pos][i] != parent) dfs(g[pos][i], pos, g, res, prob / p, len + 1);
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

    std::vector<double> res;
    dfs(0, -1, g, res, 1.0, 0);

    double ans = 0.0;
    for (int i = 0; i < res.size(); ++i) {
        ans += res[i];
    }

    std::cout << std::setprecision(8) << ans << '\n';
}