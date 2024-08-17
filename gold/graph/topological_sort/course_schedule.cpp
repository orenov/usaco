#include <iostream>
#include <vector>

void dfs(int pos, std::vector<std::vector<int>>& g, std::vector<int>& color, std::vector<int>& order) {
    color[pos] = 1;
    for (int i = 0; i < g[pos].size(); ++i) {
        int v = g[pos][i];
        if (color[v] == 1) return;
        if (color[v] == 0) dfs(v, g, color, order);
    }

    color[pos] = 2;
    order.push_back(pos);
}

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    for (int i = 0; i < m; ++i) {
        int a, b; std::cin >> a >> b;
        g[a-1].push_back(b-1);
    }

    std::vector<int> color(n, 0); // 0 - not visited, 1 - in cycle, 2 - visited
    std::vector<int> order;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(i, g, color, order);
        }
    }

    if (order.size() != n) {
        std::cout << "IMPOSSIBLE\n";
    } else {
        for (int i = n -1 ; i >= 0; --i) {
            std::cout << 1 + order[i] << ' ';
        }
        std::cout << '\n';
    }
}