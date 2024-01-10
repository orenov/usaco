#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

int fun(std::vector<std::vector<int>>& a, int x) {
    int cnt = 1;
    int i = 0;
    int last = a[0][0];
    while (i < a.size()) {
        //std::cout << cnt << ' ' << i << ' ' << last << ' ' << x << '\n';
        int next = last + x;
        if (next <= a[i][1]) {
            last = next;
            ++cnt;
        } else {
            ++i;
            while (i < a.size()) {
                if (next <= a[i][0]) {
                    last = a[i][0];
                    ++cnt;
                    break;
                } else if (next <= a[i][1]) {
                    last = next;
                    ++cnt;
                    break;
                } else {
                    ++i;
                }
            }
        }
    }

    return cnt;
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> a(m, std::vector<int>(2, 0));
    for (int i = 0; i < m; ++i) {
        std::cin >> a[i][0] >> a[i][1];
    }
    std::sort(a.begin(), a.end());

    int l = 0;
    int r = 1e9;
    // [l, r) invariant
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        //std::cout << " === " << mid << ' ' << fun(a, mid) << '\n';
        if (fun(a, mid) >= n) { // opt
            l = mid;
        } else {
            r = mid;
        }
    }

    std::cout << l << '\n';
}