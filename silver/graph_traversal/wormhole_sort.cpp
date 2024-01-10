#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=992

struct Edge {
    int from, to, weight;
    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};

void dfs(int pos, std::vector<std::vector<Edge>>& g, std::vector<int>& cc, int id) {
    cc[pos] = id;
    for (int i = 0; i < g[pos].size(); ++i) {
        if (cc[g[pos][i].to] == -1) {
            dfs(g[pos][i].to, g, cc, id);
        }
    }
}

bool run(std::vector<int>& p, std::vector<std::vector<Edge>>& g, int x) {
    std::vector<int> cc(p.size(), -1);
    std::vector<std::vector<Edge>> g2(p.size(), std::vector<Edge>());
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            if (g[i][j].weight >= x) {
                g2[i].push_back(g[i][j]);
            }
        }
    }

    int id = 0;
    for (int i = 0; i < cc.size(); ++i) {
        if (cc[i] == -1) {
            dfs(i, g2, cc, id);
            id++;
        }
    }


    //for (int i = 0; i < cc.size(); ++i) {
    //    std::cout << cc[i] << ' ';
    //}
    //std::cout << '\n';


    for (int i = 0; i < p.size(); ++i) {
        if (cc[i] != cc[p[i]]) {
            return false;
        }
    }

    return true;
}

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    
    int n, m; std::cin >> n >> m;
    std::vector<int> p(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        p[i]--;
    }

    std::vector<std::vector<Edge>> g(n, std::vector<Edge>());
    for (int i = 0; i < m; ++i) {
        int u, v, w; 
        std::cin >> u >> v >> w;
        u--;v--;
        g[u].push_back(Edge(u, v, w));
        g[v].push_back(Edge(v, u, w));
    }

    int l = -1;
    int r = 1e9 + 2;
    // true, true, false, false
    // [l, r) invariant
    while (l + 1 < r) {
        int m = (l + r) / 2;
        //std::cout << l << ' ' << m << ' ' << r << '\n';
        if (run(p, g, m)) {
            l = m;
        } else {
            r = m;
        }
    }

    if (l == 1e9 + 1) l = -1;
    std::cout << l << '\n';
}