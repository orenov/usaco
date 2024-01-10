#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <string>
#include <map>

// https://cses.fi/problemset/task/1085

long long fun(std::vector<long long>& a, long long x) {
    long long cnt = 0;
    long long s = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (s + a[i] > x) {
            cnt++;
            s = a[i];
        } else {
            s += a[i];
        }
    }
    cnt++;

    return cnt;
}

int main() {
    long long n, k; std::cin >> n >> k;
    std::vector<long long> a(n, 0);
    
    long long total = 0;
    long long mmax = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        total += a[i];
        mmax = std::max(mmax, a[i]);
    }


    long long l = mmax - 1;
    long long r = total;
    // (l, r] invariant;

    while (l + 1 < r) {
        long long m = (l + r) / 2;
        //std::cout << m << ' ' << fun(a, m) << '\n';
        if (fun(a, m) <= k) {
            r = m;
        }  else {
            l = m;
        }
    }

    std::cout << r << '\n';
}
