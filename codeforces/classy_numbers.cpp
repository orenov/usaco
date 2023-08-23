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
int dp[19][19][2];

// non_zero <= 3
int run(int pos, int non_zero, bool smaller, const string& x) {
    if (non_zero > 3) return 0;
    if (pos == x.size()) return 1;
    if (non_zero == 3 && smaller) {
        return 1;
    }

    if (dp[pos][non_zero][smaller] != -1) {
        return dp[pos][non_zero][smaller];
    }
    
    int end = smaller ? 9 : (x[pos] - '0');
    int cnt = 0;
    
    for (int i = 0; i <= end; ++i) {
        if (i == 0) {
            cnt += run(pos + 1, non_zero, smaller || (i != end), x);
        } else {
            cnt += run(pos + 1, non_zero + 1, smaller || (i != end), x);
        }
    }

    dp[pos][non_zero][smaller] = cnt;

    return cnt;
}

int main() {
    int T; cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        ll l, r;
        cin >> l >> r;
        memset(dp, -1, sizeof(dp));
        int cnt1 = run(0, 0, false, to_string(r));
        memset(dp, -1, sizeof(dp));
        int cnt2 = run(0, 0, false, to_string(l-1));
        std::cout << cnt1 - cnt2 << '\n';
    }
}
