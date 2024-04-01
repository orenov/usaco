#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <string>
#include <set>

void dfs(int pos, std::vector<std::vector<int>>& g, std::vector<int>& color, bool& is_good) {
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (color[to] == color[pos]) {
            is_good = false;
        }
        if (color[to] == -1) {
            color[to] = 1 - color[pos];
            dfs(g[pos][i], g, color, is_good);
        }
    }
}

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> g(n, std::vector<int>());

    for (int i = 0; i < m; ++i) {
        int from, to;
        std::cin >> from >> to;
        from--; to--;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    std::vector<int> color(n, -1);
    bool is_good = true;
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            color[i] = 1;
            dfs(i, g, color, is_good);
        }
    }
    
    if (!is_good) {
        std::cout << "IMPOSSIBLE\n";
    }

    for (int i = 0; i < n; ++i) {
        std::cout << color[i] + 1 << ' ';
    }
    std::cout << '\n';
}
