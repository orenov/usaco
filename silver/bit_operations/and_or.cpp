#include <iostream>
#include <vector>

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> cnt(21, 0);
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k <= 20; ++k) {
            if (a[i] & (1 << k)) {
                cnt[k]++;
            }
        }
    }

    std::vector<int64_t> b(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k <= 20; ++k) {
            if (cnt[k] > 0) {
                b[i] |= 1 << k;
                cnt[k]--;
            }
        }
    }

    int64_t answer = 0;
    for (int i = 0; i < n; ++i) {
        answer += b[i] * b[i];
    }

    std::cout << answer << '\n';
}