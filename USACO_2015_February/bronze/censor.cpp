#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <string>

#define LOCAL false

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("censor.in", "r", stdin);
    string s, t;
    cin >> s >> t;
    string res;

    int i = 0;
    while (i < s.size() && i < t.size()) {
        res += s[i];
        ++i;
    }

    while (i < s.size()) {
        int start = res.size() - t.size();
        bool f = true;
        for (int j = 0; j < t.size(); ++j) {
            if (t[j] != res[start+j]) {
                f = false;
                break;
            }
        }

        if (f) {
            for (int j = 0; j < t.size(); ++j) {
                res.pop_back();
            }
        }
        res += s[i];
        i++;
    }

    if (!LOCAL) freopen("censor.out", "w", stdout);
    std::cout << res << '\n';
}
