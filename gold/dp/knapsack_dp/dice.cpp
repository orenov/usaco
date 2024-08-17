#include <iostream>
#include <vector>

int main() {
    int n; std::cin >> n;
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6 && j <= i; ++j) {
            dp[i] += dp[i - j];
            dp[i] %= 1000000007;
        }
    }

    std::cout << dp.back() << '\n';
}