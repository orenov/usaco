#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>
#include <string>

// https://atcoder.jp/contests/abc164/tasks/abc164_d

int main() {
    std::string s; std::cin >> s;
    std::map<int, int> fmap;
    fmap[0] = 1;
    
    long long res = 0;
    int cur = 0;
    int d = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
        cur = cur + d * (s[i] - '0');
        cur %= 2019;
        d = (d * 10) % 2019;

        if (fmap.find(cur) != fmap.end()) {
            res += fmap[cur];
        }
        fmap[cur]++;
    }

    std::cout << res << '\n';
}