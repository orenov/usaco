#include <iostream>
#include <vector>

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> dp(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        int cnt = 0;
        int top = 0;

        for (int j = i; j < n && j < i + k; ++j) {
            cnt++;
            top = std::max(top, a[j]);
            int score = top * cnt;
            if (j + 1 < n) score += dp[j + 1];
            
            dp[i] = std::max(dp[i], score);
        }
    }

    std::cout << dp[0] << '\n';
}