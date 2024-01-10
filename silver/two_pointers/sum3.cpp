#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// https://cses.fi/problemset/task/1641

int main() {
    int n, x; std::cin >> n >> x;
    std::vector<std::vector<int>> a(n, std::vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][0];
        a[i][1] = i + 1;
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i) {
        int l = i + 1;
        int r = a.size() - 1;
        while (l < r) {
            if (a[i][0] + a[l][0] + a[r][0] == x) {
                std::cout << a[i][1] << ' ' << a[l][1] << ' ' << a[r][1] << '\n';
                return 0;
            } else if (a[i][0] + a[l][0] + a[r][0] > x) {
                r--;
            } else {
                l++;
            }
        }
    }

    std::cout << "IMPOSSIBLE\n";
}