#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <set>

// https://cses.fi/problemset/task/2422

long long fun(long long n, long long x) {
    long long cnt = 0;

    for (long long i = 1; i <= n; ++i) {
       cnt += std::min(x / i, n);
    }

    return cnt;
}

int main() {
    long long n; std::cin >> n;

    long long l = 0;
    long long r = n * n;
    // (l, r] invariant
    while (l + 1 < r) {
        long long m = (l + r) / 2;
        //std::cout << l << ' ' << r << ' ' << m << ' ' << fun(n, m) << '\n';
        if (fun(n, m) > (n * n) / 2) {
            r = m;
        } else {
            l = m;
        }
    }
    std::cout << r << '\n';
}