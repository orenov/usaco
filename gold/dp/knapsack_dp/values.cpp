#include <iostream>
#include <vector>

int main() {
    int n, k; std::cin >> n >> k;
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) std::cin >> c[i];

    // dp[i][j][k] = true/false
    // means
    // use only first i-th elements
    // to form sum equal to j
    // that has subset equal to k
    // 
    std::vector<std::vector<bool>> dp(k+1, std::vector<bool>(k+1, false));
    dp[0][0] = true;

    for (int i = 0; i < n; ++i) {
        std::vector<std::vector<bool>> new_dp = dp;

        for (int j = 0; j <= k; ++j) {
            bool flag = false;
            for (int q = 0; q <= k; ++q) {
                if (dp[j][q] && j + c[i] <= k) {
                    flag = true;
                }

                if (dp[j][q] && j + c[i] <= k && flag) {
                    new_dp[j + c[i]][q] = true;
                }
                
                if (dp[j][q] && j + c[i] <= k && q + c[i] <= k && flag) {
                    new_dp[j + c[i]][q + c[i]] = true;
                }
            }
        }

        dp = new_dp;
    }

    std::vector<int> res;
    for (int i = 0; i <= k; ++i) {
        if (dp.back()[i]) {
            res.push_back(i);
        }
    }

    std::cout << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';
}