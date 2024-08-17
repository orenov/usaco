#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using ll = long long int;


bool solve(ll from, ll x, std::vector<ll>& a, std::vector<ll>& b, char c1, char c2, std::map<char, std::vector<ll>>& fmap) {
    // first a
    {
        ll id = from;
        ll cur_a = 0;
        ll cur_b = 0;
        for (ll i = from; i < a.size(); ++i) {
            if (cur_a < x) {
                cur_a += a[i];
                id = i;
            } else {
                cur_b += b[i];
            }
        }

        if (cur_a >= x && cur_b >= x) {
            fmap[c1] = {from+1, id+1};
            fmap[c2] = {id+2, (ll)a.size()};
            return true;
        }
    }

    // first b
    {
        ll id = from;
        ll cur_a = 0;
        ll cur_b = 0;
        for (ll i = from; i < a.size(); ++i) {
            if (cur_b < x) {
                cur_b += b[i];
                id = i;
            } else {
                cur_a += a[i];
            }
        }

        if (cur_a >= x && cur_b >= x) {
            fmap[c2] = {from+1, id+1};
            fmap[c1] = {id+2, (ll)a.size()};
            return true;
        }
    }

    return false;
}

int main() {
    ll T; std::cin >> T;
    for (ll qq = 1; qq <= T; ++qq) {
        ll n; std::cin >> n;
        std::vector<ll> a(n), b(n), c(n);
        ll total = 0;

        for (ll i = 0; i < n; ++i) {
            std::cin >> a[i];
            total += a[i];
        }
        for (ll i = 0; i < n; ++i) {
            std::cin >> b[i];
        }
        for (ll i = 0; i < n; ++i) {
            std::cin >> c[i];
        }

        ll need = total / 3;
        if (total % 3 != 0) need++;
        std::map<char, std::vector<ll>> fmap;

        // a
        {
            ll i = 0;
            ll cur = 0;
            while (cur < need) {
                cur += a[i];
                ++i;
            }
            // [0, i - 1] - a
            fmap['a'] = {1, i};
            if (solve(i, need, b, c, 'b', 'c', fmap)) {
                std::cout << fmap['a'][0] << ' ' << fmap['a'][1] << ' ' << fmap['b'][0] << ' ' << fmap['b'][1] << ' ' << fmap['c'][0] << ' ' << fmap['c'][1] << '\n';
                continue;
            }
        }

        // b
        {
            ll i = 0;
            ll cur = 0;
            while (cur < need) {
                cur += b[i];
                ++i;
            }
            // [0, i - 1] - b
            fmap['b'] = {1, i};
            if (solve(i, need, a, c, 'a', 'c', fmap)) {
                std::cout << fmap['a'][0] << ' ' << fmap['a'][1] << ' ' << fmap['b'][0] << ' ' << fmap['b'][1] << ' ' << fmap['c'][0] << ' ' << fmap['c'][1] << '\n';
                continue;
            }
        }
        
        // c
        {
            ll i = 0;
            ll cur = 0;
            while (cur < need) {
                cur += c[i];
                ++i;
            }
            // [0, i - 1] - c
            fmap['c'] = {1, i};
            if (solve(i, need, a, b, 'a', 'b', fmap)) {
                std::cout << fmap['a'][0] << ' ' << fmap['a'][1] << ' ' << fmap['b'][0] << ' ' << fmap['b'][1] << ' ' << fmap['c'][0] << ' ' << fmap['c'][1] << '\n';
                continue;
            }
        }
        
        std::cout << -1 << '\n';
    }
}