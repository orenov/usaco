#include <iostream>
#include <vector>

int main() {
    int n, x; std::cin >> n >> x;
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i];
    }

    std::vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i <= x; ++i) {
            if (i + c[j] <= x) {
                dp[i + c[j]] += dp[i];
                dp[i + c[j]] %= 1000000007;
            }
        }
    }

    std::cout << dp.back() << '\n';
}