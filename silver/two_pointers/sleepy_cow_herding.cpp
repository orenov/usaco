#include <iostream>
#include <vector>
#include <algorithm>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=918

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int rmin = n;
    int rmax = std::max(a[a.size() - 1] - a[1] - n + 2, a[a.size() - 2] - a[0] - n + 2);
    
    int l = 0; // next to move
    int r = 0; // next to add

    while (r < a.size()) {
        while (r < a.size() && a[r] - a[l] < n) r++;
        if (r - l == n - 1 && a[r - 1] - a[l] + 1 == n - 1){            
        } else {
            rmin = std::min(rmin, n - (r - l));
        }

        l++;
    }

    std::cout << rmin << '\n';
    std::cout << rmax << '\n';
}