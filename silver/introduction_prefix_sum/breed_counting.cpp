#include <iostream>
#include <vector>
#include <algorithm>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=572

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, q; std::cin >> n >> q;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> pr(n + 1, std::vector<int>(3, 0));

    for (int i = 1; i <= n; ++i) {
        std::vector<int> x(3, 0);
        x[a[i-1]-1]++;

        pr[i] = {pr[i-1][0] + x[0], pr[i-1][1] + x[1], pr[i-1][2] + x[2]};
    }

    for (int i = 0; i < q; ++i) {
        int l, r; std::cin >> l >> r;
        l--; r--;
        std::cout << pr[r+1][0] - pr[l][0] << ' ' << pr[r+1][1] - pr[l][1] << ' ' << pr[r+1][2] - pr[l][2] << '\n';
    }
}