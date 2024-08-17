#include <iostream>
#include <vector>
#include <set>

int main() {
    int q, k; std::cin >> q >> k;
    std::vector<int> dp(k + 1, 0);
    dp[0] = 1;


    for (int qq = 0; qq < q; ++qq) {
        char op; std::cin >> op;
        int val; std::cin >> val;
        std::vector<int> new_dp = dp;
        
        if (op == '+') {
            for (int i = 0; i <= k; ++i) {
                if (i + val <= k) {
                    new_dp[i + val] += dp[i];
                    new_dp[i + val] %= 998244353;
                }
            }
        }

        if (op == '-') {
            for (int i = 0; i <= k; ++i) {
                if (i + val <= k && new_dp[i + val] > 0 && new_dp[i] > 0) {
                    new_dp[i + val] -= new_dp[i];
                    if (new_dp[i + val] < 0) {
                        new_dp[i + val] += 998244353;
                    }
                    new_dp[i + val] %= 998244353;
                }
            }
        }
        
        dp = new_dp;
        std::cout << dp.back() << '\n';
    }
}