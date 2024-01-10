#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>

// https://codeforces.com/contest/1826/problem/D

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::vector<int> l(n, a[0] + 1);
        std::vector<int> r(n, a.back() - n);
        
        for (int i = 1; i < n; ++i) {
            l[i] = std::max(l[i-1], a[i] + i + 1);
        }


        for (int i = n - 2; i >= 0; --i) {
            r[i] = std::max(r[i+1], a[i] - i - 1);
        }

        int res = INT_MIN;
        for (int i = 1; i < n - 1; ++i) {
            res = std::max(res, a[i] + l[i-1] + r[i+1]);
        }

        std::cout << res << '\n';
    }
}