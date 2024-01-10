#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>

// https://codeforces.com/problemset/problem/1000/C

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<long long>> a(2 * n, std::vector<long long>(2, 0));

    for (int i = 0; i < n; ++i) {
        std::cin >> a[2*i][0] >> a[2*i + 1][0];
        a[2*i + 1][0]++;

        a[2*i][1] = 1; // start
        a[2*i+1][1] = -1; // end
    }

    std::sort(a.begin(), a.end());
    
    std::vector<long long> res(n + 1, 0);
    int cur = 0;
    int i = 0;
    long long last = a[0][0];

    while (i < a.size()) {
        long long next = a[i][0];
        if (i != 0) res[cur] += next - last;

        while (i < a.size() && a[i][0] == next) {
            cur += a[i][1];
            ++i;
        }
        last = next;
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';
}