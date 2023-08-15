#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>

#define LOCAL false

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("balancing.in", "r", stdin);
    int n; cin >> n;

    vector<vector<int>> a(n, vector<int>(2, 0));
    set<int> h;
    set<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        h.insert(a[i][0] + 1);
        h.insert(a[i][0] - 1);
        v.insert(a[i][1] + 1);
        v.insert(a[i][1] - 1);
    }
    int res = n;

    for (auto aa: h) {
        for (auto bb: v) {
            int a1 = 0;
            int a2 = 0; 
            int a3 = 0;
            int a4 = 0;

            for (int j = 0; j < n; ++j) {
                if (a[j][0] > aa && a[j][1] > bb) a1++;
                if (a[j][0] > aa && a[j][1] < bb) a2++;
                if (a[j][0] < aa && a[j][1] > bb) a3++;
                if (a[j][0] < aa && a[j][1] < bb) a4++;
            }

            //std::cout << a1 << ' ' << a2 << ' ' << a3 << ' ' << a4 << '\n';

            int val = max(max(a1, a2), max(a3, a4));

            res = min(res, val);

        }
    }


    if (!LOCAL) freopen("balancing.out", "w", stdout);
    std::cout << res << '\n';
}
