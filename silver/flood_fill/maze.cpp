#include <iostream>
#include <string>
#include <vector>


void floodfill(int r, int c, std::vector<std::string>& g, std::vector<std::vector<bool>>& visited) {
    if (r < 0 || r >= g.size()) return;
    if (c < 0 || c >= g[0].size()) return;
    if (g[r][c] == '.') {
        g[r][c] = '#';
        return;
    }
    if (g[r][c] == '#') return;
    if (visited[r][c]) return;
    visited[r][c] = true;
    floodfill(r + 1, c, g, visited);
    floodfill(r - 1, c, g, visited);
    floodfill(r, c + 1, g, visited);
    floodfill(r, c - 1, g, visited);
}

void floodfill2(int r, int c, std::vector<std::string>& g, std::vector<std::vector<bool>>& visited, int& ones) {
    if (r < 0 || r >= g.size()) return;
    if (c < 0 || c >= g[0].size()) return;
    if (g[r][c] == '#' || g[r][c] == 'B') return;
    if (visited[r][c]) return;
    if (g[r][c] == 'G') ones--;

    visited[r][c] = true;
    floodfill2(r + 1, c, g, visited, ones);
    floodfill2(r - 1, c, g, visited, ones);
    floodfill2(r, c + 1, g, visited, ones);
    floodfill2(r, c - 1, g, visited, ones);
}

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, m; std::cin >> n >> m;
        std::vector<std::string> g(n, "");
        for (int i = 0; i < n; ++i) std::cin >> g[i];
        int good = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 'G') good++;
            }
        }

        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 'B') {
                    floodfill(i, j, g, visited);
                }
            }
        }

        //for (int i = 0; i < n; ++i) {
        //    std::cout << g[i] << '\n';
        //}

        if (good == 0) {
            std::cout << "YES\n";
            continue;
        }
        if (g.back().back() == '#') {
            std::cout << "NO\n";
            continue;
        }

        std::vector<std::vector<bool>> visited2(n, std::vector<bool>(m, false));
        floodfill2(n - 1, m - 1, g, visited2, good);

        if (good == 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}