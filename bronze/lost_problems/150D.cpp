#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <sstream>
#include <string>
#include <fstream>
#include <set>

using namespace std;

using ll = long long int;

bool is_intersect(vector<vector<int> >& a, int i, int j) {
    int l = max(a[i][0], a[j][0]);
    int r = min(a[i][1], a[j][1]);
    return l <= r;
}

int main() {
    int T; cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; cin >> n;
        vector<vector<int> > a(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            int l, r; cin >> l >> r;
            a[i].push_back(l);
            a[i].push_back(r);
        }

        sort(a.begin(), a.end());
        vector<int> dp(n + 1, 0);
        vector<int> r(n, 0);

        for (int i = 0; i < n; ++i) {
            //swap(a[i][0], a[i][1]);
            r[i] = a[i][0];
        }

        for (int i = n - 2; i >= 0; --i) {
            dp[i] = dp[i + 1];

            for (int j = i + 1; j < n; ++j) {
                if (is_intersect(a, i, j)) {
                    auto it = lower_bound(r.begin() + j + 1, r.end(), max(a[i][1], a[j][1]) + 1);
                    
                    if (it != r.end()) {
                        dp[i] = max(dp[i], 2 + dp[it - r.begin()]);
                    } else {
                        dp[i] = max(dp[i], 2);
                    }
                }
            }
        }

        std::cout << n - dp[0] << '\n';
    }
}