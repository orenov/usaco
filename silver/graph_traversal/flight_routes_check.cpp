#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <string>
#include <set>

// https://cses.fi/problemset/task/1682

void dfs(int pos, std::vector<std::vector<int>>& g, std::vector<bool>& visited, int& cnt) {
    visited[pos] = true;
    cnt++;

    for (int i = 0; i < g[pos].size(); ++i) {
        if (!visited[g[pos][i]]) {
            dfs(g[pos][i], g, visited, cnt);
        }
    }
}

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    std::vector<std::vector<int>> g_rev(n, std::vector<int>());

    for (int i = 0; i < m; ++i) {
        int from, to;
        std::cin >> from >> to;
        from--; to--;
        g[from].push_back(to);
        g_rev[to].push_back(from);
    }

    std::vector<bool> visited(n, false);
    int cnt = 0;
    dfs(0, g, visited, cnt);
    
    if (cnt != n) {
        std::cout << "NO\n";
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                std::cout << 1 << ' ' << i + 1 << '\n';
                return 0;
            }
        }
    }

    std::vector<bool> visited2(n, false);
    int cnt2 = 0;
    dfs(0, g_rev, visited2, cnt2);

    if (cnt2 != n) {
        std::cout << "NO\n";
        for (int i = 0; i < n; ++i) {
            if (!visited2[i]) {
                std::cout << i + 1 << ' ' << 1 << '\n';
                return 0;
            }
        }
    }

    std::cout << "YES\n";
}
