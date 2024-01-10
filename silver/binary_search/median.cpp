#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>
#include <string>

// https://codeforces.com/contest/1201/problem/C

long long run(std::vector<long long>& a, long long x) {
    long long res = 0;
    for (int i = a.size() / 2; i < a.size(); ++i) {
        if (a[i] < x) {
            res += x - a[i];
        }
    }

    return res;
}

int main() {
    long long n, k; std::cin >> n >> k;
    std::vector<long long> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    long long l = a[a.size() / 2];
    long long r = a.back() + k + 1;

    // [l, r) invariant 
    int i = 0;
    while (l + 1 < r) {
        //std::cout << l << ' ' << r << '\n';
        long long m = (l + r) / 2;
        if (run(a, m) <= k) {
            l = m;
        } else {
            r = m;
        }
        i++;
    }

    std::cout << l << '\n';
}
