#include <iostream>
#include <vector>



int main() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> dp;
    dp.push_back(a[0]);
    // dp[i] - minimum value on which sequence of length i ends
    for (int i = 1; i < n; ++i) {
        int l = -1;
        int r = dp.size() - 1;
        // (l, r] invariant
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (dp[m] >= a[i]) {
                r = m;
            } else {
                l = m;
            }
        }

        if (dp[r] >= a[i]) {
            dp[r] = a[i];
        } else {
            dp.push_back(a[i]);
        }
    }

    std::cout << dp.size() << '\n';
}