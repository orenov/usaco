#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, x, y; std::cin >> n >> x >> y;

        std::vector<int> a(n + 1);
        bool f = true;
        for (int i = y - 1; i >= 1; --i) {
            if (f) {
                a[i] = -1;
                //std::cout << -1 << ' ';
            } else {
                a[i] = 1;
                //std::cout << 1 << ' ';
            }
            f = !f;
        }

        for (int i = y; i <= x; ++i) {
            //std::cout << 1 << ' ';
            a[i] = 1;
        }

        f = true;
        for (int i = x + 1; i <= n; ++i) {
            if (f) {
                a[i] = -1;
                //std::cout << -1 << ' ';
            } else {
                a[i] = 1;
                //std::cout << 1 << ' ';
            }
            f = !f;
        }

        for (int i = 1; i <= n; ++i) {
            std::cout << a[i] << ' ';
        }

        std::cout << '\n';
    }
}