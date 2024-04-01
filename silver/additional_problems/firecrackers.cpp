#include <iostream>
#include <vector>
#include <algorithm>

bool fun(std::vector<int>& v, int x, int corridor_len, int hooligan_position, int guard_position) {
    // move to one direction -> 0
    if (guard_position < hooligan_position) {
        guard_position = corridor_len - guard_position + 1;
        hooligan_position = corridor_len - hooligan_position + 1;
    }

    // can we fire up x
    if (guard_position - hooligan_position <= x) {
        return false;
    }

    //std::cout << "=====\n";
    std::vector<int> explode_time;
    for (int i = x - 1; i >= 0; --i) {
        explode_time.push_back(v[i] + 1 + (x - 1 - i));
    }
    
    //std::cout << x << '\n';
    //for (int i = 0; i < explode_time.size(); ++i) {
    //    std::cout << explode_time[i] << ' ';
    //}
    //std::cout << '\n';

    int time_catch = guard_position - 1;

    for (int i = 0; i < explode_time.size(); ++i) {
        if (explode_time[i] > time_catch) return false;
    }

    return true;
}

int main() {
    int T; std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int corridor_len, m, hooligan_position, guard_position;
        std::cin >> corridor_len >> m >> hooligan_position >> guard_position;
        
        std::vector<int> v(m, 0);
        for (int i = 0; i < m; ++i) {
            std::cin >> v[i];
        }

        std::sort(v.begin(), v.end());

        int l = 0;
        int r = m + 1;
        // [l, r) - invariant

        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (fun(v, m, corridor_len, hooligan_position, guard_position)) {
                l = m;
            } else {
                r = m;
            }
        }

        std::cout << l << '\n';
    }
}