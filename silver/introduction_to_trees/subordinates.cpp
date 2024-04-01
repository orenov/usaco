#include <iostream>
#include <vector>

void dfs(int pos, std::vector<std::vector<int>>& g, std::vector<int>& res) {
    for (int i = 0; i < g[pos].size(); ++i) {
        dfs(g[pos][i], g, res);
        res[pos] += 1 + res[g[pos][i]];
    }
}

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    for (int i = 1; i <= n - 1; ++i) {
        int j; std::cin >> j; --j;
        if (i != 0) g[j].push_back(i);
    }
    std::vector<int> res(n, 0);    
    dfs(0, g, res);
    
    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';
}