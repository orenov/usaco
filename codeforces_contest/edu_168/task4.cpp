#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

int dfs(int pos, std::vector<std::vector<int>>& g, std::vector<int>& a) {
    if (g[pos].size() == 0) {
        return a[pos];
    }

    int min_val = 2e9;
    for (int i = 0; i < g[pos].size(); ++i) {
        min_val = std::min(min_val, dfs(g[pos][i], g, a));
    }

    if (pos == 0) {
        return min_val + a[pos];
    }

    if (min_val < a[pos]) {
        return min_val;
    }

    return (min_val + a[pos]) / 2;
}

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<int> a(n);
        std::vector<std::vector<int>> g(n, std::vector<int>());

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        for (int i = 1; i < n; ++i) {
            int tmp; std::cin >> tmp; tmp--;
            g[tmp].push_back(i);
        }

        std::cout << dfs(0, g, a) << '\n';
    }
}