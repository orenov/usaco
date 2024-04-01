#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

bool fun(std::vector<std::vector<int>>& a, int x, std::pair<int, int>& res) {
    std::vector<int> b(a.size(), 0);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            if (a[i][j] >= x) {
                b[i] |= 1 << j;
            }
        }
    }

    std::map<int, std::vector<int>> fmap;
    for (int i = 0; i < b.size(); ++i) {
        fmap[b[i]].push_back(i);
    }

    for (int mask1 = 0; mask1 < (1 << a[0].size()); ++mask1) {
        for (int mask2 = 0; mask2 < (1 << a[0].size()); ++mask2) {
            if ((mask1 | mask2) == ((1 << a[0].size()) - 1) && fmap[mask1].size() > 0 && fmap[mask2].size() > 0) {
                res = {fmap[mask1][0], fmap[mask2][0]};
                return true;
            }
        }    
    }

    return false;
}

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }

    int l = 0;
    int r = 1e9 + 1;
    std::pair<int, int> res;

    // [l, r) invariant
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (fun(a, m, res)) {
            l = m;
        } else {
            r = m;
        }
    }

    fun(a, l, res);
    std::cout << res.first + 1 << ' ' << res.second + 1 << '\n';
}