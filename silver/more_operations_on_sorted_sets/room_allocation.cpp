#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

// https://cses.fi/problemset/task/1164

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> events;

    for (int i = 0; i < n; ++i) {
        int l, r; std::cin >> l >> r;
        events.push_back({l, 0, i});
        events.push_back({r, 1, i});
    }

    std::sort(events.begin(), events.end());

    std::set<int> rooms;
    for (int i = 1; i <= n; ++i) {
        rooms.insert(i);
    }

    int cur = 0;
    int ans = 0;
    std::vector<int> res(n, 0);

    for (int i = 0; i < events.size(); ++i) {
        if (events[i][1] == 0) { // start
            cur++;
            res[events[i][2]] = *rooms.begin();
            rooms.erase(res[events[i][2]]);
        } else { // end
            cur--;
            rooms.insert(res[events[i][2]]);
        }

        ans = std::max(ans, cur);
    }

    std::cout << ans << '\n';
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';
}