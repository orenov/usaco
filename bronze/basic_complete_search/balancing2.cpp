#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>

#define LOCAL false

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=619
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
        v.insert(a[i][1] + 1);
    }
    h.insert(*h.begin() - 2);
    v.insert(*v.begin() - 2);

    int res = n;
    sort(a.begin(), a.end());

    for (auto bb: v) {
        //std::cout << "Start: " << bb << '\n';
        int upper_left = 0;
        int upper_right = 0; 
        int bottom_left = 0;
        int bottom_right = 0;

        // calc base
        int aa = *h.begin();
        for (int j = 0; j < n; ++j) {
            if (a[j][0] > aa && a[j][1] > bb) upper_right++;
            if (a[j][0] > aa && a[j][1] < bb) bottom_right++;
            if (a[j][0] < aa && a[j][1] > bb) upper_left++;
            if (a[j][0] < aa && a[j][1] < bb) bottom_left++;
        }

        //std::cout << upper_right << ' ' << upper_left << ' ' << bottom_right << ' ' << bottom_left << '\n';

        res = min(res, max(max(upper_left, upper_right), max(bottom_left, bottom_right)));

        // continue
        int j = 0;
        while (j < n) {
            int cur = a[j][0];
            while (j < n && a[j][0] == cur) {
                if (a[j][1] > bb) {
                    upper_right--;
                    upper_left++;
                } else {
                    bottom_right--;
                    bottom_left++;
                }
                j++;
            }
            //std::cout << upper_right << ' ' << upper_left << ' ' << bottom_right << ' ' << bottom_left << '\n';
            res = min(res, max(max(upper_left, upper_right), max(bottom_left, bottom_right)));
        }

    }


    if (!LOCAL) freopen("balancing.out", "w", stdout);
    std::cout << res << '\n';
}
