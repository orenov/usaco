#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=738

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n; std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][1] >> a[i][0];
    }
    std::sort(a.begin(), a.end());
    int res = 0;
    int l = 0;
    int r = a.size() - 1;
    while (l <= r) {
        //std::cout << a[l][1] << ' ' << a[r][1] << '\n';
        res = std::max(res, a[l][0] + a[r][0]);
        int cnt = std::min(a[l][1], a[r][1]);
        a[l][1] -= cnt;
        if (r != l) a[r][1] -= cnt;
        if (a[l][1] == 0) {
            l++;
        }
        if (a[r][1] == 0) {
            r--;
        }
    }

    std::cout << res << '\n'; 
}