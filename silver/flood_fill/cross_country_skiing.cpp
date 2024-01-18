#include <iostream>
#include <vector>
#include <string>

void floodfill(int r, int c, int x, int val_parent, 
        std::vector<std::vector<int>>& g, std::vector<std::vector<int>>& w,
        std::vector<std::vector<bool>>& visited, int& ways) {
    if (r < 0 || r >= g.size()) return;
    if (c < 0 || c >= g[0].size()) return;
    if (visited[r][c]) return;
    if (std::abs(g[r][c] - val_parent) > x) return;
    if (w[r][c] == 1) ways--;
    visited[r][c] = true;

    floodfill(r + 1, c, x, g[r][c], g, w, visited, ways);
    floodfill(r - 1, c, x, g[r][c], g, w, visited, ways);
    floodfill(r, c + 1, x, g[r][c], g, w, visited, ways);
    floodfill(r, c - 1, x, g[r][c], g, w, visited, ways);
}

bool fun(int x, std::vector<std::vector<int>>& g, std::vector<std::vector<int>>& w, int ways, int r, int c) {
    std::vector<std::vector<bool>> visited(g.size(), std::vector<bool>(g[0].size(), false));
    floodfill(r, c, x, g[r][c], g, w, visited, ways);
    return ways == 0;
}

int main() {
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> g(n, std::vector<int>(m, 0));
    std::vector<std::vector<int>> w(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> g[i][j];
        }
    }
    int ways = 0;
    int row = 0;
    int col = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> w[i][j];
            if (w[i][j] == 1) {
                ways++;
                row = i;
                col = j;
            }
        }
    }

    int l = -1;
    int r = 1e9;
    // (l, r] invariant
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (fun(m, g, w, ways, row, col)) {
            r = m;
        } else {
            l = m;
        }
    }

    std::cout << r << '\n';
}