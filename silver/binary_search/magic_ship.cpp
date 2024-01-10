#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>
#include <string>

// https://codeforces.com/problemset/problem/1117/C

bool fun(long long x, long long source_x, long long source_y, long long target_x, long long target_y, std::string& s) {
    for (int i = 0; i < s.size(); ++i) {
        long long cnt = x / s.size();
        if (i < x % s.size()) cnt++;

        if (s[i] == 'U') {
            source_y += cnt;
        }
        if (s[i] == 'D') {
            source_y -= cnt;
        }
        if (s[i] == 'L') {
            source_x -= cnt;
        }
        if (s[i] == 'R') {
            source_x += cnt;
        }
    }

    return std::abs(source_y - target_y) + std::abs(source_x - target_x) <= x;
}

int main() {
    long long source_x, source_y, target_x, target_y;
    std::cin >> source_x >> source_y >> target_x >> target_y;
    int n; std::cin >> n;
    std::string s; std::cin >> s;

    long long l = 0;
    long long r = 1e16; 
    // 2 * (std::abs(source_x - target_x) + std::abs(source_y - target_y));
    // (l, r] invariant
    while (l + 1 < r) {
        long long m = (l + r) / 2;
        if (fun(m, source_x, source_y, target_x, target_y, s)) {
            r = m;
        } else {
            l = m;
        }
    }

    if (r == 1e16) r = -1;
    std::cout << r << '\n';
}
