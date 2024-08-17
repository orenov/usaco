#include <iostream>
#include <vector>

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> dp(n, 1);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[i]) {
                dp[j] = std::max(dp[j], dp[i] + 1);
            }
        }
    }

    int r = 0;
    for (int i = 0; i < dp.size(); ++i) {
        r = std::max(dp[i], r);
    }

    std::cout << r << '\n';
}