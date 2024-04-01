#include <iostream>
#include <vector>

void dfs(int pos, int parent, std::vector<std::vector<int>>& g, std::vector<int>& cc, std::string& s, int id) {
    cc[pos] = id;
    for (int i = 0; i < g[pos].size(); ++i) {
        if (g[pos][i] == parent) continue;
        if (s[g[pos][i]] != s[pos]) continue;
        dfs(g[pos][i], pos, g, cc, s, id);
    }
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int n, m; std::cin >> n >> m;
    std::string s; std::cin >> s;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v; std::cin >> u >> v; --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::vector<int> cc(n, -1); // node -> component
    int id = 0;
    for (int i = 0; i < n; ++i) {
        if (cc[i] == -1) {
            dfs(i, -1, g, cc, s, id);
            id++;
        }
    }

    for (int i = 0; i < m; ++i) {
        int u, v; char c; std::cin >> u >> v >> c; --u; --v;
        if (cc[u] != cc[v]) {
            std::cout << 1;
        } else if (s[u] == c || s[v] == c) {
            std::cout << 1;
        } else {
            std::cout << 0;
        }
    }
}