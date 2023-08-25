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
    if (!LOCAL) freopen("cowqueue.in", "r", stdin);

    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
    }

    sort(a.begin(), a.end());

    int cur = 0;
    for (int i = 0; i < a.size(); ++i) {
        int start = max(cur, a[i][0]);
        cur = start + a[i][1];
    }


    if (!LOCAL) freopen("cowqueue.out", "w", stdout);
    std::cout << cur << '\n';
}
