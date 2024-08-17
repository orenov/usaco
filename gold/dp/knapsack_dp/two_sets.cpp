#include <iostream>
#include <vector>
 
int main() {
    int n; std::cin >> n;
    int x = n * (n + 1) / 2;
 
    if (x % 2 == 1) {
        std::cout << "0\n";
        return 0;
    }
    x /= 2;
    
    std::vector<long long> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = x; j >= 0; --j) {
            if (j - i >= 0) {
                dp[j] += dp[j - i];
                dp[j] %= 2 * 1000000007;
            }
        }
    }
 
    std::cout << dp.back() / 2 << '\n';
}