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
    int T; cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, m; cin >> n >> m;
        vector<vector<int>> c(m, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> c[j][i];
            }
        }

        ll res = 0;
        for (int i = 0; i < m; ++i) {
            sort(c[i].begin(), c[i].end());

            ll cnt = 1;
            ll sum = c[i][0];
            for (int j = 1; j < n; ++j) {
                res += c[i][j] * cnt - sum;
                cnt++;
                sum += c[i][j];
            }
        }

        std::cout << res << '\n';
    }
}
