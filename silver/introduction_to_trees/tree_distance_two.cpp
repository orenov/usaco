#include <iostream>
#include <vector>

void dfs1(int pos, int parent, int64_t d, 
        std::vector<std::vector<int>>& g,
        std::vector<int>& cnt,
        std::vector<int64_t>& dist) 
{
    cnt[pos]++;
    dist[pos] = d;
    for (int i = 0; i < g[pos].size(); ++i) {
        if (g[pos][i] == parent) continue;
        dfs1(g[pos][i], pos, d + 1, g, cnt, dist);
        cnt[pos] += cnt[g[pos][i]];
    }
}

void dfs2(int pos, int parent, 
        std::vector<std::vector<int>>& g,
        std::vector<int>& cnt,
        std::vector<int64_t>& res) 
{
    if (pos != 0) res[pos] = res[parent] + (cnt.size() - cnt[pos]) - cnt[pos];
    for (int i = 0; i < g[pos].size(); ++i) {
        if (g[pos][i] == parent) continue;
        dfs2(g[pos][i], pos, g, cnt, res);
    }
}

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v; std::cin >> u >> v; --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::vector<int> cnt(n, 0);
    std::vector<int64_t> dist(n, 0);
    dfs1(0, -1, 0, g, cnt, dist);
    std::vector<int64_t> res(n, 0);
    for (int i = 0; i < n; ++i) {
        res[0] += dist[i];
    }

    dfs2(0, -1, g, cnt, res);

    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';
}