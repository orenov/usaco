#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=785

int main() {
    freopen("outofplace.in", "r", stdin);
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> b = a;
    std::sort(b.begin(), b.end());
    int cnt = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (a[i] != b[i]) cnt++;
    }
    freopen("outofplace.out", "w", stdout);
    std::cout << std::max(cnt - 1, 0) << '\n';
}