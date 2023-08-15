#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <set>

#define LOCAL false

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("guess.in", "r", stdin);
    int n; cin >> n;
    
    vector<set<string>> a(n, set<string>());
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            string v; cin >> v;
            a[i].insert(v);
        }
    }

    int res = 0;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            if (i == j) continue;

            int cnt = 0;
            for (auto w: a[i]) {
                if (a[j].find(w) != a[j].end()) {
                    cnt++;
                }
            }
            res = max(res, cnt);
        }
    }

    if (!LOCAL) freopen("guess.out", "w", stdout);
    std::cout << res + 1 << '\n';
}
