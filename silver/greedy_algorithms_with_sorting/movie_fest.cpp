#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

// https://cses.fi/problemset/task/1629

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(2, 0));

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][1] >> a[i][0];
    }

    int cnt = 0;
    int last = -1;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i) {
        if (a[i][1] >= last) {
            cnt++;
            last = a[i][0];
        }
    }

    std::cout << cnt << '\n';
}