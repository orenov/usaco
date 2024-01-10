#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <string>
#include <map>

// https://cses.fi/problemset/task/1620

long long fun(std::vector<int>& a, long long x) {
    long long cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        cnt += x / a[i];
    }

    return cnt;
}

int main() {
    long long n, t; std::cin >> n >> t;
    std::vector<int> a(n, 0);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    long long l = -1;
    long long r = a[0] * t;
    // (l, r] invariant;

    while (l + 1 < r) {
        //std::cout << l << ' ' << r << '\n';
        long long m = (l + r) / 2;
        if (fun(a, m) >= t) {
            r = m;
        }  else {
            l = m;
        }
    }

    std::cout << r << '\n';
}
