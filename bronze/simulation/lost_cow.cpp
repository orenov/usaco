#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL false

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=735
*/

using namespace std;
using ll = long long int;

ll fun(ll x, ll y) {
    if (x == y) {
        return 0;
    }

    ll res = 0;
    ll cnt = 1;
    bool sign = true;

    while (true) {
        ll new_x = x;
        if (sign) {
            new_x += cnt;
        } else {
            new_x -= cnt;
        }

        res += cnt;

        if (y > x && new_x >= y) {
            res -= new_x - y;
            break;
        } else if (y < x && new_x <= y) {
            res -= y - new_x;
            break;
        }

        res += cnt;
        cnt *= 2;
        sign = !sign;
    }

    return res;
}

int main() {
    if (!LOCAL) freopen("lostcow.in", "r", stdin);
    int x, y; cin >> x >> y;
    if (!LOCAL) freopen("lostcow.out", "w", stdout);
    std::cout << fun(x, y) << '\n';
}
