#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; std::cin >> n >> k;
    std::vector<std::vector<int>> a(n, std::vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][0];
        a[i][1] = i;
    }

    std::sort(a.begin(), a.end());

    if (a[0][0] != 0) {
        std::cout << "-1\n";
        return 0;
    }

    std::vector<std::vector<int>> res;
    std::queue<std::vector<int>> q; q.push({a[0][0], a[0][1], 0}); // dist, id, degree

    int i = 1;
    while (i < a.size()) {
        if (q.size() == 0) {
            std::cout << "-1\n";
            return 0;
        }
        if (q.front()[2] == k) {
            q.pop();
        } else if (q.front()[0] + 1 != a[i][0]) {
            q.pop();
        } else {
            res.push_back({q.front()[1], a[i][1]});
            q.push({a[i][0], a[i][1], 1});
            q.front()[2]++;
            i++;
        }
    }

    std::cout << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i][0] + 1 << ' ' << res[i][1] + 1 << '\n';
    }
}