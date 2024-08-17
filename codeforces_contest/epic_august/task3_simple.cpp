#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<std::vector<long long>> a(n, std::vector<long long>(2, 0));

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i][0] >> a[i][1];
        }

        std::vector<long long> source(2);
        std::vector<long long> target(2);
        std::cin >> source[0] >> source[1] >> target[0] >> target[1];

        long long d = (source[0] - target[0]) * (source[0] - target[0]) + (source[1] - target[1]) * (source[1] - target[1]);

        bool f = true;
        for (int i = 0; i < n; ++i) {
            long long tmp =(a[i][0] - target[0]) * (a[i][0] - target[0]) + (a[i][1] - target[1]) * (a[i][1] - target[1]);
            //std::cout << d << ' ' << tmp << '\n';
            if (tmp <= d) {
               f = false;
            }
        }

        if (f) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }

    }
}