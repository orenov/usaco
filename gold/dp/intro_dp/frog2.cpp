#include <iostream>
#include <vector>

int main() {
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> dp(n, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= k && i + j < n; ++j) {
            dp[i+j] = std::min(dp[i+j], dp[i] + std::abs(a[i] - a[i+j]));
        }
    }

    std::cout << dp.back() << '\n';
}