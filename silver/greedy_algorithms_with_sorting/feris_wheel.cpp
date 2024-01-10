#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <string>
#include <map>

// https://cses.fi/problemset/task/1090

int main() {
    int n, x; std::cin >> n >> x;
    std::vector<int> a(n, 0);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    int cnt = 0;
    std::sort(a.begin(), a.end());
    int l = 0;
    int r = a.size() - 1;
    while (l <= r) {
        if (a[l] + a[r] <= x) {
            cnt++;
            l++;
            r--;
        } else {
            cnt++;
            r--;
        }
    }

    std::cout << cnt << '\n';
}
