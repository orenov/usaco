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

vector<int> to_array(string& s) {
    vector<int> a(26, 0);
    for (int i = 0; i < s.size(); ++i) {
        a[s[i]-'a']++;
    }
    return a;
}

int main() {
    if (!LOCAL) freopen("blocks.in", "r", stdin);
    int n; cin >> n;
    vector<int> a(26, 0);
    for (int i = 0; i < n; ++i) {
        string s1, s2; cin >> s1 >> s2;
        auto a1 = to_array(s1);
        auto a2 = to_array(s2);
        for (int k = 0; k < 26; ++k) {
            a[k] += max(a1[k], a2[k]);
        }
    }

    if (!LOCAL) freopen("blocks.out", "w", stdout);
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << '\n';
    }
}
