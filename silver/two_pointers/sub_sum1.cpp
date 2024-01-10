#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// https://cses.fi/problemset/task/1660

int main() {
    int n, x; std::cin >> n >> x;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int l = 0;
    int r = 0;
    long long cur = 0;
    int cnt = 0;

    while (r < n || l < n) {
        if (r < n && l < n) {
            if (cur > x) {
                cur -= a[l];
                l++;
            } else {
                cur += a[r];
                r++;
            }
        } else {
            cur -= a[l];
            l++;
        }

        if (cur == x) {
            cnt++;
        }
    }

    std::cout << cnt << '\n';
}