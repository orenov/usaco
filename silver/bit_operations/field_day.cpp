#include <iostream>
#include <vector>

int main() {
    int n, c; std::cin >> c >> n;
    std::vector<int> teams(n, 0);
    std::vector<int> dp(1 << c, -1e9);

    for (int i = 0; i < n; ++i) {
        int k = 0;
        while (k < c) {
            char ch; std::cin >> ch;
            if (ch == 'G') teams[i] |= 1 << k;
            ++k;
        }
        dp[teams[i]] = 0;
    }

    for (int i = 0; i < c; ++i) {
        std::vector<int> new_dp = dp;
        for (int mask = 0; mask < 1 << c; ++mask) {
            if (dp[mask] != -1e9) {
                new_dp[mask ^ (1 << i)] = std::max(dp[mask ^ (1 << i)], dp[mask] + 1);
            }
        }
        dp = new_dp;
    }
    
    for (int i = 0; i < n; ++i) {
        std::cout << dp[teams[i]] << '\n';
    }

}