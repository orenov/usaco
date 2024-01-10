#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>

// https://codeforces.com/contest/847/problem/B

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> res;

    for (int i = 0; i < n; ++i) {
        int l = -1;
        int r = res.size();
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (res[m].back() <= a[i]) {
                r = m;
            } else {
                l = m;
            }
        }

        if (r == res.size()) {
            res.push_back(std::vector<int>());
        }
        res[r].push_back(a[i]);
    }

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            std::cout << res[i][j] << ' ';
        }
        std::cout << '\n';
    }

}
