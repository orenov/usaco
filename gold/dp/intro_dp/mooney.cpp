#include <iostream>
#include <vector>

int main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    int n, m, c;
    std::cin >> n >> m >> c;
    std::vector<int> score(n);
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> score[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }

    std::vector<int> dp(n, -1e9);
    int res = 0;
    int round = 0;

    dp[0] = 0;
    int k = 1000;
    while (k > 0) {
        std::vector<int> new_dp = dp;

        for (int i = 0; i < n; ++i) {
            if (dp[i] == -1e9) continue;

            for (int j = 0; j < g[i].size(); ++j) {
                int to = g[i][j];
                new_dp[to] = std::max(new_dp[to], dp[i] + score[to]);
            }
        }
        dp = new_dp;
        round++;
        res = std::max(res, dp[0] - c * round * round);
        --k;
    }

    std::cout << res << '\n';
}