#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>
#include <string>
#include <iomanip>

// https://codeforces.com/contest/782/problem/B

bool run(std::vector<double>& x, std::vector<double>& v, double time) {
    double l = x[0] - time * v[0];
    double r = x[0] + time * v[0];
    for (int i = 1; i < x.size(); ++i) {
        double l1 = x[i] - time * v[i];
        double r1 = x[i] + time * v[i];
        if (l1 > r || r1 < l) return false;
        l = std::max(l1, l);
        r = std::min(r1, r); 
    }

    return true;
}

int main() {
    long long n; std::cin >> n;
    std::vector<double> x(n, 0.0);
    std::vector<double> v(n, 0.0);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    double l = -1;
    double r = 1e10;

    // (l, r] invariant 
    while (l + 1e-6 < r) {
        double m = (l + r) / 2;
        //std::cout << m << ' ' << run(x, v, m) << '\n';
        if (run(x, v, m)) {
            r = m;
        } else {
            l = m;
        }
    }

    std::cout << std::setprecision(10) << r << '\n';
}
