#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>

// https://codeforces.com/contest/1833/problem/E

void dfs(int pos, std::vector<std::vector<int>>& g, std::vector<int>& c, int id) {
    c[pos] = id;
    for (int i = 0; i < g[pos].size(); ++i) {
        if (c[g[pos][i]] == -1) {
            dfs(g[pos][i], g, c, id);
        }
    }
}

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<std::vector<int>> g(n, std::vector<int>());

        for (int i = 0; i < n; ++i) {
            int u; std::cin >> u; --u;
            g[i].push_back(u);
            g[u].push_back(i);
        }

        int id = 0;
        std::vector<int> c(n, -1);
        for (int i = 0; i < n; ++i) {
            if (c[i] == -1) {
                dfs(i, g, c, id);
                id++;
            }
        }

        std::map<int, int> is_open;
        std::vector<int> size(id, 0);
        for (int i = 0; i < n; ++i) {
            size[c[i]]++;
            if (g[i].size() == 1) {
                is_open[c[i]] |= true;
            } else {
                is_open[c[i]] |= false;
            }
        }

        int cnt_open = 0;
        for (auto it = is_open.begin(); it != is_open.end(); ++it) {
            if (it->second || size[it->first] == 2) {
                cnt_open++;
            }
        }

        // total id horovods
        std::cout << std::min(id, id - cnt_open + 1) << ' ' << id << '\n';
    }
}