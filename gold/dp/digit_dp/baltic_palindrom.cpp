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

ll dp[20][11][11][2][2];

ll run(int pos, int last1, int last2, bool smaller, bool started, const string& x) {
    if (pos == x.size()) {
        return 1;
    }

    if (dp[pos][last1][last2][smaller][started] != -1) {
        return dp[pos][last1][last2][smaller][started];
    }

    int end = smaller ? 9 : (x[pos] - '0');
    ll cnt = 0;
    for (int i = 0; i <= end; ++i) {
        if (i == last1 || i == last2) continue;
        if (!started && i == 0) {
            cnt += run(pos + 1, last1, last2, true, false, x);
        } else {
            cnt += run(pos + 1, i, last1, smaller || (i != end), started || (i != 0), x);
        }
    }

    dp[pos][last1][last2][smaller][started] = cnt;
    return cnt;
}

int main() {
    ll a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    ll cnt1 = run(0, 10, 10, false, false, to_string(b));
    memset(dp, -1, sizeof(dp));
    ll cnt2 = run(0, 10, 10, false, false, to_string(a-1));
    std::cout << cnt1 - cnt2 << '\n';
}
