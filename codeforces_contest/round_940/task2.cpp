#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, k; std::cin >> n >> k;
        if (n == 1) {
            std::cout << k << '\n';
        } else {
            int v = 0;
            int i = 0;
            while (v + (1 << i) <= k) {
                v += (1 << i);
                i++;
            }

            std::cout << v << ' ' << k - v << ' ';
            for (int j = 0; j < n - 2; ++j) {
                std::cout << "0 ";
            }
            std::cout << '\n';
        }
    }
}