#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL true

/*
    Author: Oleksii Renov
    https://codeforces.com/problemset/problem/581/D
*/

using namespace std;
using ll = long long int;


void run(int pos, vector<vector<int>>& p, vector<vector<int>>& r, vector<string>& cur, vector<string>& res) {
    if (pos == 0) {

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                //std::cout << cur[i][j];
            }
            //sstd::cout << '\n';

        }
        // validate
        int n = 0;
        while (n < cur[0].size() && cur[0][n] != '.') n++;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (cur[i][j] == '.') return;
            }
        }

        for (int i = n; i < cur.size(); ++i) {
            for (int j = 0; j < cur[0].size(); ++j) {
                if (cur[i][j] != '.') return;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = n; j < cur[0].size(); ++j) {
                if (cur[i][j] != '.') return;
            }
        }
        // write answer
        res = vector<string>(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = cur[i][j];
            }
        }

        return;
    }

    for (int i = 0; i < p.size(); ++i) {
        for (int j = 0; j < r.size(); ++j) {
            for (int k = 0; k < 2; ++k) {
            // type 1
                bool valid = true;
                vector<string> new_cur = cur;
                int xx = p[i][0];
                int yy = p[i][1];
                
                vector<int> rj = r[j];
                if (k == 1) swap(rj[0], rj[1]);

                for (int x = xx; x < xx + rj[0]; ++x) {
                    for (int y = yy; y < yy + rj[1]; ++y) {
                        if (cur[x][y] != '.') valid = false;
                        new_cur[x][y] = rj[2];
                    }
                }

                if (valid) {
                    swap(p[i], p[p.size() - 1]);
                    p.pop_back();
                    swap(r[j], r[r.size() - 1]);
                    r.pop_back();

                    p.push_back({xx, yy + rj[1]});
                    p.push_back({xx + rj[0], yy});

                    run(pos - 1, p, r, new_cur, res);

                    p.pop_back();
                    p.pop_back();
                    r.push_back(rj);
                    swap(r[j], r[r.size() - 1]);
                    p.push_back({xx, yy});
                    swap(p[i], p[p.size() - 1]);
                }
            }
        }
    }

}

int main() {
    vector<vector<int>> r(3, vector<int>(3, 0));
    cin >> r[0][0] >> r[0][1] >> r[1][0] >> r[1][1] >> r[2][0] >> r[2][1];
    r[0][2] = 'A';
    r[1][2] = 'B';
    r[2][2] = 'C'; 

    vector<vector<int>> p{{0,0}};
    vector<string> cur(300, string(300, '.'));
    vector<string> res;

    run(3, p, r, cur, res);

    if (res.size() > 0) {
        std::cout << res.size() << '\n';
        for (int i = 0; i < res.size(); ++i) {
            std::cout << res[i] << '\n';
        }
    } else {
        std::cout << "-1\n";
    }
}
