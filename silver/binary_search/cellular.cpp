#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>

// https://codeforces.com/contest/702/problem/C

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n, 0);
    std::vector<int> b(m, 0);
    std::vector<int> d(n, INT_MAX);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    int res = 0;
    int i = 0; 
    int j = 0;

    while (i < n - 1 && j < m - 1) {
        d[i] = std::min(d[i], std::abs(a[i] - b[j]));
        if (std::abs(a[i] - b[j+1]) <= std::abs(a[i+1] - b[j])) {
            j++;
        } else {
            i++;
        }
    }

    if (i == n - 1) {
        while (j < m) {
            d[i] = std::min(d[i], std::abs(a[i] - b[j]));
            j++;
        }
    }

    if (j == m - 1) {
        while (i < n) {
            d[i] = std::min(d[i], std::abs(a[i] - b[j]));
            i++;
        }
    }

    for (int i = 0; i < d.size(); ++i) {
        res = std::max(res, d[i]);
    }

    std::cout << res << '\n';
}