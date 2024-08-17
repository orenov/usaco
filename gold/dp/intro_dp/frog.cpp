#include <iostream>
#include <vector>

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> dp(n, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n) dp[i+1] = std::min(dp[i+1], dp[i] + std::abs(a[i] - a[i+1]));
        if (i + 2 < n) dp[i+2] = std::min(dp[i+2], dp[i] + std::abs(a[i] - a[i+2]));
    }

    std::cout << dp.back() << '\n';
}