#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <cstring>

#define LOCAL true

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

ll mod = 998244353;

ll fast_pow(ll a, ll b) {
    if (b == 0) return 1;
    ll r = fast_pow(a, b/2);
    r *= r;
    r %= mod;
    if (b % 2 == 1) {
        r *= a;
        r %= mod;
    }
    return r;
}


ll run(int len, int n) {
    if (len == n) return 10;
    ll cnt = 0;
    int left = n - len - 1;
    // left && right
    cnt += 2 * 10 * 9 * fast_pow(10, left);
    cnt %= mod;

    cnt += 10 * 9 * 9 * left * fast_pow(10, left - 1);
    cnt %= mod;

    return cnt;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<ll> res(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        res[i] = run(i, n);
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';
}
