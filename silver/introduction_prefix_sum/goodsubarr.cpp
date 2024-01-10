#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>

// https://codeforces.com/contest/1398/problem/C

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<int> p(n, -1);
        std::map<int, long long> memo;

        for (int i = 0; i < n; ++i) {
            char c; std::cin >> c;
            p[i] += (c - '0');
        }

        for (int i = 1; i < n; ++i) {
            p[i] += p[i-1];
        }

        long long cnt = 0;
        memo[0] = 1;
        for (int i = 0; i < n; ++i) {
            if (memo.find(p[i]) != memo.end()) {
                cnt += memo[p[i]];
            }
            memo[p[i]]++;
        }
        
        std::cout << cnt << '\n';
    }
}