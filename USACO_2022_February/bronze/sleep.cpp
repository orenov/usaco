#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL true

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

int calc_max(vector<int>& a) {
    int val = a[0];
    for (int i = 0; i < a.size(); ++i) {
        val = max(val, a[i]);
    }
    return val;
}

bool same(vector<int>& a) {
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] != a[0]) return false;
    }
    return true;
}


int fun(vector<int>& a) {
    vector<int> b = a;
    int old_m = -1;
    int m = calc_max(b);

    while (true) {        
        vector<int> new_b;
        
        int cur = 0;
        for (int i = 0; i < a.size(); ++i) {
            cur += a[i];
            if (cur >= m || i == a.size() - 1) {
                new_b.push_back(cur);
                cur = 0;
            }
        }

        if (same(new_b)) {
            return a.size() - new_b.size();
        }
        m++;
    }
}

int main() {
    int T; cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        std::cout << fun(a) << '\n';
    }
}
