#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>

// https://codeforces.com/gym/104114/problem/N

int main() {
    int n, m; std::cin >> n >> m;

    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i+1]) {
            a[i+1] = std::max(a[i+1], a[i] - m);
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        if (a[i+1] > a[i]) {
            a[i] = std::max(a[i], a[i+1] - m);
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}
