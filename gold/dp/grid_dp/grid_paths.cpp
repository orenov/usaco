#include <iostream>
#include <vector>
#include <string>


int main() {
    int n; std::cin >> n;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    if (a[0][0] == '*') {
        std::cout << 0 << '\n';
        return 0;
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == '*') continue;
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
            dp[i][j] %= 1000000007;
        }
    }

    std::cout << dp.back().back() << '\n';
}