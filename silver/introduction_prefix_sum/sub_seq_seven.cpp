#include <iostream>
#include <vector>
#include <algorithm>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=595

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> earliest(7, -2);
    earliest[0] = -1;

    int cnt = 0;
    int cur = 0;

    for (int i = 0; i < n; ++i) {
        cur = (cur + a[i]) % 7;
        if (earliest[cur] != -2) {
            cnt = std::max(cnt, i - earliest[cur]);
        }
        if (earliest[cur] == -2) {
            earliest[cur] = i;
        }
    }

    std::cout << cnt << '\n';
}