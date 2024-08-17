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

int dp[12][100][2][2][100];

int run(int pos, int sum, bool smaller, bool started, int num, int k, const string& x) {
    if (k > 100) return 0;
    if (pos == x.size()) {
        if (num % k == 0 && sum % k == 0) return 1;
        return 0;
    }

    if (dp[pos][sum % k][smaller][started][num % k] != -1) {
        return dp[pos][sum % k][smaller][started][num % k];
    }

    int end = smaller ? 9 : (x[pos] - '0');
    int cnt = 0;
    for (int i = 0; i <= end; ++i) {
        cnt += run(pos + 1, sum + i, smaller || (i != end), started || (i != 0), num * 10 + i, k, x);
    }
    dp[pos][sum % k][smaller][started][num % k] = cnt;
    return cnt;
}

int main() {
    int T; cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        ll a, b, k; cin >> a >> b >> k;
        memset(dp, -1, sizeof(dp));
        int cnt1 = run(0, 0, false, false, 0, k, to_string(b));
        memset(dp, -1, sizeof(dp));
        int cnt2 = run(0, 0, false, false, 0, k, to_string(a-1));
        std::cout << "Case " << qq << ": " << cnt1 - cnt2 << '\n';
    }
}
