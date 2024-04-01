#include <iostream>
#include <vector>

struct Edge {
    int from, to, rel;
    Edge(int from, int to, int rel) : from(from), to(to), rel(rel) {}
};

int dfs(int pos, int parent, std::vector<std::vector<Edge>>& g, int r) {
    int cnt = 1;
    for (int i = 0; i < g[pos].size(); ++i) {
        if (g[pos][i].to != parent && g[pos][i].rel >= r) cnt += dfs(g[pos][i].to, pos, g, r);
    }
    return cnt;
}

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, q; std::cin >> n >> q;
    std::vector<std::vector<Edge>> g(n, std::vector<Edge>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v, r; std::cin >> u >> v >> r;
        --u; --v;
        g[u].push_back(Edge(u, v, r));
        g[v].push_back(Edge(v, u, r));
    }

    for (int i = 0; i < q; ++i) {
        int r, x; std::cin >> r >> x;
        x--;
        std::cout << dfs(x, -1, g, r) - 1 << '\n';
    }
}