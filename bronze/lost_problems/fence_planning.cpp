#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n, m; std::cin >> n >> m;
    
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    for (int i = 0; i < q; ++i) {
        int l, r; std::cin >> l >> r;
        std::cout << upper(a, r) - upper(a, l - 1) << '\n';
   }
}