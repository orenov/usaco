#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=666

int upper(std::vector<int>& a, int x) {
    // (l, r]
    int l = -1;
    int r = a.size();
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m] > x) {
            r = m;
        } else {
            l = m;
        }
    }

    return r;
}

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n, q; std::cin >> n >> q;
    
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    for (int i = 0; i < q; ++i) {
        int l, r; std::cin >> l >> r;
        std::cout << upper(a, r) - upper(a, l - 1) << '\n';
    }
}