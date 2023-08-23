#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <cstring>

#define LOCAL true

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

int dp[10][10][11][2][2];


int run(int pos, int left, int last, bool smaller, bool started, const string& x) {
    if (pos == x.size()) {
        return left == 0;
    }

    if (dp[pos][left][last][smaller][started] != -1) {
        return dp[pos][left][last][smaller][started];
    }
    // 1000
    int cnt = 0;
    int end = smaller ? 9 : (x[pos] - '0');

    if (started) {
        for (int i = 0; i <= end; ++i) {
            // skip
            cnt += run(pos + 1, left, last, smaller || (i != end), true, x);
            // continue sequence
            if (left > 0 && (i > last || last == 10)) {
                cnt += run(pos + 1, left - 1, i, smaller || (i != end), true, x);
            }
        }
    } else {
        // not starting
        cnt += run(pos + 1, left, last, true, false, x);

        // start
        for (int i = 1; i <= end; ++i) {
            cnt += run(pos + 1, left, last, smaller || (i != end), true, x);
            if (left > 0) {
                cnt += run(pos + 1, left - 1, i, smaller || (i != end), true, x);
            }
        }
    }

    dp[pos][left][last][smaller][started] = cnt;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        ll x, y; cin >> x >> y;
        int res = 0;
        int cnt = 0;
        for (int i = 9; i >= 1; --i) {
            memset(dp, -1, sizeof(dp));
            int cnt1 = run(0, i, 10, false, false, to_string(y));
            memset(dp, -1, sizeof(dp));
            int cnt2 = run(0, i, 10, false, false, to_string(x-1));
            //std::cout << i << ' ' << cnt1 << ' ' << cnt2 << '\n';
            if (cnt1 - cnt2 > 0) {
                res = i;
                cnt = cnt1 - cnt2;
                break;
            }
        }
        std::cout << "Case " << qq << ": " << res << ' ' << cnt << '\n';
    }
}
