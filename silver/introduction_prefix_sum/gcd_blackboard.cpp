#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>

// https://atcoder.jp/contests/abc125/tasks/abc125_c

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> left, right;
    left.push_back(0);
    right.push_back(0);
    for (int i = 0; i < a.size(); ++i) {
        if (i == 0) {
            left.push_back(a[i]);
        } else {
            left.push_back(gcd(left.back(), a[i]));
        }
    }

    for (int i = a.size() - 1; i >= 0; --i) {
        if (i == a.size() - 1) {
            right.push_back(a[i]);
        } else {
            right.push_back(gcd(right.back(), a[i]));
        }
    }

    for (int i = 0; i < right.size() / 2; ++i) {
        std::swap(right[i], right[right.size() - i - 1]);
    }

    int res = 0;
    for (int i = 0; i < left.size() - 1; ++i) {
        int l = left[i];
        int r = right[i + 1];
        int v = gcd(std::max(l, r), std::min(l, r));
        res = std::max(res, v);
    }
    
    std::cout << res << '\n';
}