#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        int r = a[0];
        for (int i = 0; i < n; i += 2) {
            r = std::max(a[i], r);
        }

        std::cout << r << '\n';
    }
}