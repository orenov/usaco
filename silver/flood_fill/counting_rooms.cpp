#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>

void dfs(int r, int c, std::vector<std::string>& g, std::vector<std::vector<bool>>& visited) {
    if (r < 0 || r >= g.size()) return;
    if (c < 0 || c >= g[0].size()) return;
    if (g[r][c] == '#') return;
    if (visited[r][c]) return;
    visited[r][c] = true;
    dfs(r + 1, c, g, visited);
    dfs(r, c + 1, g, visited);
    dfs(r - 1, c, g, visited);
    dfs(r, c - 1, g, visited);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> g(n, "");
    for (int i = 0; i < n; ++i) {
        std::cin >> g[i];
    }
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '.' && !visited[i][j]) {
                dfs(i, j, g, visited);
                cnt++;
            }
        }
    }

    std::cout << cnt << '\n';
}