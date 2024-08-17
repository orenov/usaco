#include <iostream>
#include <vector>
#include <algorithm>

long long run(int n, std::vector<long long>& dp) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (n == 1) return 1;

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = run(n - 1, dp) + 2 * (n - 1) * run(n - 2, dp);
    dp[n] %= 1000000007;
    return dp[n];
}

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        long long n, k; std::cin >> n >> k;
        for (int i = 0; i < k; ++i) {
            long long u, v; std::cin >> u >> v;
            if (u != v) {
                n -= 2;
            } else {
                n--;
            }
        }
        std::vector<long long> dp(n + 1, -1);

        std::cout << run(n, dp) << '\n';
    }
}