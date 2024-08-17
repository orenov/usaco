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
            std::cin >> a[i]; // not inclusive (x, y], if x == y then empty
            if (a[i] % 2 == 1) a[i]++;
        }

        int cnt = 0;
        int i = 0;
        while (i < n) {
            if (a[i] == 0) {
                i++;
            } else if (a[i] == 2 && i + 1 < n && a[i+1] == 2) {
                i += 2;
                cnt++;
            } else if (a[i] == 2 && i + 3 < n && a[i+1] == 4 && a[i+2] == 4 && a[i+3] == 2) {
                i += 4;
                cnt += 3;
            } else {
                cnt++;
                i++;
            }
        }

        std::cout << cnt << '\n';
    }
}