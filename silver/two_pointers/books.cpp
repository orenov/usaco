#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>

// https://codeforces.com/contest/279/problem/B

int main() {
    int n, t; std::cin >> n >> t;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int res = 0;
    int r = 0; // next to add
    int l = 0; // next to remove
    int cur = 0; // current time

    while (r < n) {
        if (cur > t) {
            cur -= a[l];
            l++;
        } else {
            cur += a[r];
            r++;
        }

        if (cur <= t) {
            res = std::max(res, r - l);
        }
    }

    std::cout << res << '\n';
}