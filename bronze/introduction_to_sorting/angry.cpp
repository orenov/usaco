#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL false

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=592
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("angry.in", "r", stdin);
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int res = 0;
    // 3 4 5 6 8 13
    //     i
    for (int i = 0; i < n; ++i) {
        int l = i;
        int r = i;
        int cnt = 1;
        int cnt_l = 1;
        int cnt_r = 1;
        while (true) {
            int l_next = l - 1; // next
            while (l_next >= 0 && a[l] - a[l_next] <= cnt_l) {
                l_next--;
                cnt++;
            }
            if (l_next == l - 1) break;

            l = l_next + 1;
            cnt_l++;
        }

        while (true) {
            int r_next = r + 1; // next
            while (r_next < n && a[r_next] - a[r] <= cnt_r) {
                r_next++;
                cnt++;
            }
            if (r_next == r + 1) break;
            
            r = r_next - 1;
            cnt_r++;
        }

        res = max(res, cnt);
    }


    if (!LOCAL) freopen("angry.out", "w", stdout);
    std::cout << res << '\n';
}
