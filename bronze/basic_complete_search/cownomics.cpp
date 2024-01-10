#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL false

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=736
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("cownomics.in", "r", stdin);
    int n, m; cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(4));
    vector<vector<int>> b(m, vector<int>(4));

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'A') a[j][0]++;
            if (s[j] == 'C') a[j][1]++;
            if (s[j] == 'G') a[j][2]++;
            if (s[j] == 'T') a[j][3]++;   
        }
    }

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'A') b[j][0]++;
            if (s[j] == 'C') b[j][1]++;
            if (s[j] == 'G') b[j][2]++;
            if (s[j] == 'T') b[j][3]++;   
        }
    }

    int res = 0;
    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        for (int j = 0; j < 4; ++j) {
            cnt += a[i][j] * b[i][j];
        }
        if (cnt == 0) res++;
    }


    if (!LOCAL) freopen("cownomics.out", "w", stdout);
    std::cout << res << '\n';
}
