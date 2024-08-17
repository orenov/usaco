#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> bfs(std::vector<std::vector<int>>& g) {
    int n = g.size();
    std::vector<int> d(n, -1);    
    std::queue<int> q; 
    q.push(0); 
    d[0] = 0;

    while (q.size() > 0) {
        int node = q.front(); q.pop();

        for (int j = 0; j < g[node].size(); ++j) {
            int v = g[node][j];
            if (d[v] == -1) {
                d[v] = d[node] + 1;
                q.push(v);
            }
        }    
    }

    return d;
}

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, m; std::cin >> n >> m;
        std::vector<std::vector<int>> g(n, std::vector<int>());

        for (int i = 0; i < m; ++i) {
            int u, v; std::cin >> u >> v; u--; v--;
            g[u].push_back(v);
        }

        std::vector<int> res(n, INT_MAX);
        std::vector<int> d = bfs(g);
        std::vector<std::vector<int>> order;
        for (int i = 0; i < n; ++i) {
            order.push_back({d[i], i});
        }

        std::sort(order.begin(), order.end());

        for (int i = n - 1; i >= 0; --i) {
            int node = order[i][1];
            res[node] = d[node];
            for (int j = 0; j < g[node].size(); ++j) {
                int to = g[node][j];
                if (d[node] >= d[to]) {
                    res[node] = std::min(res[node], d[to]);
                } else {
                    res[node] = std::min(res[node], res[to]);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            std::cout << res[i] << ' ';
        }
        std::cout << '\n';
    }
}