#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=989

long long solve(long long k, long long x) { // dist, max_speed
    long long max_speed = 1;
    long long r = k;
    while (true) {
        long long sec = 0;
        long long left = k;

        // up
        left -= max_speed * (max_speed + 1) / 2;
        sec += max_speed;

        // down
        sec += std::max(0LL, max_speed - x);
        left -= std::max(0LL, max_speed * (max_speed - 1) / 2 - (x - 1) * x / 2);

        if (left < 0) {
            break;
        };
        
        r = std::min(r, sec + static_cast<long long>(ceil(1.0 * left / max_speed)));
        max_speed++;
    }
    return r;
}

int main() {
    freopen("race.in", "r", stdin);
    long long n, k; std::cin >> k >> n;
    freopen("race.out", "w", stdout);
    for (int i = 0; i < n; ++i) {
        long long x; std::cin >> x;
        std::cout << solve(k, x) << '\n';
    }
}