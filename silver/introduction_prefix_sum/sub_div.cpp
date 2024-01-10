#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// https://cses.fi/problemset/task/1662

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::map<int, int> fmap;
    long long cnt = 0;
    long long cur = 2 * 1e5 * 1e9;
    fmap[cur % n] = 1;

    for (int i = 0; i < n; ++i) {
        cur += a[i];
        if (fmap.find(cur % n) != fmap.end()) {
            cnt += fmap[cur % n];
        }
        fmap[cur % n]++;
    }

    std::cout << cnt << '\n';
}