#include <iostream>
#include <vector>
#include <algorithm>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=835

int main() {
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end(), std::greater<int>());

    int cnt = 0;

    for (int i = 0; i < a.size(); ++i) {
        if (cnt <= a[i]) {
            cnt++;
        }
    }
    
    std::cout << cnt << '\n';
}