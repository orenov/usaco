#include <iostream>
#include <vector>


int mod = 1000000007;

long long mod_exp(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;

    long long val = mod_exp(a, b / 2);
    val = (val * val) % mod;
    if (b % 2 == 1) {
        val = (val * a) % mod;
    }

    return val;
}

int main() {
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);

    int n, m, k; std::cin >> n >> m >> k;

    std::vector<std::vector<int>> words(n, std::vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        std::cin >> words[i][0] >> words[i][1];
        // length -> class
    }

    std::vector<int> a(26, 0);
    for (int i = 0; i < m; ++i) {
        char c; std::cin >> c;
        a[c - 'A']++;
    }

    // combinations cnt

    std::vector<int> cnt(n + 1, 0);
    std::vector<int> dp(k + 1, 0);
    dp[0] = 1;
    
    for (int i = 0; i <= k; ++i) {
        std::vector<int> new_dp = dp;
        for (int j = 0; j < n; ++j) {
            if (i + words[j][0] > k) continue;

            new_dp[i + words[j][0]] += dp[i];
            new_dp[i + words[j][0]] %= mod;

            if (i + words[j][0] == k) {
                cnt[words[j][1]] += dp[i];
                cnt[words[j][1]] %= mod;
            }
        }
        dp = new_dp;
    }

    // endings count
    // maximum 26
    // classes maximum 5000
    long long res = 1;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 0) continue;

        long long tmp = 0;
        for (int j = 0; j < cnt.size(); ++j) {
            tmp += mod_exp(cnt[j], a[i]);
            tmp %= mod;
        }
        res *= tmp;
        res %= mod;
    }

    std::cout << res << '\n';
}