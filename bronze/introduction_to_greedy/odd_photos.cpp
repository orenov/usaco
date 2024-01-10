#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=1084

int main() {
    int n; std::cin >> n;
    int odd = 0;
    int even = 0;
    for (int i = 0; i < n; ++i) {
        int val; std::cin >> val;
        if (val % 2 == 1) {
            odd++;
        } else {
            even++;
        }
    }

    int cnt = 0;

    while (odd != 0 || even != 0) {
        // even
        if (even > 0) {
            even--; 
            cnt++;
        } else if (odd >= 2) {
            odd -= 2; 
            cnt++;
        } else if (odd == 1) {
            cnt -= 1;
            odd -= 1;
        } else {
            break;
        }

        // odd
        if (odd > 0) {
            odd--;
            cnt++;
        } else if (even > 0) {
            even = 0;
        } else {
            break;
        }
    }

    std::cout << std::max(0, cnt) << '\n';
}