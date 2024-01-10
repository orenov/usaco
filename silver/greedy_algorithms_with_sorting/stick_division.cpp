#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// https://cses.fi/problemset/task/1161

int main() {
    int x, n; std::cin >> x >> n;
    std::vector<long long> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::make_heap(a.begin(), a.end(), std::greater<long long>());
    long long res = 0;

    while (a.size() > 1) {
        long long v1 = a[0];
        std::pop_heap(a.begin(), a.end(), std::greater<long long>()); a.pop_back();
        long long v2 = a[0];
        std::pop_heap(a.begin(), a.end(), std::greater<long long>()); a.pop_back();
        res += (v1 + v2);
        //std::cout << v1 << ' ' << v2 << '\n';
        
        a.push_back(v1 + v2);
        std::push_heap(a.begin(), a.end(), std::greater<long long>());
    }

    std::cout << res << '\n';
}