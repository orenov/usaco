#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <string>

#define LOCAL true

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) {
        freopen("cowsignal.in", "r", stdin);
    }

    int m, n, k;
    cin >> m >> n >> k;
    vector<string> a(m, "");
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    if (!LOCAL) {
        freopen("cowsignal.out", "w", stdout);
    }

    for (int i = 0; i < m; ++i) {
        string out = "";
        for (int j = 0; j < n; ++j) {
            for (int q = 0; q < k; ++q) {
                out.push_back(a[i][j]);
            }
        }
        for (int q = 0; q < k; ++q) {
            std::cout << out << '\n';
        }
    }
}
