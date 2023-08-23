#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cstring>

#define LOCAL false

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

ll poww(ll a, ll b) {
    ll r = 1;
    while (b > 0) {
        r *= a;
        b--;
    }
    return r;
}

ll dp[20][2][2];

ll run(int pos, bool smaller, bool started, const string& x, ll r) {
    if (r <= 0) return 0;

    if (pos == x.size()) {
        return 0;
    }

    if (dp[pos][smaller][started] != -1) {
        return dp[pos][smaller][started];
    }

    int end = smaller ? 9 : (x[pos] - '0');
    int left = x.size() - pos - 1;
    // 10
    // pos = 0, x.size() = 2
    // left = 2 - 0 - 1 = 1;
    // pow(10, left) = 10
    // end = 1
    ll cnt = 0;
    for (int i = 0; i <= end; ++i) {
        if (i == 0 && !started) {
            cnt += run(pos + 1, true, false, x, r);
        } else if (smaller || (i != end)) {
            cnt += poww(10, left) * i + run(pos + 1, smaller || (i != end), started || (i != 0), x, r);
        } else {
            ll v = 1 + r % (poww(10, left));
            cnt += v * i + run(pos + 1, smaller || (i != end), started || (i != 0), x, r);
        }
    }

    dp[pos][smaller][started] = cnt;

    return cnt;
}

int main() {
    int T; cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        ll l, r;
        cin >> l >> r;
        memset(dp, -1, sizeof(dp));
        ll cnt1 = run(0, false, false, to_string(r), r);
        memset(dp, -1, sizeof(dp));
        ll cnt2 = run(0, false, false, to_string(l-1), l-1);
        std::cout << cnt1 - cnt2 << '\n';
    }
}