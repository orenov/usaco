#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <climits>

#define LOCAL false

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("lifeguards.in", "r", stdin);
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(2, 0));

    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
    }

    vector<int> l(1001, 0);
    for (int i = 0; i < n; ++i) {
        for (int k = a[i][0] + 1; k <= a[i][1]; ++k) {
            l[k]++;
        }
    }

    int covered = 0;
    for (int i = 0; i < l.size(); ++i) {
        if (l[i] > 0) covered++;
    }


    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int k = a[i][0] + 1; k <= a[i][1]; ++k) {
            if (l[k] == 1) cnt++;
        }
        res = min(res, cnt);
    }

    if (!LOCAL) freopen("lifeguards.out", "w", stdout);

    std::cout << covered - res << '\n';
}
