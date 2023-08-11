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
    if (!LOCAL) freopen("shuffle.in", "r", stdin);
    int n; cin >> n;
    vector<int> a(n, 0);
    vector<int> c(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    // 3 shuffles
    for (int i = 0; i < 3; ++i) {
        vector<int> out = c;
        for (int j = 0; j < n; ++j) {
            out[j] = c[a[j]-1];
        }
        c = out;
    }

    if (!LOCAL) freopen("shuffle.out", "w", stdout);
    for (int i = 0; i < n; ++i) {
        std::cout << c[i] << '\n';
    }
}
