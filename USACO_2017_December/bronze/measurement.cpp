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

bool fun(vector<int>& a, vector<int>& b) {
    int old_max = max(a[0], max(a[1], a[2]));
    vector<int> old;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == old_max) old.push_back(i);
    }

    int new_max = max(b[0], max(b[1], b[2]));
    vector<int> neww;
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] == new_max) neww.push_back(i);
    }

    if (old.size() != neww.size()) return false;
    for (int i = 0; i < old.size(); ++i) {
        if (old[i] != neww[i]) return false;
    }
    return true;
}

int main() {
    if (!LOCAL) freopen("measurement.in", "r", stdin);
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(3, 0));
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        string s;
        cin >> s;
        if (s == "Mildred") a[i][1] = 0;
        if (s == "Elsie") a[i][1] = 1;
        if (s == "Bessie") a[i][1] = 2;
        cin >> a[i][2];
    } 

    sort(a.begin(), a.end());
    vector<int> m(3, 7);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> new_m = m;
        new_m[a[i][1]] += a[i][2];
        if (!fun(m, new_m)) cnt++;
        m = new_m;
        //std::cout << m[0] << ' ' << m[1] << ' ' << m[2] << '\n';
    }

    if (!LOCAL) freopen("measurement.out", "w", stdout);
    std::cout << cnt << '\n';
}
