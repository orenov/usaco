#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=859

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n; std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(3, 0));
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }

    std::sort(a.begin(), a.end());

    std::vector<std::vector<int>> arrived;

    //std::cout << "===\n";
    int res = 0;
    int cur_time = a[0][0];
    int i = 0;
    while (i < a.size() || arrived.size() > 0) {
        while (i < a.size() && (a[i][0] <= cur_time || arrived.size() == 0)) {
            arrived.push_back({-1 * a[i][2], a[i][0], a[i][1]}); // seniority, arrive time, need
            std::push_heap(arrived.begin(), arrived.end());
            ++i;
        }
        //std::cout << arrived.size() << '\n';
        int time = arrived[0][1];
        int need = arrived[0][2];

        std::pop_heap(arrived.begin(), arrived.end());
        arrived.pop_back();

        //std::cout << cur_time << ' ' << time << ' ' << need << '\n';

        if (time >= cur_time) {
            cur_time = time;
        } else {
            res = std::max(res, cur_time - time);
        }

        cur_time += need;
    }

    std::cout << res << '\n';
}