#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
   int T; std::cin >> T;
   for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
   }
}