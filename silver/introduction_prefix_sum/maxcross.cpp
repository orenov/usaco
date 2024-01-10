#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=715

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int n, k, b; std::cin >> n >> k >> b;
    std::vector<int> p(n + 1, 0);
    for (int i = 0; i < b; ++i) {
        int val; std::cin >> val;
        p[val]++;
    }

    for (int i = 1; i <= n; ++i) {
        p[i] += p[i-1];
    }
    
    int cnt = k;
    for (int i = k; i <= n; ++i) {
        cnt = std::min(cnt, p[i] - p[i - k]);
    }

    std::cout << cnt << '\n';
}