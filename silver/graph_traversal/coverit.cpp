#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

void dfs(int pos, std::vector<std::vector<int>>& g, std::vector<int>& clusters, 
        std::vector<std::vector<int>>& colors, int color, int id) {
    colors[color].push_back(pos);
    clusters[pos] = id;

    for (int i = 0; i < g[pos].size(); ++i) {
        if (clusters[g[pos][i]] == -1) {
            dfs(g[pos][i], g, clusters, colors, 1 - color, id);
        }
    }
}

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, m; std::cin >> n >> m;
        std::vector<std::vector<int>> g(n, std::vector<int>());
        for (int i = 0; i < m; ++i) {
            int u, v; std::cin >> u >> v; --u; --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int id = 0;
        std::vector<int> clusters(n, -1);
        std::vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (clusters[i] == -1) {
                std::vector<std::vector<int>> colors(2, std::vector<int>());
                dfs(i, g, clusters, colors, 0, id);
                id++;
                if (colors[0].size() > colors[1].size()) {
                    for (int j = 0; j < colors[1].size(); ++j) {
                        res.push_back(colors[1][j]);
                    }
                } else {
                    for (int j = 0; j < colors[0].size(); ++j) {
                        res.push_back(colors[0][j]);
                    }
                }
            }
        }

        std::cout << res.size() << '\n';
        for (int i = 0; i < res.size(); ++i) {
            std::cout << 1 + res[i] << ' ';
        }
        std::cout << '\n';
    }
}