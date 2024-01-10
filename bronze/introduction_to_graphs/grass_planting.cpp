#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=894

int main() {
    freopen("planting.in", "r", stdin);
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int x, y; std::cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int m = 0;
    for (int i = 0; i < g.size(); ++i) {
        m = std::max(m, 1 + static_cast<int>(g[i].size()));
    }
    freopen("planting.out", "w", stdout);
    std::cout << m << '\n';
}