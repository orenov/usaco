#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <string>
#include <set>

// https://cses.fi/problemset/task/1073

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n, 0);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::multiset<int> fset;
    for (int i = 0; i < a.size(); ++i) {
        auto it = fset.upper_bound(a[i]);
        if (it != fset.end()) {
            fset.erase(it);
        }
        fset.insert(a[i]);
    }

    std::cout << fset.size() << '\n';
}
