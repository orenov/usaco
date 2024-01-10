#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// https://codeforces.com/contest/1209/submission/230973183

int main() {
    int n, q; std::cin >> n >> q;
    std::vector<long long> a(n, 0LL);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::map<int, std::vector<int> > fmap;
    for (int i = 0; i < n; ++i) {
        if (fmap.find(a[i]) == fmap.end()) {
            fmap[a[i]] = {i, i};
        }

        fmap[a[i]][0] = std::min(i, fmap[a[i]][0]);
        fmap[a[i]][1] = std::max(i, fmap[a[i]][1]);
    }

    std::vector<std::vector<int> > intervals;
    for (auto it = fmap.begin(); it != fmap.end(); ++it) {
        intervals.push_back(it->second);
    }
    std::sort(intervals.begin(), intervals.end());

    std::vector<std::vector<int> > final;
    // [l, r] invariant
    int l = intervals[0][0];
    int r = intervals[0][1];
    
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < r) {
            r = std::max(r, intervals[i][1]);
        } else {
            final.push_back({l, r});
            l = intervals[i][0];
            r = intervals[i][1];
        }
    }

    final.push_back({l, r}); // bad

    int res = 0;

    for (int i = 0; i < final.size(); ++i) {
        l = final[i][0];
        r = final[i][1];

        std::map<int, int> cnt;
        int max_val = 0;
        for (int j = l; j <= r; ++j) {
            cnt[a[j]]++;
            max_val = std::max(max_val, cnt[a[j]]);
        }

        res += (r - l + 1) - max_val;
    }

    std::cout << res << '\n';

}