#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=689

int main() {
    freopen("cowtip.in", "r", stdin);
    int n; std::cin >> n;
    std::vector<std::string> s(n, "");
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }
    int cnt = 0;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (s[i][j] == '0') continue;
            cnt++;
            for (int qi = 0; qi <= i; ++qi) {
                for (int qj = 0; qj <= j; ++qj) {
                    if (s[qi][qj] == '0') {
                        s[qi][qj] = '1';
                    } else {
                        s[qi][qj] = '0';
                    }
                }
            }
        }
    }

    freopen("cowtip.out", "w", stdout);
    std::cout << cnt << '\n';
}