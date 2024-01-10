#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=594

int fun(std::vector<int>& a, int x) {
    int cnt = 0;
    int i = 0;
    while (i < a.size()) {
        int start = a[i];
        while (i + 1 < a.size() && a[i+1] - start <= 2 * x) ++i;
        ++cnt;
        ++i;
    }

    return cnt;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    int l = -1;
    int r = a.back() - a[0] + 1;
    // (l, r] invariant
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (fun(a, m) <= k) {
            r = m;
        } else {
            l = m;
        }
    }

    std::cout << r << '\n';
}