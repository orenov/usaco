#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

// https://cses.fi/problemset/task/1643

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n, 0);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long min_prefix = 0;
    long long res = LLONG_MIN;
    long long cur_prefix = 0;
    for (int i = 0; i < n; ++i) {
        cur_prefix += a[i];
        res = std::max(res, cur_prefix - min_prefix);
        min_prefix = std::min(min_prefix, cur_prefix);
    }

    std::cout << res << '\n';
}