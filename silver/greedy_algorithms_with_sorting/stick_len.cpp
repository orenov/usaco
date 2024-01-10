#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// https://cses.fi/problemset/task/1074

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    long long m = a[a.size() / 2];

    long long d = 0;
    for (int i = 0; i < a.size(); ++i) {
        d += std::abs(a[i] - m);
    }

    std::cout << d << '\n';
}