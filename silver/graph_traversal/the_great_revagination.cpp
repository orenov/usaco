#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=920

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m; std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> g(n, std::vector<std::pair<int, int>>());

    for (int i = 0; i < m; ++i) {
        char c; int u, v;
        std::cin >> c >> u >> v;
        u--; v--;
        g[u].push_back({v, c == 'S'});
        g[v].push_back({u, c == 'S'});
    }

    std::vector<int> colors(n, -1);
    int id = 0;

    for (int i = 0; i < n; ++i) {
        if (colors[i] == -1) {
            std::queue<std::pair<int, int>> q; 
            q.push({i, 1});
            colors[i] = 1;

            while (q.size() > 0) {
                std::pair<int, int> next = q.front(); q.pop();

                for (int j = 0; j < g[next.first].size(); ++j) {
                    int col = g[next.first][j].second ? next.second : (1 - next.second);

                    if (colors[g[next.first][j].first] == -1) {
                        colors[g[next.first][j].first] = col;
                        q.push({g[next.first][j].first, col}); 
                    } else if (colors[g[next.first][j].first] != col) {
                        std::cout << "0\n";
                        return 0;
                    }
                }
            }
            id++;
        }
    }

    std::cout << 1;
    for (int i = 0; i < id; ++i) {
        std::cout << 0;
    }
    std::cout << '\n';
}