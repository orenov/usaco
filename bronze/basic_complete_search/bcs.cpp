#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL false

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=640
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("bcs.in", "r", stdin);
    int n, k; cin >> n >> k;
    vector<string> a(n, "");
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<string>> b(k, vector<string>(n, ""));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b[i][j];
        }
    }

    int x = -1;
    int y = -1;

    for (int i = 0; i < b.size(); ++i) {
        for (int j = i + 1; j < b.size(); ++j) {
            vector<string> p1 = b[i];
            vector<string> p2 = b[j];

            for (int h1 = 0; h1 < n; ++h1) {
                for (int v1 = 0; v1 < n; ++v1) {
                    for (int h2 = 0; h2 < n; ++h2) {
                        for (int v2 = 0; v2 < n; ++v2) {

                            bool valid = true;
                            for (int h = 0; h < n; ++h) {
                                for (int v = 0; v < n; ++v) {
                                    if (a[h][v] == '.') {
                                        if (p1[(h + h1) % n][(v + v1) % n] == '.' && p2[(h + h2) % n][(v + v2) % n] == '.') {
                                        } else {
                                            valid = false;
                                        }
                                    }

                                    if (a[h][v] == '#') {
                                        if (p1[(h + h1) % n][(v + v1) % n] == '#' && p2[(h + h2) % n][(v + v2) % n] == '.') {
                                        } else if (p1[(h + h1) % n][(v + v1) % n] == '.' && p2[(h + h2) % n][(v + v2) % n] == '#') {
                                        } else {
                                            valid = false;
                                        }
                                    }
                                }
                            }

                            if (valid) {
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }



        }
    }

    if (!LOCAL) freopen("bcs.out", "w", stdout);
    std::cout << min(x, y) + 1 << ' ' << max(x, y) + 1 << '\n';
}
