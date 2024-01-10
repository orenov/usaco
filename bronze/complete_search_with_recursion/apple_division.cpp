#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <climits>

#define LOCAL true

/*
    Author: Oleksii Renov
    https://cses.fi/problemset/task/1623
*/

using namespace std;
using ll = long long int;

void fun(size_t pos, vector<int>& a, ll sum, ll& res) {
    if (pos == a.size()) {
        res = min(res, abs(sum));
        return;
    }

    fun(pos + 1, a, sum + a[pos], res);
    fun(pos + 1, a, sum - a[pos], res);
}


int main() {
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll res = INT_MAX;
    fun(0, a, 0, res);

    std::cout << res << '\n';
}
