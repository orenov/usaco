#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=944

void dfs(int pos, std::vector<std::vector<int>>& g, std::vector<int>& c, int id) {
    c[pos] = id;
    for (int i = 0; i < g[pos].size(); ++i) { 
        if (c[g[pos][i]] == -1) {
            dfs(g[pos][i], g, c, id);
        }
    }
}

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n, m; std::cin >> n >> m;
    
    std::vector<std::vector<int>> a(n, std::vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][0] >> a[i][1];
    }

    std::vector<std::vector<int>> g(n, std::vector<int>());
    for (int i = 0; i < m; ++i) {
        int u,v; std::cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int id = 0;
    std::vector<int> c(n, -1);
    for (int i = 0; i < n; ++i) {
        if (c[i] == -1) {
            dfs(i, g, c, id);
            id++;
        }
    }

    std::map<int, int> xmax, xmin, ymax, ymin;
    for (int i = 0; i < id; ++i) {
        xmax[i] = 0;
        xmin[i] = 1e9;
        ymax[i] = 0;
        ymin[i] = 1e9;
    }

    for (int i = 0; i < n; ++i) {
        xmax[c[i]] = std::max(xmax[c[i]], a[i][0]);
        xmin[c[i]] = std::min(xmin[c[i]], a[i][0]);
        ymax[c[i]] = std::max(ymax[c[i]], a[i][1]);
        ymin[c[i]] = std::min(ymin[c[i]], a[i][1]);
    }

    int p = 1e9;
    for (int i = 0; i < id; ++i) {
        int x = xmax[i] - xmin[i];
        int y = ymax[i] - ymin[i];
        p = std::min(p, 2 * x + 2 * y);
    }

    std::cout << p << '\n';
}