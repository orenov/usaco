#include <iostream>
#include <vector>
#include <algorithm>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=691

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        char c; std::cin >> c;
        if (c == 'H') a[i] = 0;
        if (c == 'P') a[i] = 1;
        if (c == 'S') a[i] = 2;
    }

    std::vector<std::vector<int>> left, right;
    left.push_back({0, 0, 0});
    right.push_back({0, 0, 0});

    for (int i = 0; i < n; ++i) {
        std::vector<int> x(3, 0);
        x[a[i]]++;
        left.push_back({left.back()[0] + x[0], left.back()[1] + x[1], left.back()[2] + x[2]});
    }

    for (int i = n - 1; i >= 0; --i) {
        std::vector<int> x(3, 0);
        x[a[i]]++;
        right.push_back({right.back()[0] + x[0], right.back()[1] + x[1], right.back()[2] + x[2]});
    }
    
    int cnt = 0;
    for (int i = 0; i <= n; ++i) {
        cnt = std::max(cnt, 
            std::max(std::max(left[i][0], left[i][1]), left[i][2]) + 
            std::max(std::max(right[n-i][0], right[n-i][1]), right[n-i][2]));
    }

    std::cout << cnt << '\n';
}