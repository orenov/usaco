#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>

#define LOCAL false

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=739
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("cownomics.in", "r", stdin);
    int n, m; cin >> n >> m;
    
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<int>> b(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'A') a[i][j] = 1;
            if (s[j] == 'C') a[i][j] = 2;
            if (s[j] == 'G') a[i][j] = 3;
            if (s[j] == 'T') a[i][j] = 4;   
        }
    }

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'A') b[i][j] = 1;
            if (s[j] == 'C') b[i][j] = 2;
            if (s[j] == 'G') b[i][j] = 3;
            if (s[j] == 'T') b[i][j] = 4;   
        }
    }

    int res = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            for (int k = j + 1; k < m; ++k) {
                vector<int> as(600, 0);
                for (int q = 0; q < n; ++q) {
                    as[100 * a[q][i] + 10 * a[q][j] + a[q][k]]++;
                }
                int cnt = 0;
                for (int q = 0; q < n; ++q) {
                    if (as[100 * b[q][i] + 10 * b[q][j] + b[q][k]] != 0) {
                        cnt++;
                        break;
                    }
                }

                if (cnt == 0) {
                    res++;
                }

            }
        }
    }


    if (!LOCAL) freopen("cownomics.out", "w", stdout);
    std::cout << res << '\n';
}