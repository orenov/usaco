#include <iostream>
#include <vector>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::string s; std::cin >> s;

        std::vector<int> prefix(n + 1, 0);
        int overall0 = 0;
        int overall1 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                overall0 ^= a[i];
            } else {
                overall1 ^= a[i];
            }
            prefix[i + 1] = prefix[i] ^ a[i];
        }

        int q; std::cin >> q;
        for (int i = 0; i < q; ++i) {
            int type; std::cin >> type;
            if (type == 1) {
                int l, r; std::cin >> l >> r;
                int change = prefix[r] ^ prefix[l-1];
                overall0 ^= change;
                overall1 ^= change;
            } else {
                int g; std::cin >> g;
                if (g == 0) {
                    std::cout << overall0 << ' ';
                } else {
                    std::cout << overall1 << ' ';
                }
            }
        }
        std::cout << '\n';
    }
}