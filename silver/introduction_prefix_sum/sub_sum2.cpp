#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// https://cses.fi/problemset/task/1661

int main() {
    int n, x; std::cin >> n >> x;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::map<long long, int> fmap;
    fmap[0] = 1;
    long long cnt = 0;
    long long cur = 0;

    for (int i = 0; i < n; ++i) {
        cur += a[i];
        if (fmap.find(cur - x) != fmap.end()) {
            cnt += fmap[cur - x];
        }
        fmap[cur]++;
    }

    std::cout << cnt << '\n';
}