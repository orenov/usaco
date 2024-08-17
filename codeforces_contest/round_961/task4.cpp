#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

bool check(std::vector<std::vector<long long>>& p) {
    long long cur = 1;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i][0] == 1 && cur > 1) return true;
        cur = std::max(cur, p[i][0]);
    }
    return false;
}

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<std::vector<long long>> p(n, std::vector<long long>(2, 0));
        for (int i = 0; i < n; ++i) {
            std::cin >> p[i][0];
        }

        if (check(p)) {
            std::cout << "-1\n";
            continue;
        }

        int cnt = 0;
        for (int i = 1; i < p.size(); ++i) {
            if (p[i-1][0] == 1) continue;
            std::vector<long long>& prev = p[i-1];
            std::vector<long long>& cur = p[i];
            if (prev[0] == cur[0] && prev[1] == cur[1]) continue;

            double log_value = log2f((long double) prev[0]) / log2f((long double) cur[0]);
            int 
            long long r = std::max(0LL, (long long) std::ceil(prev[1] + log2f(log_value)));
            
            cur[1] = r;
            cnt += r;
        }

        std::cout << cnt << '\n';

    }
}