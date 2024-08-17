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

int dp[100];

bool is_pali(ll x) {
    vector<int> d;
    while (x > 0) {
        d.push_back(x % 10);
        x/=10;
    }
    for (int i = 0; i < d.size()/2; ++i) {
        if (d[i] != d[d.size()-i-1]) return false;
    }
    return true;
}

bool is_pali(vector<int> d) {
    for (int i = 0; i < d.size()/2; ++i) {
        if (d[i] != d[d.size()-i-1]) return false;
    }
    return true;
}


ll run(int pos, int len, bool smaller, bool started, const string& x, ll num) {
    if (pos == x.size()) {        
        if (is_pali(num)) {
            return 1;
        }
        return 0;
    }

    int n = x.size();
    int max_seq = n - pos + len;
    if (smaller && started && max_seq - 2 * len < 0) {
        vector<int> d;
        ll num2 = num;
        ll len2 = 2 * len;
        while (max_seq - len2 < 0) {
            d.push_back(num2 % 10);
            num2 /= 10;
            len2--;
        }
        ll p = 0;
        ll dig = 1;
        for (int i = 0; i < d.size(); ++i) {
            p += dig * d[i];
            dig *= 10;
        }
        //std::cout << p  << ' ' << d.size() << ' ' << len << ' ' << max_seq << ' ' << pos << ' ' << num << ' ' << is_pali(d) << '\n';
        return is_pali(d);
    }

    if (smaller && started && max_seq - 2 * len >= 0) {

        int left = max_seq - 2 * len;
        ll res = 1;
        while (left >= 2) {
            res *= 10;
            left -= 2;
        }
        if (left > 0) res *= 10;
        //std::cout << pos << ' ' << num << ' ' << x.size() - pos - len << ' ' << res << '\n';
        return res;
    }

    int end = smaller ? 9 : (x[pos] - '0');
    int cnt = 0;
    for (int i = 0; i <= end; ++i) {
        if (i == 0 && !started) {
            cnt += run(pos + 1, len, true, false, x, 0);
        } else {
            cnt += run(pos + 1, len + 1, smaller || (i != end), started || (i != 0), x, 10 * num + i);
        }
    }

    return cnt;
}

int main() {
    int T; cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        ll x, y; cin >> x >> y;
        if (x < y) swap(x, y);
        memset(dp, -1, sizeof(dp));
        ll cnt1 = run(0, 0, false, false, to_string(x), 0);
        //std::cout << "====\n";
        memset(dp, -1, sizeof(dp));
        ll cnt2 = run(0, 0, false, false, to_string(y - 1), 0);
        //std::cout << cnt1 << ' ' << cnt2 << '\n';
        std::cout << "Case " << qq << ": " << cnt1 - cnt2 << '\n';
    }
}
