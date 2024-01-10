#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL false

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=856
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("blist.in", "r", stdin);
    int n; cin >> n;
    vector<int> a(1001, 0);
    for (int i = 0; i < n; ++i) {
        int s, t, b; cin >> s >> t >> b;
        s--;t--;
        for (int k = s; k <= t; ++k) {
            a[k] += b;
        }
    }

    int res = 0;
    for (int i = 0; i < a.size(); ++i) {
        res = max(res, a[i]);
    }

    if (!LOCAL) freopen("blist.out", "w", stdout);
    std::cout << res << '\n';
}
