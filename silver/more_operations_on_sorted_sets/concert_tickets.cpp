#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <string>
#include <map>

// https://cses.fi/problemset/task/1091

int main() {
    int n, m; std::cin >> n >> m;
    std::map<int,int> fmap;

    for (int i = 0; i < n; ++i) {
        int val; std::cin >> val;
        fmap[-1 * val]++;
    }
    
    for (int i = 0; i < m; ++i) {
        int x; std::cin >> x;
        auto it = fmap.lower_bound(x * - 1);

        if (it == fmap.end()) {
            std::cout << "-1\n";
            continue;
        }

        std::cout << -1 * it->first << '\n';

        if (it->second == 1) {
            fmap.erase(it->first);
        } else {
            it->second--;
        }
    }

}
