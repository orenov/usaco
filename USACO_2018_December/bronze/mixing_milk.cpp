#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL false

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) {
        freopen("mixmilk.in", "r", stdin);
    }

    vector<int> tank(3, 0);
    vector<int> cur(3, 0);
    for (int i = 0; i < 3; ++i) {
        cin >> tank[i] >> cur[i];
    }

    for (int i = 0; i < 100; ++i) {
        int x = i % 3;
        int y = (i + 1) % 3;

        int total = cur[x] + cur[y];
        if (total > tank[y]) {
            cur[y] = tank[y];
            cur[x] = total - tank[y];
        } else {
            cur[y] = total;
            cur[x] = 0;
        }
    }

    if (!LOCAL) {
        freopen("mixmilk.out", "w", stdout);
    }
    std::cout << cur[0] << '\n' << cur[1] << '\n' << cur[2] << '\n';
}
