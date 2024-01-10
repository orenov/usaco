#include <iostream>
#include <vector>
#include <algorithm>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=416

int main() {
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    int n, k; std::cin >> n >> k;
    std::vector<std::vector<int>> p(n + 2, std::vector<int>(n + 2, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int val; std::cin >> val;
            //if (i != 3 || j != 3) continue;
            p[i][std::max(0, j - k)] += val;
            p[i][std::min(n + 1, j + k + 1)] -= val;

            int kk = k - 1;
            while (kk >= 0) {
                // a b c d e
                if (i - (k - kk) >= 1) {
                    p[i - (k - kk)][std::max(0, j - kk)] += val;
                    p[i - (k - kk)][std::min(n + 1, j + kk + 1)] -= val;
                }
                if (i + (k - kk) <= n) {
                    p[i + (k - kk)][std::max(0, j - kk)] += val;
                    p[i + (k - kk)][std::min(n + 1, j + kk + 1)] -= val;
                }
                kk--;
            }
        }
    }

    // prefix

    int res = 0;
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 1; j <= n + 1; ++j) {
            p[i][j] += p[i][j-1];
            res = std::max(res, p[i][j]);
        }
    }

    //for (int i = 0; i <= n + 1; ++i) {
    //    for (int j = 0; j <= n + 1; ++j) {
    //        std::cout << p[i][j] << ' ';
    //    }
    //    std::cout << '\n';
    //}

    std::cout << res << '\n';
}