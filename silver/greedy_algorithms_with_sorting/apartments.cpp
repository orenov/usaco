#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <string>
#include <map>

// https://cses.fi/problemset/task/1084

int main() {
    int n, m, k; std::cin >> n >> m >> k;
    std::vector<int> a(n, 0);
    std::vector<int> b(m, 0);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    
    int cnt = 0;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size()) {
        if (std::abs(a[i] - b[j]) <= k) {
            i++;
            j++;
            cnt++;
        } else if (a[i] - k > b[j]) {
            j++;
        } else {
            i++;
        }
    }

    std::cout << cnt << '\n';
}
