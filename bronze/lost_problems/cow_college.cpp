#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n; std::cin >> n;
    std::vector<long long> a(n, 0LL);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    long long res = 0;
    long long price = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (res < a[i] * (a.size() - i)) {
            res = a[i] * (a.size() - i);
            price = a[i];
        }
    }

    std::cout << res << ' ' << price << '\n';
}