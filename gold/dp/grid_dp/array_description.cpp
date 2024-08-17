#include <iostream>
#include <vector>

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> dp(n, std::vector<int>(m + 1, 0));

    // first initialize
    if (a[0] == 0) {
        for (int i = 1; i <= m; ++i) dp[0][i] = 1;
    } else {
        dp[0][a[0]] = 1;
    }

    for (int i = 1; i < n; ++i) {
        if (a[i] != 0) {
            dp[i][a[i]] += dp[i-1][a[i]];
            if (a[i] - 1 >= 1) dp[i][a[i]] += dp[i-1][a[i]-1];
            dp[i][a[i]] %= 1000000007;
            if (a[i] + 1 <= m) dp[i][a[i]] += dp[i-1][a[i]+1];
            dp[i][a[i]] %= 1000000007;
        } else {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] += dp[i-1][j];
                if (j != 1) dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= 1000000007;
                if (j != m) dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= 1000000007;
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= m; ++i) {
        res += dp.back()[i];
        res %= 1000000007;
    }

    std::cout << res << '\n';
}