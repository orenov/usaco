#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=919

int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int n, k; std::cin >> n >> k;
    std::vector<std::vector<int>> a(1002, std::vector<int>(1002, 0));
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1]++;
        a[x1][y2]--;
        a[x2][y1]--;
        a[x2][y2]++;
    }

    int res = 0;
    for (int i = 0; i <= 1000; ++i) {
        for (int j = 0; j <= 1000; ++j) {
            if (i > 0) a[i][j] += a[i-1][j];
            if (j > 0) a[i][j] += a[i][j-1];
            if (i > 0 && j > 0) a[i][j] -= a[i-1][j-1];
            res += a[i][j] == k;
        }
    }

    std::cout << res << '\n';
}