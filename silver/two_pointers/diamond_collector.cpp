#include <iostream>
#include <vector>
#include <algorithm>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=643

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    
    std::vector<int> dp1(a.size(), 0);
    std::vector<int> dp2(a.size(), 0);

    int l = 0;
    int r = 0;

    while (l < a.size()) {
        while (r < a.size() && a[r] - a[l] <= k) r++;
        dp1[l] = r - l;
        l++;
    }

    for (int i = a.size() - 2; i >= 0; --i) {
        dp2[i] = std::max(dp2[i+1], dp1[i]);
    }

    int res = 0;
    for (int i = 0; i + dp1[i] < a.size(); ++i) {
        res = std::max(res, dp1[i] + dp2[i + dp1[i]]);
    }

    std::cout << res << '\n';
}