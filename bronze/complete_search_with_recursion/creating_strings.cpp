#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <string>

#define LOCAL true

/*
    Author: Oleksii Renov
    https://cses.fi/problemset/task/1622
*/

using namespace std;
using ll = long long int;

void fun(size_t pos, int n, string& s, vector<int>& chars, vector<string>& a) {
    if (pos == n) {
        a.push_back(s);
        return;
    }


    for (size_t i = 0; i < chars.size(); ++i) {
        if (chars[i] > 0) {
            chars[i]--;
            s.push_back(i + 'a');
            fun(pos + 1, n, s, chars, a);
            s.pop_back();
            chars[i]++;
        }
    }
}

int main() {
    string s; cin >> s;
    vector<int> chars(26, 0);
    for (int i = 0; i < s.size(); ++i) {
        chars[s[i] - 'a']++;
    }
    vector<string> a;
    string t = "";
    fun(0, s.size(), t, chars, a);

    sort(a.begin(), a.end());
    std::cout << a.size() << '\n';
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << '\n';
    }
}
