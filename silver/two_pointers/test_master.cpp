#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>

// https://codeforces.com/contest/1777/problem/C

void update_incr(std::vector<int>& a, int& cnt, int x) {
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            if (i < a.size()) {
                if (a[i] == 0) cnt--;
                a[i]++;
            }
            if (x / i < a.size()) {
                if (a[x / i] == 0) cnt--;
                a[x / i]++;
            }
        }
    }
}

void update_decr(std::vector<int>& a, int& cnt, int x) {
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            if (i < a.size()) {
                if (a[i] == 1) cnt++;
                a[i]--;
            }
            if (x / i < a.size()) {
                if (a[x / i] == 1) cnt++;
                a[x / i]--;
            }
        }
    }
}

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, m; std::cin >> n >> m;
        std::vector<int> a(n, 0);
        std::vector<int> b(m + 1, 0); // zero do not cnt
        int cnt = m;

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        int res = INT_MAX;
        int l = 0; // next to remove
        int r = 0; // next to add

        while (r < n) {
            if (cnt == 0) {
                update_decr(b, cnt, a[l]);
                l++;
            } else {
                update_incr(b, cnt, a[r]);
                r++;
            }

            if (cnt == 0) {
                res = std::min(res, a[r-1] - a[l]);
            }
        }
        
        while (l < n && cnt == 0) {
            res = std::min(res, a[r-1] - a[l]);
            update_decr(b, cnt, a[l]);
            l++;
        }

        if (res == INT_MAX) {
            std::cout << "-1\n";
        } else {
            std::cout << res << '\n';
        }
    }
}