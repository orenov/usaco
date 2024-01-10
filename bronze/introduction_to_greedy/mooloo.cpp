#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=1301

int main() {
    int n, k; std::cin >> n >> k;
    std::vector<long long> d(n, 0LL);
    for (int i = 0; i < n; ++i) {
        std::cin >> d[i];
    }

    long long cnt = k + 1;
    long long last = d[0];
    for (int i = 1; i < n; ++i) {
        if (d[i] - last <= k) {
            cnt += d[i] - last;
        } else {
            cnt += k + 1;
        }
        last = d[i];
    }

    std::cout << cnt << '\n';
}