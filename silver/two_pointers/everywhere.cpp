#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>
#include <string>

// https://codeforces.com/problemset/problem/701/C

bool cmp(std::vector<int>& target, std::vector<int>& current) {
    for (int i = 0; i < target.size(); ++i) {
        if (target[i] > 0 && current[i] == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n; std::cin >> n;
    std::string s; std::cin >> s;

    std::vector<int> cnt(60, 0);
    std::vector<int> cur(60, 0);
    for (int i = 0; i < s.size(); ++i) {
        cnt[s[i]-'A']++;
    }

    int res = n;
    int l = 0; // next to remove
    int r = 0; // next to take
    while (r < n) {
        if (cmp(cnt, cur)) {
            cur[s[l] - 'A']--;
            l++;
        } else {
            cur[s[r] - 'A']++;
            r++;
        }
        if (cmp(cnt, cur)) {
            res = std::min(res, r - l);
        }
    }

    while (l < n && cmp(cnt, cur)) {
        res = std::min(res, r - l);
        cur[s[l] - 'A']--;
        l++;
    }

    std::cout << res << '\n';
}