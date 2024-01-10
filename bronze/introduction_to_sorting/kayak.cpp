#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL true

/*
    Author: Oleksii Renov
    https://codeforces.com/contest/863/problem/B
*/

using namespace std;
using ll = long long int;

int main() {
    int n; cin >> n;
    vector<int> a(2*n, 0);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int res = INT_MAX;
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = i + 1; j < 2 * n; ++j) {
            int last = -1;
            int cnt = 0;
            for (int k = 0; k < 2 * n; ++k) {
                if (k == i || k == j) continue;

                if (last == -1) {
                    last = a[k];
                } else {
                    cnt += a[k] - last;
                    last = -1;
                }

            }


            res = min(res, cnt);
        }
    }

    std::cout << res << '\n';
}
