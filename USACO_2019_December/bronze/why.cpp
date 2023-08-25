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
    if (!LOCAL) freopen("whereami.in", "r", stdin);
    if (!LOCAL) freopen("whereami.out", "w", stdout);
    
    int n; cin >> n;
    string s; cin >> s;
    

    for (int k = 1; k <= n; ++k) {
        map<string, int> fmap;

        for (int i = 0; i <= n - k; ++i) {
            string tmp;
            for (int j = i; j < i + k; ++j) {
                tmp += s[j];
            }
            fmap[tmp]++;
        }

        bool good = true;
        for (const auto& x: fmap) {
            if (x.second != 1) {
                good = false;
            }
        }

        if (good) {
            std::cout << k << '\n';
            return 0;
        }
    }

}
