#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=763

bool cmp(std::set<int>& a, std::set<int>& b) {
    for (auto it = a.begin(); it != a.end(); ++it) {
        if (b.find(*it) == b.end()) return false;
    }
    for (auto it = b.begin(); it != b.end(); ++it) {
        if (a.find(*it) == a.end()) return false;
    }
    return true;
}

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n, g; std::cin >> n >> g;
    std::vector<std::vector<int>> a(n, std::vector<int>(3, 0));

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    std::sort(a.begin(), a.end());
    int cnt = 0;

    std::map<int, int> cow_to_volume; // cow -> volume
    std::map<int, std::set<int>> volume_to_cnt; // volume to cnt cow

    for (int i = 0; i < n; ++i) {
        if (cow_to_volume.find(a[i][1]) == cow_to_volume.end()) {
            cow_to_volume[a[i][1]] = g;
            volume_to_cnt[g].insert(a[i][1]);
        }
    }

    volume_to_cnt[g].insert(-1);

    std::set<int> cur = volume_to_cnt[g];

    for (int i = 0; i < n; ++i) {
        int id = a[i][1];
        int change = a[i][2];

        int old_volume = cow_to_volume[id];
        int new_volume = old_volume + change;

        cow_to_volume[id] = new_volume;
        volume_to_cnt[old_volume].erase(id);

        if (volume_to_cnt[old_volume].size() == 0) {
            volume_to_cnt.erase(old_volume);
        }

        volume_to_cnt[new_volume].insert(id);

        if (!cmp(cur, volume_to_cnt.rbegin()->second)) {
            cnt++;
            cur = volume_to_cnt.rbegin()->second;
        }
    }

    std::cout << cnt << '\n';
}