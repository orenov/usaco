#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, m, k; std::cin >> n >> m >> k;
        int n1 = std::min(n, k);
        int m1 = std::min(m, k);

        std::cout << n1 * m1 << '\n';
    }
}