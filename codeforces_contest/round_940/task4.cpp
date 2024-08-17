#include <iostream>
#include <vector>
#include <algorithm>

int highest_bit(int x) {
    int i = 0;
    while (x > 0) {
        x /= 2;
        i++;
    }

    return i - 1;
}


int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<int> a(n, 0);

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::vector<int> prefix(n + 1, 0);
        // [l, r] -> prefix[r + 1] ^ previx[l];

        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] ^ a[i];
        }

        std::vector<std::vector<int>> arr(32, std::vector<int>(n + 2, 0));

        for (int bit = 0; bit < 32; ++bit) {
            for (int i = 0; i <= n; ++i) {
                arr[bit][i + 1] = arr[bit][i] + (prefix[i] >> bit & 1);
            }
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            int bit = highest_bit(a[i]);
            int left = arr[bit][i + 1];
            int right = arr[bit][n + 1] - arr[bit][i + 1];

            res += (int64_t) left * right;
            res += (int64_t) (i + 1 - left) * (n - i - right);
        }

        std::cout << res << '\n';
    }
}