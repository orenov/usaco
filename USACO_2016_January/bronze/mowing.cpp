#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <climits>

#define LOCAL false

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("mowing.in", "r", stdin);
    map<pair<int,int>, int> fmap;
    int n; cin >> n;
    int res = INT_MAX;
    
    int x = 0;
    int y = 0;

    int cnt = 0;

    fmap[{x, y}] = cnt;

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int k; cin >> k;
        while (k > 0) {
            //std::cout << x << ' ' << y << ' ' << cnt << '\n';
            if (s == "N") {
                y++;
            }
            if (s == "S") {
                y--;
            }
            if (s == "W") {
                x--;
            }
            if (s == "E") {
                x++;
            }
            if (fmap.find({x, y}) != fmap.end()) {
                res = min(res, cnt - fmap[{x, y}] + 1);
            }
            k--;
            cnt++;
            fmap[{x, y}] = cnt;
        }
    }


    if (!LOCAL) freopen("mowing.out", "w", stdout);
    if (res == INT_MAX) {
        res = -1;
    } 
    std::cout << res << '\n';
}
