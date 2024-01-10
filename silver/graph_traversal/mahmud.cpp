#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>
#include <string>

// https://codeforces.com/contest/862/problem/B

void dfs(int pos, std::vector<std::vector<int>>& g, int parent, int color, std::vector<long long>& cnt) {
    cnt[color]++;
    for (int i = 0; i < g[pos].size(); ++i) {
        if (g[pos][i] != parent) {
            dfs(g[pos][i], g, pos, 1 - color, cnt);
        }
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

    std::vector<long long> cnt(2, 0);
    dfs(0, g, -1, 0, cnt);
    std::cout << cnt[0] * cnt[1] - (n - 1) << '\n';
}
