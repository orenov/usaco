#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <climits>

#define LOCAL true

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=1061
*/

using namespace std;
using ll = long long int;

int main() {
    int n; cin >> n;
    vector<vector<int>> north, east;
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        int x, y; cin >> x >> y;
        if (c == 'N') north.push_back({x, y, i});
        if (c == 'E') east.push_back({x, y, i});
    }

    vector<int> res(n, INT_MAX);
    for (int k = 0; k < n; ++k) {
        int id = -1;
        int val = -1;

        for (int i = 0; i < north.size(); ++i) {
            for (int j = 0; j < east.size(); ++j) {
                //if (res[north[i][2]] != INT_MAX) continue;
                //if (res[east[j][2]] != INT_MAX) continue;
                if (north[i][0] < east[j][0]) continue;
                if (north[i][1] > east[j][1]) continue;
                int time_n = east[j][1] - north[i][1];
                if (res[north[i][2]] != INT_MAX && time_n > res[north[i][2]]) {
                    time_n = INT_MAX;
                }
                int time_e = north[i][0] - east[j][0];
                if (res[east[j][2]] != INT_MAX && time_e > res[east[j][2]]) {
                    time_e = INT_MAX;
                }
                //std::cout << "north " << north[i][0] << ' ' << north[i][1] << '\n';
                //std::cout << "east " << east[j][0] << ' ' << east[j][1] << '\n';
                
                //std::cout << time_n << ' ' << time_e << '\n';
                if (res[north[i][2]] == INT_MAX && time_n > time_e && (id == -1 || val > time_n)) {
                    id = north[i][2];
                    val = time_n;
                }
                if (res[east[j][2]] == INT_MAX && time_n < time_e && (id == -1 || val > time_e)) {
                    id = east[j][2];
                    val = time_e;
                }
            }
        }
        if (id == -1) break;
        //std::cout << "=== " << id << ' ' << val << '\n';
        res[id] = val;
    }

    for (int i = 0; i < res.size(); ++i) {
        if (res[i] == INT_MAX) {
            std::cout << "Infinity\n";
        } else {
            std::cout << res[i] << '\n';
        }
    }



}
