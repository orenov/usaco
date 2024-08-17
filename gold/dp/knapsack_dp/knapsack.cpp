#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int s, n; std::cin >> s >> n;
    std::vector<std::vector<int>> items(n, std::vector<int>(3));

    // s in [1, 2000]
    for (int i = 0; i < n; ++i) {
        std::cin >> items[i][0] >> items[i][1] >> items[i][2];
        // cost, weight, count
    }

    std::sort(items.begin(), items.end(), std::greater<std::vector<int>>());

    std::vector<std::vector<int>> a(2001, std::vector<int>());
    for (int i = 0; i < n; ++i) {
        int cnt = items[i][2];
        int w = items[i][1];
        int max_items = 2000 / w;

        while (cnt > 0 && a[w].size() < max_items) {
            a[w].push_back(items[i][0]);
            cnt--;
        }
    }

    std::vector<std::vector<int>> items2;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            items2.push_back({i, a[i][j]});
            // w, cost
        }
    }

    std::vector<int> dp(s + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 0; i < items2.size(); ++i) {
        int w = items2[i][0];
        int c = items2[i][1];
        std::vector<int> new_dp = dp;

        for (int j = 0; j < dp.size(); ++j) {
            if (dp[j] >= 0 && j + w < dp.size()) {
                new_dp[j + w] = std::max(new_dp[j + w], dp[j] + c);
            }
        }

        dp = new_dp;
    }

    int mmax = 0;
    for (int i = 0; i < dp.size(); ++i) {
        mmax = std::max(dp[i], mmax);
    }

    std::cout << mmax << '\n';
}