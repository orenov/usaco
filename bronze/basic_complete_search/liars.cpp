#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL true

/*
    Author: Oleksii Renov
    http://usaco.org/index.php?page=viewproblem2&cpid=1228
*/

using namespace std;
using ll = long long int;

int main() {
    int n; cin >> n;
    vector<int> l;
    vector<int> g;
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        int x; cin >> x;
        if (c == 'G') g.push_back(x);
        if (c == 'L') l.push_back(x);
    }

    int res = n - 1;
    sort(g.begin(), g.end());
    sort(l.begin(), l.end());

    for (int i = 0; i < g.size(); ++i) {
        int cnt = g.size() - i - 1;
        for (int j = 0; j < l.size(); ++j) {
            if (l[j] < g[i]) cnt++;
        }
        res = min(res, cnt);
    }

    std::cout << res << '\n';
}
