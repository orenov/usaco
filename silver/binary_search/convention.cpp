#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=858

int fun(std::vector<int>& a, int k, int c) {
    int cnt = 0;
    int i = 0;
    while (i < a.size()) {
        int start = a[i];
        int c0 = 1;
        while (i < a.size() && a[i+1] - start <= k && c0 + 1 <= c) {
            ++i;
            ++c0;
        }
        ++cnt;
        ++i;
    }

    return cnt;
}

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int n, m, c; std::cin >> n >> m >> c;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    int l = -1;
    int r = a.back() - a[0];
    // (l, r] invariant
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        //std::cout << mid << ' ' << fun(a, mid, c) << '\n';
        if (fun(a, mid, c) <= m) {
            r = mid;
        } else {
            l = mid;
        }
    }

    std::cout << r << '\n';
}