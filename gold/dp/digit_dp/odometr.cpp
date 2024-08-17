#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <cstring>

#define LOCAL false

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int; 

ll dp[20][50][2][2];
// 204261015347317
// 1285155905653

ll run(int pos, int len, bool smaller, bool has_one, int target, int target2, const string& x) {
    if (pos == x.size()) {
        if (target2 != -1) {
            if (len == 20) {
                return 1;
            } else {
                return 0;
            }
        }

        if (len >= 20) {
            return 1;
        } else {
            return 0;
        }
    }

    if (dp[pos][len][smaller][has_one] != -1) {
        return dp[pos][len][smaller][has_one];
    }

    int end = smaller ? 9 : (x[pos] - '0');
    ll res = 0;
    for (int i = 0; i <= end; ++i) {
        if ((has_one || i > 0) && target2 != -1 && i != target && i != target2) continue;

        if (has_one || i > 0) {
            if (i == target) {
                len++;
            } else {
                len--;
            }
        }
        
        res += run(pos + 1, len, smaller || (i != end), has_one || (i != 0), target, target2, x);
        
        if (has_one || i > 0) {
            if (i == target) {
                len--;
            } else {
                len++;
            }
        }
    }

    dp[pos][len][smaller][has_one] = res;

    return res;
}


int main() {
    if (!LOCAL) freopen("odometer.in", "r", stdin);
    ll l, r; cin >> l >> r;

    ll cnt1 = 0;
    ll cnt2 = 0;
    ll d1 = 0;
    ll d2 = 0;
    for (int i = 0; i <= 9; ++i) {
        memset(dp, -1, sizeof(dp));
        cnt1 += run(0, 20, false, false, i, -1, to_string(r));
        memset(dp, -1, sizeof(dp));
        cnt2 += run(0, 20, false, false, i, -1, to_string(l - 1));

        for (int j = 0; j <= 9; ++j) {
            memset(dp, -1, sizeof(dp));
            d1 += run(0, 20, false, false, i, j, to_string(r));
            memset(dp, -1, sizeof(dp));
            d2 += run(0, 20, false, false, i, j, to_string(l - 1));
        }
    }

    if (!LOCAL) freopen("odometer.out", "w", stdout);
    std::cout << (cnt1 - d1/2) - (cnt2 - d2/2) << '\n';
}
