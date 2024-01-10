#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <string>
#include <map>

// https://cses.fi/problemset/task/1630

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(2, 0));

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][0] >> a[i][1];
    }
    std::sort(a.begin(), a.end());

    long long score = 0;
    long long time = 0;
    for (int i = 0; i < a.size(); ++i) {
        score += a[i][1] - (time + a[i][0]);
        time += a[i][0];
    }

    std::cout << score << '\n';
}
