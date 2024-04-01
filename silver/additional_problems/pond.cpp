#include <iostream>
#include <vector>

bool fun(std::vector<std::vector<int>>& a, int x, int k) {
    int n = a.size();
    std::vector<std::vector<int64_t>> pr(n + 1, std::vector<int64_t>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pr[i+1][j+1] = a[i][j] <= x;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pr[i][j] = pr[i][j] + pr[i-1][j] + pr[i][j-1] - pr[i-1][j-1];
        }
    }

    int64_t threshold = k * k / 2;
    if (k % 2 == 1) threshold++;

    for (int i = 0; i <= n - k; ++i) {
        for (int j = 0; j <= n - k; ++j) {
            int64_t val = pr[i + k][j + k] - pr[i][j+k] - pr[i+k][j] + pr[i][j];
            //std::cout << val << ' ' << k * k / 2 << '\n';
            if (pr[i + k][j + k] - pr[i][j+k] - pr[i+k][j] + pr[i][j] >= threshold) {
                return true;       
            }
        }
    }

    return false;
}

int main() {
    int n, k; std::cin >> n >> k;
    std::vector<std::vector<int>> a(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
        }
    }

    int l = -1;
    int r = 1e9 + 1;
    // (l, r] invariant

    while (l + 1 < r) {
        int m = (l + r) / 2;
        //std::cout << "=====\n";
        //std::cout << m << '\n';
        if (fun(a, m, k)) {
            r = m;
        } else {
            l = m;
        }
    }

    std::cout << r << '\n';
}