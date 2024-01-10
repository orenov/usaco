#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>

// https://codeforces.com/gym/102951/problem/B

int main() {
    int n, x; std::cin >> n >> x;
    std::vector<int> a(n, 0);
    for (int i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (x >= a[i]) {
            cnt++;
            x -= a[i];
        } else {
            break;
        }
    }

    std::cout << cnt << '\n';
}