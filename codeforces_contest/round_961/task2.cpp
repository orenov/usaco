#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        long long n, m; std::cin >> n >> m;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end());

        long long res = 0;
        int l = 0;
        int r = 0;
        long long cur = 0;

        while (r < a.size()) {
            cur += a[r];

            while (cur > m || a[r] - a[l] > 1) {
                cur -= a[l];
                l++;
            }

            res = std::max(res, cur);
            r++;
        }


        std::cout << res << '\n';
    }
}