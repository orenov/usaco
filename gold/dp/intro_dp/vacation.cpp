#include <vector>
#include <iostream>

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(3, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> a[i][j];
        }
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(3, 2e9));
    //
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = a[i][0] + std::max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = a[i][1] + std::max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = a[i][2] + std::max(dp[i-1][0], dp[i-1][1]);
    }

    std::cout << std::max(dp.back()[0], std::max(dp.back()[1], dp.back()[2])) << '\n';
}