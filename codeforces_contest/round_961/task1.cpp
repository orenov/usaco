#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, k; std::cin >> n >> k;

        int cnt = 0;
        for (int i = n; i >= 1 && k > 0; --i) {
            if (i == n) {
                k -= i;
                cnt++;
            } else {
                k -= i;
                cnt++;

                if (k > 0) {
                    k -= i;
                    cnt++;
                }
            }
        }

        std::cout << cnt << '\n';
    }
}