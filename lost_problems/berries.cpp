#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int cnt = 0;
    for (int i = 0; i < k / 2; ++i) {
        int need = k - i;
        for (int j = 0; j <= 1000; ++j) {
            for (int q = 0; q < a.size(); ++q) {

            }
        }

    }

}