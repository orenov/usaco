#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=813

struct Boot {
    int max_depth, max_step, index;
};

struct Snow {
    int depth, index;
};

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    int n, b; std::cin >> n >> b;
    std::vector<Snow> snow(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> snow[i].depth;
        snow[i].index = i;
    }
    std::vector<Boot> boots(b);
    for (int i = 0; i < b; ++i) {
        std::cin >> boots[i].max_depth >> boots[i].max_step;
        boots[i].index = i;
    }

    std::sort(boots.begin(), boots.end(), [](const Boot& a, const Boot& b) {
        return a.max_depth > b.max_depth;
    });

    std::sort(snow.begin(), snow.end(), [](const Snow& a, const Snow& b) {
        return a.depth > b.depth;
    });

    std::set<int> fset;
    for (int i = 0; i < n; ++i) fset.insert(i);

    int max_segment = 0;

    int j = 0;
    std::vector<int> res(b, 0);
    for (int i = 0; i < b; ++i) {
        while (j < snow.size() && snow[j].depth > boots[i].max_depth) {
            int val = snow[j].index;
            auto it = fset.find(val);
            max_segment = std::max(max_segment, *next(it) - *prev(it));
            fset.erase(val);
            j++;
        }

        if (boots[i].max_step >= max_segment) {
            res[boots[i].index] = 1;
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << '\n';
    }
}