#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <cstring>

#define LOCAL true

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;


void run(int pos, int mask, int mask_min, ll num, const string& x, ll& ans) {
    if (pos == x.size()) {
        ans = min(ans, num);
        return;
    }

    int start = x[pos] - '0';
    if ((1 << start) & mask) {
        run(pos + 1, mask, mask_min, num * 10 + start, x, ans);
    }

    for (int i = start + 1; i <= 9; ++i) {
        if (!((1 << i) & mask)) continue;
        ll cur_num = num * 10 + i;
        int cur_pos = pos + 1;
        while (cur_pos != x.size()) {
            cur_num = cur_num * 10 + mask_min;
            cur_pos++;
        }
        ans = min(ans, cur_num);
        break;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, k; cin >> n >> k;
        ll ans = LLONG_MAX;

        for (int mask = 0; mask < (1 << 10); ++mask) {
            int cnt = 0;
            int mask_min = 20;
            for (int j = 0; j < 10; ++j) {
                if ((1 << j) & mask) {
                    cnt++;
                    mask_min = min(mask_min, j);
                }
                if (cnt > k) break;
            }

            if (cnt <= k && cnt != 0) {
                run(0, mask, mask_min, 0, to_string(n), ans);
            }
        }

        std::cout << ans << '\n';
    }
}
