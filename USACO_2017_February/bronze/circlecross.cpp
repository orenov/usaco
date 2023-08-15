#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>

#define LOCAL false


/*
    Author: Oleksii Renov
    ABCCABDDEEFFGGHHIZIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZ
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("circlecross.in", "r", stdin);
    string s; cin >> s;
    int cnt = 0;

    for (char c = 'A'; c <= 'Z'; ++c) {
        int start = -1;
        int end = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                if (start == -1) {
                    start = i;
                } else {
                    end = i;
                }
            } 
        }

        vector<int> a(26, 0);
        for (int i = start + 1; i < end; ++i) {
            a[s[i] - 'A']++;
        }

        int r = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == 1) r++;
        }

        cnt += r;
    }


    if (!LOCAL) freopen("circlecross.out", "w", stdout);
    std::cout << cnt / 2 << '\n';
}
