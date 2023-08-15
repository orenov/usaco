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
    if (!LOCAL) freopen("diamond.in", "r", stdin);

    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int res = 0;
    int cnt = 0;
    int j = 0;
    int i = 0;
    while (i < n) {
        if (a[i] - a[j] <= k) {
            cnt++;
            i++;
        } else if (i > j) {
            cnt--;
            j++;
        } else {
            cnt = 1;
            j = i;
        }
        res = max(res, cnt);
    }

    if (!LOCAL) freopen("diamond.out", "w", stdout);
    std::cout << res << '\n';
}
