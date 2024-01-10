#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=810

int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    long long l, n, f, b; std::cin >> l >> n >> f >> b;
    std::vector<std::vector<long long>> a(n, std::vector<long long>(2, 0));
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][1] >> a[i][0];
    }
    std::sort(a.begin(), a.end(), std::greater<std::vector<long long>>());
    long long cnt = 0;
    long long cur = 0;
    int i = 0;
    while (i < a.size()) {
        while (i < a.size() && cur > a[i][1]) ++i;
        if (i == a.size()) break;

        //std::cout << i << ' ' << cur << ' ' << a[i][0] << ' ' << a[i][1] << '\n';

        long long sec = (a[i][1] - cur) * (f - b);
        cnt += sec * a[i][0];
        cur = a[i][1];
        ++i;
    }

    std::cout << cnt << '\n';
}