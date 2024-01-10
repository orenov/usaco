#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=916

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> g(m, std::vector<int>());
    for (int i = 0; i < m; ++i) {
        int x, y; std::cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < m; ++i) {
        sort(g[i].begin(), g[i].end());
    }

    std::vector<int> x(n, 0);
    for (int i = 0; i < g.size(); ++i) {
        std::set<int> bad;
        for (int j = 0; j < g[i].size(); ++j) {
            bad.insert(x[g[i][j]]);
        }
        int j = 1;
        while (bad.find(j) != bad.end()) j++;
        x[i] = j;
    }

    for (int i = 0; i < x.size(); ++i) {
        std::cout << x[i];
    }
    std::cout << '\n';
}