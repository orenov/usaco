#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=690

int fun(std::vector<int>& a, int k) {
    std::multiset<int> fset;
    int time = 0;
    int last = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (fset.size() == k) {
            time = *fset.begin();
            fset.erase(fset.begin());
        }
        last = std::max(last, a[i] + time);
        fset.insert(a[i] + time);
    }

    return last;
}

int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    int n, t; std::cin >> n >> t;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int l = -1;
    int r = a.size() - 1;
    // (l, r] invariant
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (fun(a, m) <= t) {
            r = m;
        } else {
            l = m;
        }
    }

    std::cout << r << '\n';
}