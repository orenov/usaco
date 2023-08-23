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


ll product(ll value) {
    ll r = 1;
    while (value > 0) {
        r *= value % 10;
        value /= 10;
    }
    return r;
}

ll run(string& rs, ll l, ll r) {
    ll ans = r;
    ll val = product(r);

    // 1234, digits = 4, 10**4
    for (int i = 0; i < rs.size(); ++i) {
        // decr rs[i], fill other j > i with 9
        if (rs[i] == '0') break;
        ll cur = 0;

        int j = 0;
        while (j < i) {
            cur = 10 * cur + (rs[j] - '0');
            j++;
        }

        cur = 10 * cur + (rs[j] - '0' - 1);
        j++;
        while (j < rs.size()) {
            cur = 10 * cur + 9;
            j++;
        }
        
        if (cur >= l && cur <= r && product(cur) > val) {
            val = product(cur);
            ans = cur;
        }

    }

    return ans;
}


int main() {
    ll l, r; cin >> l >> r;
    string rs = to_string(r);
    std::cout << run(rs, l, r) << '\n';
}
