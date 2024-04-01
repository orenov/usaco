#include <iostream>
#include <vector>

int main() {
    int64_t n, k; std::cin >> n >> k;
    std::vector<int64_t> a(k, 0);
    for (int i = 0; i < k; ++i) {
        std::cin >> a[i];
    }
    int64_t res = 0;
    for (int mask = 1; mask < (1 << k); ++mask) {
        int64_t val = 1;
        int cnt = 0;

        for (int i = 0; i < k; ++i) {
            if (mask & (1 << i)) {
                if (val > n / a[i]) {
                    val = n + 1;
                    break;
                }
                val *= a[i];
                cnt++;
            }
        }

        if (cnt % 2 == 1) {
            res += n / val;
        } else {
            res -= n / val;
        }
    }

    std::cout << res << '\n';
}