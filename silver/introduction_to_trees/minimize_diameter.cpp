#include <iostream>
#include <vector>

int dfs(int pos, int parent, std::vector<std::vector<int>>& g, int& d) {
    int first = 0;
    int second = 0;
    for (int i = 0; i < g[pos].size(); ++i) {
        if (g[pos][i] == parent) continue;
        int cur = 1 + dfs(g[pos][i], pos, g, d);
        if (cur > first) {
            second = first;
            first = cur;
        } else if (cur > second) {
            second = cur;
        }
    }
    d = std::max(d, first + second);
    return first;
}

int main() {
    int n1; std::cin >> n1;
    std::vector<std::vector<int>> g1(n1, std::vector<int>());
    for (int i = 0; i < n1 - 1; ++i) {
        int u, v; std::cin >> u >> v; --u; --v;
        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    int n2; std::cin >> n2;
    std::vector<std::vector<int>> g2(n2, std::vector<int>());
    for (int i = 0; i < n2 - 1; ++i) {
        int u, v; std::cin >> u >> v; --u; --v;
        g2[u].push_back(v);
        g2[v].push_back(u);
    }

    int d1 = 0;
    dfs(0, -1, g1, d1);
    int d2 = 0;
    dfs(0, -1, g2, d2);

    int res = 1 + d1 / 2 + d2 / 2;
    if (d1 % 2 == 1) res++;
    if (d2 % 2 == 1) res++;

    std::cout << std::max(res, std::max(d1, d2)) << '\n';
}