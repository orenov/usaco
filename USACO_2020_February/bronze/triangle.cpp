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
    if (!LOCAL) freopen("triangles.in", "r", stdin);
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(2, 0));
    for (int i = 0; i < a.size(); ++i) {
        cin >> a[i][0] >> a[i][1];
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                bool is_x = a[i][0] == a[j][0]; 
                bool is_y = a[i][1] == a[k][1];
                if (is_x && is_y) {
                    res = max(res, abs(a[i][1] - a[j][1]) * abs(a[i][0] - a[k][0]));
                }
            }
        }
    }

    if (!LOCAL) freopen("triangles.out", "w", stdout);
    std::cout << res << '\n';
}
