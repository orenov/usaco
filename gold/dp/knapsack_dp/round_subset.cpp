#include <iostream>
#include <vector>
#include <climits>

int count5(long long val) {
    int cnt = 0;
    while (val % 5 == 0) {
        cnt++;
        val /= 5;
    }
    return cnt;
}

int count2(long long val) {
    int cnt = 0;
    while (val % 2 == 0) {
        cnt++;
        val /= 2;
    }
    return cnt;
}


int main() {
    int n, k; std::cin >> n >> k;
    std::vector<std::vector<int>> a(n, std::vector<int>(2, 0));

    for (int i = 0; i < n; ++i) {
        long long val; std::cin >> val;
        a[i] = {count5(val), count2(val)};
    }

    std::vector<std::vector<int>> dp(k + 1, std::vector<int>(30 * n, INT_MIN));
    dp[0][0] = 0;
    // dp[i][j] 
    // i - 1.. k - cnt
    // j - #number of 5th
    // dp[i][j] - sum of #2

    for (int q = 0; q < n; ++q) {
        std::vector<std::vector<int>> new_dp = dp;
        int cnt5 = a[q][0];
        int cnt2 = a[q][1];

        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < dp[i].size(); ++j) {
                if (dp[i][j] >= 0 && i != dp.size() - 1) {
                    new_dp[i+1][j+cnt5] = std::max(new_dp[i+1][j+cnt5], dp[i][j] + cnt2);
                }
            }
        }

        dp = new_dp;
    }

    int res = 0;
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            if (dp[i][j] >= 0) res = std::max(res, std::min(j, dp[i][j]));
        }
    }

    std::cout << res << '\n';
}