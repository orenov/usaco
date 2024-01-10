#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL false

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=963
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("gymnastics.in", "r", stdin);
    int k, n; cin >> k >> n;

    vector<vector<int>> a(k, vector<int>(n, 0));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            int val; cin >> val;
            a[i][val-1] = j;
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cnt = 0;
            for (int q = 0; q < k; ++q) {
                if (a[q][i] > a[q][j]) cnt++;
                if (a[q][i] < a[q][j]) cnt--;
            }
            if (cnt == k || cnt == -k) {
                res++;
            }
        }
    }


    if (!LOCAL) freopen("gymnastics.out", "w", stdout);
    std::cout << res << '\n';
}
