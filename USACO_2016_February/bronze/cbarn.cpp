#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <climits>

#define LOCAL false

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("cbarn.in", "r", stdin);
    int n; cin >> n;
    vector<int> a(n, 0);
    int s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int k = 1; k < n; ++k) {
            int id = (i + k) % n;
            cur += a[id] * k;
        }
        res = min(res, cur);
    }

    if (!LOCAL) freopen("cbarn.out", "w", stdout);
    std::cout << res << '\n';
}
