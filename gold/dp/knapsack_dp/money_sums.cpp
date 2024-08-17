#include <vector>
#include <iostream>

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) std::cin >> a[i];

    std::vector<bool> dp(1000 * 100 + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = dp.size() - 1; j >= 0; --j) {
            if (j - a[i] >= 0 && dp[j - a[i]]) {
                dp[j] = true;
            }
        }
    }

    std::vector<int> r;
    for (int i = 1; i < dp.size(); ++i) {
        if (dp[i]) {
            r.push_back(i);
        }
    }

    std::cout << r.size() << '\n';
    for (int i = 0; i < r.size(); ++i) {
        std::cout << r[i] << ' ';
    }
    std::cout << '\n';
}