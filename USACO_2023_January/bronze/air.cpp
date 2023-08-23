#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <climits>

#define LOCAL false

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> cows(n, vector<int>(3, 0));
    for (int i = 0; i < n; ++i) {
        cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
    }
    vector<vector<int>> air(m, vector<int>(4, 0));
    for (int i = 0; i < m; ++i) {
        cin >> air[i][0] >> air[i][1] >> air[i][2] >> air[i][3];
    }

    int res = INT_MAX;
    for (int mask = 0; mask < (1 << m); ++mask) {
        int price = 0;
        vector<int> temp(101, 0);

        for (int i = 0; i < m; ++i) {
            if (mask & (1 << i)) {
                price += air[i][3];
                for (int j = air[i][0]; j <= air[i][1]; ++j) {
                    temp[j] += air[i][2];
                }
            }
        }

        // check
        bool valid = true;

        for (int i = 0; i < n; ++i) {
            for (int j = cows[i][0]; j <= cows[i][1]; ++j) {
                if (temp[j] < cows[i][2]) valid = false;
            }
        }

        if (valid) {
            res = min(res, price);
        }
    }

    std::cout << res << '\n';
}