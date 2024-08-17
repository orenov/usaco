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

ll fact[21];

ll run(int pos, vector<int>& need, bool smaller, bool started, const string& x) {
    if (pos == x.size()) {
        for (int i = 0; i < need.size(); ++i) {
            if (need[i] >= 1) return 0;
        }
        return 1;
    }

    int end = smaller ? 9 : (x[pos] - '0');
    ll cnt = 0;

    ll mem = 0;

    if (smaller && started) {
        int left = x.size() - pos;
        int sum_need = 0;
        int any = 0;
        ll fact_req = 1;
        for (int i = 0; i < need.size(); ++i) {
            if (need[i] == -1) {
                any++;
            }
            if (need[i] != -1) {
                sum_need += need[i];
                fact_req *= fact[need[i]];
            }
        }
        if (sum_need > left) return 0;
        if (sum_need == left) return fact[left] / fact_req;
        if (sum_need < left) {
            ll res = fact[left] / (fact_req  * fact[left - sum_need]);
            for (int i = 0 ; i < left - sum_need; ++i) {
                res *= any;
            }
            return res;
        }
    }

    for (int i = 0; i <= end; ++i) {
        if (i == 0 && !started) {
            cnt += run(pos + 1, need, true, false, x);
        } else if (need[i] > 0) {
            need[i]--;
            cnt += run(pos + 1, need, smaller || (i != end), started || (i != 0), x);
            need[i]++;   
        } else if (need[i] == -1) {
            cnt += run(pos + 1, need, smaller || (i != end), started || (i != 0), x);
        }
    }

    return cnt;
}


ll calc(ll val, vector<int>& a) {
    ll r = 0;
    for (int mask = 0; mask < (1 << 10); ++mask) {
        vector<int> need(10, -1);
        int sign = 1;
        for (int i = 0; i < 10; ++i) {
            if (mask & (1 << i)) {
                need[i] = a[i];
                sign *= -1;
            }
        }
        ll value = run(0, need, false, false, to_string(val));
        r += sign * value;
    }

    return r;
}

int main() {
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < 20; ++i) {
        fact[i] = i * fact[i-1];
    }

    int T; cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        ll l, r; cin >> l >> r;
        vector<int> a(10, 0);
        for (int i = 0; i < 10; ++i) {
            cin >> a[i];
        }
        std::cout << calc(r, a) - calc(l-1, a) << '\n';
    }

    return 0;
}
