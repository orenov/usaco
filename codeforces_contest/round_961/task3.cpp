#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        long long n, m; std::cin >> n >> m;
        std::vector<std::vector<long long>> a(n, std::vector<long long>(2, 0));
        
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i][0];
        }

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i][1];
        }

        std::sort(a.begin(), a.end());

        long long res = 0;
        
        for (int i = 0; i < a.size(); ++i) {
            // std::cout << "start: " << a[i][0] << ' ' << a[i][1] << '\n';
            // take first
            long long cur = 0;
            long long h1 = std::min(m / a[i][0], a[i][1]);
            long long cur1 = h1 * a[i][0];
            
            res = std::max(res, cur1);

            // take rest of cur2
            if (i + 1 < a.size() && a[i+1][0] - a[i][0] == 1) {
                long long h2 = std::min((m - cur1) / a[i+1][0], a[i+1][1]);

                long long cur2 = cur1 + h2 * a[i+1][0];
                res = std::max(res, cur2);

                if (h2 <= a[i+1][1]) {
                    cur2 = std::min(cur2 + std::min(h1, a[i+1][1] - h2), m);
                }

                res = std::max(res, cur2);
            }

            //std::cout << "final: " << cur  << ' ' << cnt << ' ' <<  a[i][0] << ' ' << h1 + h2 << '\n';
        }

        std::cout << res << '\n';
    }
}