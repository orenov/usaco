#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>
#include <string>

// https://codeforces.com/problemset/problem/814/C

int main() {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int m;
        char c;
        std::cin >> m >> c;

        int l = 0;
        int r = 0;
        int cnt = 0;
        int res = 0;

        while (r < n) {
            while (r < n && (s[r] == c || cnt < m)) {
                if (s[r] != c) cnt++;
                r++;
            }
            //std::cout << l << ' ' << r - 1 << ' ' << cnt << '\n';
            res = std::max(res, r - l);
            if (s[l] != c) {
                cnt--;
            }
            l++;
        }

        std::cout << res << '\n';

    }
}
