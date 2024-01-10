#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>

// https://codeforces.com/problemset/problem/1158/A

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<long long> a(n, 0);
    std::vector<long long> b(m, 0);
    for (int i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < b.size(); ++i) {
        std::cin >> b[i];
    }

    long long cnt = 0;
    long long mmin = a[0];
    for (int i = 0; i < a.size(); ++i) {
        mmin = std::max(a[i], mmin);
        cnt += a[i] * b.size();
    }

    std::sort(b.begin(), b.end());
    std::sort(a.begin(), a.end());

    for (int i = 0; i < b.size(); ++i) {
        if (b[i] < mmin) {
            std::cout << "-1\n";
            return 0;
        }
    }

    int i = 0;
    if (b[0] != a[a.size() - 1]) {
        cnt += b[0] - a[a.size() - 2];
        i++;
    }
    for (; i < b.size(); ++i) {
        cnt += b[i] - a[a.size() - 1];
    }

    std::cout << cnt << '\n';
}