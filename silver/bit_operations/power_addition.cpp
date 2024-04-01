#include <iostream>
#include <vector>

int main() {
    int T; std::cin >> T;
    for (int qq = 0; qq < T; ++qq) {
        int n; std::cin >> n;
        std::vector<int64_t> a(n, 0);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::vector<int64_t> maxs(n, -1e10);
        for (int i = 1; i < n; ++i) {
            maxs[i] = std::max(maxs[i-1], a[i-1]);
        }
        int64_t t = 0;
        int64_t cur = 0;
        for (int i = n - 1; i >= 1; --i) {
            while (cur + a[i] < maxs[i]) {
                cur += 1 << t;
                t++;
            }
        }

        std::cout << t << '\n';
    }
}