#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>
#include <string>
#include <iomanip>
#include <unordered_map>

// https://codeforces.com/gym/104468/problem/H

int main() {
    std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    std::unordered_map<int, std::vector<long long>> fmap;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int c; std::cin >> c;
        if (fmap.find(c) == fmap.end()) {
            fmap[c].push_back(0);
        }
        fmap[c].push_back(a[i] + fmap[c].back());
    }

    long long total = 0;
    std::unordered_map<int, long long> cnt;
    int q; std::cin >> q;

    for (int qq = 0; qq < q; ++qq) {
        int type, col;
        long long val;
        std::cin >> type >> col >> val;

        if (type == 1) {
            cnt[col] += val;
            total += val;
        }

        if (type == 2) {
            int l = 0;
            int r = fmap[col].size();
            // [l, r) - invariant
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (fmap[col][m] + m * (total - cnt[col]) <= val) {
                    l = m;
                } else {
                    r = m;
                }
            }
            std::cout << l << '\n';
        }
    }
}
