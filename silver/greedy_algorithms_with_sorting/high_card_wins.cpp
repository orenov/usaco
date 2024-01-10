#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=571

int main() {
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    std::set<int> fset;
    for (int i = 1; i <= 2 * n; ++i) {
        fset.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        fset.erase(a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        auto it = fset.lower_bound(a[i]);
        if (it != fset.end()) {
            cnt++;
            fset.erase(it);
        }
    }

    std::cout << cnt << '\n';
}