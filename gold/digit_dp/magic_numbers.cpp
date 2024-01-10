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

ll dp[2001][2001][2];

ll run(int pos, bool smaller, string& a, int m, int d, ll num) {
    if (pos == a.size()) {
        return num % m == 0;
    }

    num %= m;
    if (dp[pos][num][smaller] != -1) {
        return dp[pos][num][smaller];
    }

    // assume we're on check
    int start = (pos == 0) ? 1 : 0;
    int end = smaller ? 9 : (a[pos] - '0');
    ll cnt = 0;

    for (int i = start; i <= end; ++i) {
        if ((pos % 2 == 0) && i != d) {
            cnt += run(pos + 1, smaller || (i != end), a, m, d, num * 10 + i);
        }
        if ((pos % 2 == 1) && i == d) {
            cnt += run(pos + 1, smaller || (i != end), a, m, d, num * 10 + i);
        }
        cnt %= 1000000007;
    }

    dp[pos][num][smaller] = cnt;
    return cnt;
}

bool is_magic(string& x, int d, int m) {
    for (int i = 1; i < x.size(); i +=2) {
        if (x[i] != (d + '0')) return false;
    }
    for (int i = 0; i < x.size(); i +=2) {
        if (x[i] == (d + '0')) return false;
    }
    ll num = 0;
    for (int i = 0; i < x.size(); ++i) {
        num = 10 * num + (x[i] - '0');
        if (num >= m) {
            num %= m;
        }
    }

    return num == 0;
}

int main() {
    int m, d; cin >> m >> d;
    string a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    ll cnt1 = run(0, false, b, m, d, 0);
    memset(dp, -1, sizeof(dp));
    ll scnt2 = run(0, false, a, m, d, 0);

    if (cnt1 - cnt2 < 0) {
        cnt1 += 1000000007;
    }
    if (is_magic(a, d, m)) {
        cnt2--;
    }
    
    std::cout << cnt1 - cnt2 << '\n';    
}
