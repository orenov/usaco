#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<int> a(n);
        int even = 0;
        int odd = 0;
        int max_odd = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (a[i] % 2 == 1) {
                ++odd;
                max_odd = std::max(max_odd, a[i]);
            } else {
                ++even;
            }
        }

        if (even == 0 || odd == 0) {
            std::cout << "0\n";
            continue;
        }
        std::sort(a.begin(), a.end());

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0 && a[i] < max_odd) {
                a[i] += max_odd;
                cnt++;
                max_odd = std::max(max_odd, a[i]);
                even--;
            }
        }

        if (even > 0) {
            cnt += even + 1;
        }

        std::cout << cnt << '\n';
    }
}