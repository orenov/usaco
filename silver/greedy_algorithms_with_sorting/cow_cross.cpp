#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=714

int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    long long c, n; std::cin >> c >> n;
    std::multiset<int> fset;
    std::vector<std::vector<long long>> a(n, std::vector<long long>(2, 0));
    for (int i = 0; i < c; ++i) {
        int val; std::cin >> val;
        fset.insert(val);
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][1] >> a[i][0];
    }
    std::sort(a.begin(), a.end());
    
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        int start = a[i][1];
        int end = a[i][0];
        auto it = fset.lower_bound(start);
        //std::cout << start << ' ' << end << ' ' << *it << '\n';
        if (it != fset.end() && *it <= end) {
            cnt++;
            fset.erase(it);
        }
    }

    std::cout << cnt << '\n';
}