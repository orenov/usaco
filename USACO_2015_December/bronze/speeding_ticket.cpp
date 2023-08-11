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
    if (!LOCAL) freopen("speeding.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(2, 0));
    vector<vector<int>> b(m, vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        if (i > 0) a[i][0] += a[i-1][0];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i][0] >> b[i][1];
        if (i > 0) b[i][0] += b[i-1][0];
    }

    int res = 0;
    int i = 0;
    int j = 0;

    while (i < n && j < m) {
        res = max(res, b[j][1] - a[i][1]);

        if (a[i][0] < b[j][0]) {
            i++;
        } else if (a[i][0] > b[j][0]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    if (!LOCAL) freopen("speeding.out", "w", stdout);
    std::cout << res << '\n';
}
