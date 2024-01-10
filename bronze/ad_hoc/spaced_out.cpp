#include <iostream>
#include <vector>
#include <algorithm>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=1088

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
        }
    }

    std::vector<std::vector<int>> rows(2, std::vector<int>(n, 0));
    std::vector<std::vector<int>> cols(2, std::vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rows[i % 2][j] += a[i][j];
            cols[j % 2][i] += a[i][j];
        }
    }

    long long res = 0;

    {
        long long tmp = 0;
        for (int i = 0; i < n; ++i) {
            tmp += std::max(rows[0][i], rows[1][i]);
        }
        res = std::max(res, tmp);
    }

    {
        long long tmp = 0;
        for (int i = 0; i < n; ++i) {
            tmp += std::max(cols[0][i], cols[1][i]);
        }
        res = std::max(res, tmp);
    }

    std::cout << res << '\n';
}