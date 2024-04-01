#include <vector>
#include <iostream>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, q; std::cin >> n >> q;
        std::vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::cin >> q >> q;
        std::vector<int64_t> sum_vec(n + 1, 0);
        std::vector<int64_t> xor_vec(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sum_vec[i + 1] = sum_vec[i] + a[i];
            xor_vec[i + 1] = xor_vec[i] ^ a[i];
        }

        if (false) {
        for (int i = 0; i < n + 1; ++i) {
            std::cout << sum_vec[i] << ' ';
        }
        std::cout << '\n';

        for (int i = 0; i < n + 1; ++i) {
            std::cout << xor_vec[i] << ' ';
        }
        std::cout << '\n';
        }

        int64_t best = 0;
        int l = 1;
        int r = 1;
        // sum_vec = [0, 0]
        // xor_vec = [0, 0]
        for (int i = 1; i <= n; ++i) {
            int64_t val = (sum_vec[i] - sum_vec[0]) - (xor_vec[i] ^ xor_vec[0]);

            int left = 0;
            int right = i;
            // [left, right); l is an answer
            while (left + 1 < right) {
                int m = (left + right) / 2;
                int64_t m_val = (sum_vec[i] - sum_vec[m]) - (xor_vec[i] ^ xor_vec[m]);
                if (m_val == val) {
                    left = m;
                } else {
                    right = m;
                }
            }

            if (val > best) {
                best = val;
                l = left + 1;
                r = i;
            } else if (val == best && i - left - 1 < r - l) {
                l = left + 1;
                r = i;
            } 
        }
        std::cout << l << ' ' << r << '\n';
    }
}