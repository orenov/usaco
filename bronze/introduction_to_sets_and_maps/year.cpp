#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL false

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=1107
*/

using namespace std;
using ll = long long int;

int main() {
    int n; cin >> n;
    map<string, int> fmap;
    fmap["Ox"] = 1;
    fmap["Tiger"] = 2;
    fmap["Rabbit"] = 3;
    fmap["Dragon"] = 4;
    fmap["Snake"] = 5;
    fmap["Horse"] = 6;
    fmap["Goat"] = 7;
    fmap["Monkey"] = 8;
    fmap["Rooster"] = 9;
    fmap["Dog"] = 10;
    fmap["Pig"] = 11;
    fmap["Rat"] = 12;

    vector<vector<string>> data(n, vector<string>(4, ""));

    // Mildred born in previous Dragon year from Bessie
    // Gretta born in previous Monkey year from Mildred
    // Elsie born in next Ox year from Gretta
    // Paulina born in next Dog year from Bessie
    
    map<string, pair<string, int>> f;
    f["Bessie"] = {"Ox", 0};

    for (int i = 0; i < n; ++i) {
        vector<string> s(8, "");
        for (int j = 0; j < 8; ++j) {
            cin >> s[j];
        }

        string new_cow = s[0];
        string known_cow = s[7];
        string way = s[3];
        string y = s[4];

        int r = f[known_cow].second;
        int year = fmap[f[known_cow].first];
        int year_born = fmap[y];

        if (way == "next") {
            if (year_born > year) {
                f[new_cow] = {y, r};
            } else {
                f[new_cow] = {y, r + 1};
            }
        }
        if (way == "previous") {
            if (year_born >= year) {
                f[new_cow] = {y, r - 1};
            } else {
                f[new_cow] = {y, r};
            }
        } 
    }

    int res = fmap[f["Elsie"].first] - fmap[f["Bessie"].first] + 12 * f["Elsie"].second;

    std::cout << abs(res) << '\n';
}
