#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>

// https://codeforces.com/gym/104002/problem/E

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> h;
    for (int i = 0; i < a.size(); i += 2) {
        h.push_back(a[i]);
        std::push_heap(h.begin(), h.end(), std::greater<int>());
        h.push_back(a[i+1]);
        std::push_heap(h.begin(), h.end(), std::greater<int>());

        while (h.size() > (i + 2) / 2) {
            std::pop_heap(h.begin(), h.end(), std::greater<int>());
            h.pop_back();
        }
    }

    long long res = 0;
    for (int i = 0; i < h.size(); ++i) {
        res += h[i];
    }

    std::cout << res << '\n';
}