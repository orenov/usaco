#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>

#define LOCAL true

/*
    Author: Oleksii Renov
    https://cses.fi/problemset/task/1640
*/

using namespace std;
using ll = long long int;

int main() {
    ll n, x; cin >> n >> x;
    vector<ll> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<ll, int> fset;
    for (int i = 0; i < n; ++i) {
        if (fset.find(x - a[i]) != fset.end()) {
            std::cout << i + 1 << ' ' << fset[x - a[i]] + 1 << '\n';
            return 0;
        }
        fset[a[i]] = i;
    }
    std::cout << "IMPOSSIBLE\n";
}
