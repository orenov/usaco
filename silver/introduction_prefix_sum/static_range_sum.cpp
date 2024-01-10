#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

// https://judge.yosupo.jp/problem/static_range_sum

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n, 0LL);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<long long> prefix(n + 1, 0LL);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    for (int i = 0; i < q; ++i) {
        int l, r; std::cin >> l >> r;
        std::cout << prefix[r] - prefix[l] << '\n';
    }
}