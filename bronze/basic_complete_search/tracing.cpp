#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <climits>

#define LOCAL false

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=1037
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("tracing.in", "r", stdin);
    int n, t; cin >> n >> t;
    string s; cin >> s;
    vector<vector<int>> a(t, vector<int>(3, 0));
    for (int i = 0; i < a.size(); ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][1]--;
        a[i][2]--;
    }

    sort(a.begin(), a.end());
    int cnt_x = 0;
    int small = INT_MAX;
    int big = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if (s[i] != '1') continue;
        // i - zero patient
        bool valid = false;
        for (int k = 0; k <= 251; ++k) {
            // j - time K
            string tmp(n, '0');
            vector<int> last(n, 0);
            last[i] = k;
            tmp[i] = '1';

            for (int j = 0; j < t; ++j) {
                int v = a[j][1];
                int u = a[j][2];
                if (tmp[v] == '1' && tmp[u] == '1') {
                    last[u]--;
                    last[v]--;
                    continue;
                }
                if (tmp[v] == '1' && tmp[u] == '0' && last[v] > 0) {
                    tmp[u] = '1';
                    last[u] = k;
                    last[v]--;
                    continue;
                }
                if (tmp[v] == '0' && tmp[u] == '1' && last[u] > 0) {
                    tmp[v] = '1';
                    last[v] = k;
                    last[u]--;
                    continue;
                }
            }

            if (tmp == s) {
                small = min(small, k);
                big = max(big, k);
                valid = true;
            }
        }

        if (valid) cnt_x++;
    }


    if (!LOCAL) freopen("tracing.out", "w", stdout);
    std::cout << cnt_x << ' ' << small << ' ';
    if (big == 251) {
        std::cout << "Infinity\n";
    } else {
        std::cout << big << '\n';
    }
}
