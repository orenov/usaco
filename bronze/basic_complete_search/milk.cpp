#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <climits>

#define LOCAL false

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=569
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("badmilk.in", "r", stdin);
    int N, M, D, S;
    cin >> N >> M >> D >> S;

    vector<vector<int>> a(N, vector<int>(M, INT_MAX));
    for (int i = 0; i < D; ++i) {
        int p, m, t; cin >> p >> m >> t;
        a[p-1][m-1] = min(a[p-1][m-1], t); // user "p" drunk milk type "m" at time "t"
    }

    vector<int> sick(N, 0);
    for (int i = 0; i < S; ++i)  {
        int p, t; cin >> p >> t;
        sick[p-1] = t; // user "p" got sick at time "t"
    }

    int res = 0;
    for (int i = 0; i < M; ++i) {
        // check satisfy
        bool satisfy = true;
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            if (sick[j] && (a[j][i] == INT_MAX || a[j][i] >= sick[j])) satisfy = false;
            if (a[j][i] != INT_MAX) cnt++;
        }

        if (satisfy) {
            res = max(res, cnt);
        }
    }

    if (!LOCAL) freopen("badmilk.out", "w", stdout);
    std::cout << res << '\n';
}