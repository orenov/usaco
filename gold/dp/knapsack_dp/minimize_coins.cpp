#include <iostream>
#include <vector>

int main() {
    int n, x; std::cin >> n >> x;
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i];
    }

    std::vector<int> dp(x + 1, 1e9);
    dp[0] = 0;

    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + c[j] <= x) {
                dp[i + c[j]] = std::min(dp[i + c[j]], dp[i] + 1);
            }
        }
    }

    if (dp.back() == 1e9) {
        std::cout << -1 << '\n';
    } else {
        std::cout << dp.back() << '\n';
    }
}