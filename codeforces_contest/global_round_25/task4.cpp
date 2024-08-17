#include <iostream>
#include <vector>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int64_t n, k; std::cin >> n >> k;
        std::vector<int64_t> b;
        bool can = true;

        for (int i = 0; i < 60 && k > 0 && n > 0; ++i) {            
            if (n / k == n / (k + 1)) {
                int64_t l = 1; // how many we want to get
                int64_t r = k + 1;  // how many we want to get
                // [l, r)
                while (l + 1 < r) {
                    int64_t m = (l + r) / 2;
                    if (n / m == n / (k + 1)) {
                        r = m;
                    } else {
                        l = m;
                    }
                }
                b.push_back(n / l);
                n -= l * b[i];
                k -= l;
            } else {
                b.push_back(n / k);
                n -= k * b[i];
                k -= k;
            }
        }

        if (n == 0 && k > 0) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
            std::cout << b.size() << '\n';
            for (int i = 0; i < b.size(); ++i) {
                std::cout << b[i] << '\n';
            }
        }
    }
}