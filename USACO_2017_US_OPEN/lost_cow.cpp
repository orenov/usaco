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

int main() {
    if (!LOCAL) freopen("lostcow.in", "r", stdin);
    int x, y; cin >> x >> y;
    int res = 0;
    int step = 1;
    int cnt = 1;

    while () {
        int new_x = x;
        if (cnt % 2 == 1) {
            new_x += step;
        } else {
            new_x -= step;
        }


        step *= 2;
    }


    if (!LOCAL) freopen("lostcow.out", "w", stdout);
    std::cout << res << '\n';
}
