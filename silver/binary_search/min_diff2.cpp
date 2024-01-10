#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>
 
// https://codeforces.com/contest/1244/problem/E

long long run(std::vector<long long>& a, std::vector<long long>& prefix, long long x) {
    long long cnt = LLONG_MAX;
    
    // iterator over left
    for (int i = 0; i < a.size(); ++i) {
        // fix L = i;
        long long tmp = (i + 1) * a[i] - prefix[i + 1];
        
        int l = i;
        int r = a.size() - 1;
        // (l, r] invariant;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (a[m] - a[i] > x) {
                r = m;
            } else {
                l = m;
            }
        }

        //for (int k = r; k < a.size(); ++k) {
            //tmp += a[k];
        //}

        tmp += prefix.back() - prefix[r];
        tmp -= (a.size() - r) * x;
        tmp -= (a.size() - r) * a[i];

        cnt = std::min(cnt, tmp);
    }

    // iterator over right
    for (int i = 0; i < a.size(); ++i) {
        // fix R = i;
        long long tmp = (prefix.back() - prefix[i+1]) -  (a.size() - i - 1) * a[i];

        int l = 0;
        int r = i;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (a[i] - a[m] >= x) {
                l = m;
            } else {
                r = m;
            }
        }

        //for (int k = 0; k <= l; ++k) {
            //tmp += -1 * a[k];
        //}

        tmp -= prefix[l + 1];
        tmp -= (l + 1) * x;
        tmp += (l + 1) * a[i];

        cnt = std::min(cnt, tmp);
    }

    return cnt;
}
 
int main() {
    int n; std::cin >> n;
    long long k; std::cin >> k;
    std::vector<long long> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    
    std::vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i-1] + a[i-1];
    }

    long long l = -1;
    long long r = a.back() - a[0] + 2;

    // [l, r) invariant
    while (l + 1 < r) {
        long long m = (l + r) / 2;
        //std::cout << l << ' ' << r << ' ' << m << ' ' << run(a, m) << '\n';
        if (run(a, prefix, m) <= k) {
            r = m;
        } else {
            l = m;
        }
    }
 
    std::cout << r << '\n';
}