#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL true

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

int main() {
    int n; cin >> n;
    vector<ll> x(n, 0);
    vector<ll> y(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> y[i];
    }

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll xx = (x[i] - x[j]) * (x[i] - x[j]);
            ll yy = (y[i] - y[j]) * (y[i] - y[j]);
            res = max(res, xx + yy);
        }
    }

    std::cout << res << '\n';
}
