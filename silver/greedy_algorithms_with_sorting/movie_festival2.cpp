#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <set>

// https://cses.fi/problemset/task/1632

int main() {
    int n, k; std::cin >> n >> k;
    std::vector<std::vector<int>> a(n, std::vector<int>(2, 0));

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][1] >> a[i][0];
    }

    int cnt = 0;
    std::sort(a.begin(), a.end());
    std::multiset<int> fset;
    for (int i = 0; i < k; ++i) fset.insert(1);

    for (int i = 0; i < a.size(); ++i) {
        int start = a[i][1];
        int end = a[i][0];

        auto it = fset.lower_bound(-start);

        if (it != fset.end()) {
            fset.erase(it);
            fset.insert(-end);
            cnt++;
        }
    }

    std::cout << cnt << '\n';
}