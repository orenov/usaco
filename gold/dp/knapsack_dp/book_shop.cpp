#include <vector>
#include <iostream>

int main() {
    int n, x; std::cin >> n >> x;
    std::vector<int> cost(n, 0);
    std::vector<int> pages(n, 0);

    for (int i = 0; i < n; ++i) std::cin >> cost[i];
    for (int i = 0; i < n; ++i) std::cin >> pages[i];

    std::vector<int> dp(x + 1, -1e9);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = x; j >= 0; --j) {
            if (j - cost[i] >= 0 && dp[j - cost[i]] >= 0) {
                dp[j] = std::max(dp[j], dp[j-cost[i]] + pages[i]);
            }
        }
    }

    int res = dp[0];
    for (int i = 0; i < dp.size(); ++i) {
        res = std::max(dp[i], res);
    }

    std::cout << res << '\n';
}   