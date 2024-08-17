#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, m, k; std::cin >> n >> m >> k;
        std::vector<std::vector<int>> a(n, std::vector<int>(2, 0));
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i][0];
            a[i][1] = i;
        }
        std::vector<std::vector<int>> a_sorted = a;
        std::sort(a_sorted.begin(), a_sorted.end());
        
        std::vector<int> cnt(n, 0);
        for (int i = 0; i < a_sorted.size() && k > 0; ++i) {
            if (k < m) {
                cnt[a_sorted[i][1]] = k;
                k = 0;
            } else {
                cnt[a_sorted[i][1]] = m;
                k -= m;
            }
        }

        long long res = 0;
        long long x = 0;

        for (int i = 0; i < n; ++i) {
            if (cnt[i] > 0) {
                res += (a[i][0] + x) * cnt[i];
                x += cnt[i];
            }
        }

        std::cout << res << '\n';
    }
}