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

ll mod = 998244353;

ll pow(ll a, ll b) {
    if (b == 0) return 1;
    ll r = pow(a, b/2);
    r *= r;
    if (b % 2 == 1) {
        r *= a;
    }
    return r;
}


ll run(int pos, bool smaller, bool has_started, int mask, int num, int cnt, const string& x) {
    if (pos == x.size()) {
        return num;
    }

    int end = smaller ? 9 : (x[pos] - '0');
    ll cnt = 0;
    for (int i = 0; i <= end; ++i) {
        if (!has_started && (i == 0)) {
            cnt += run(pos + 1, true, false, mask, 0, k, x);
        } else if (i != end) {
            if ((1 << i) & mask) {

            }
        } else if (i == end) {
            if ((1 << i) & mask) {

            }
        }
    }

    return cnt;
}

int main() {
    ll l, r, k; cin >> l >> r >> k;

    ll res = 0;
    for (int mask = 0; mask < (1 << 10); ++mask) {
        int cnt = 0;
        for (int i = 0; i < 10; ++i) {
            if ((1 << i) & mask) cnt++;
        }

        if (cnt != k) continue;
        std::cout <<  "==== " << mask << " " << cnt << '\n';
        res += run(0, false, false, mask, 0, cnt, to_string(r));
        // -= run(0, false, false, mask, 0, k, to_string(l - 1));
    }
    
    std::cout << res << '\n';
}
