#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=573

int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n; std::cin >> n;
    std::vector<int> a(n / 2, 0);
    std::vector<int> b(n / 2, 0);
    std::set<int> fset;
    for (int i = 1; i <= 2 * n; ++i) {
        fset.insert(i);
    }
    for (int i = 0; i < n / 2; ++i) {
        std::cin >> a[i];
        fset.erase(a[i]);
    }
    for (int i = 0; i < n / 2; ++i) {
        std::cin >> b[i];
        fset.erase(b[i]);
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    std::sort(b.begin(), b.end());

    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        auto it = fset.rbegin();
        if (*it > a[i]) {
            cnt++;
            fset.erase(*it);
        }
    }

    for (int i = 0; i < b.size(); ++i) {
        auto it = fset.begin();
        if (*it < b[i]) {
            cnt++;
            fset.erase(*it);
        }
    }

    std::cout << cnt << '\n';
}