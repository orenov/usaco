#include <iostream>
#include <vector>


int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    std::vector<int> dp(n);
    // initialize
    {
        int mmax = 0;
        int ssum = 0;
        int cnt = 0;
        // only for i = 1
        for (int j = n - 1; j >= 0; --j) {
            mmax = std::max(mmax, a[j]);
            ssum += a[j];
            cnt++;

            dp[j] = mmax * cnt - ssum; 
        }
    }

    //k--;
    while (k > 0) {
        std::vector<int> new_dp = dp;
        for (int i = 0; i < n; ++i) {
            int mmax = 0;
            int ssum = 0;
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                mmax = std::max(mmax, a[j]);
                ssum += a[j];
                cnt++;
                int add = 0;
                if (j + 1 < n) add = dp[j + 1];
                new_dp[i] = std::min(new_dp[i], mmax * cnt - ssum + add);
            }
        }

        dp = new_dp;
        k--;
    }

    std::cout << dp[0] << '\n';
}