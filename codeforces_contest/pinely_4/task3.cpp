#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::vector<int> res;
        for (int l = 1; l <= 41; ++l) {
            int mmax = 0;
            int mmin = 1e9 + 1;

            for (int i = 0; i < n; ++i) {
                mmax = std::max(mmax, a[i]);
                mmin = std::min(mmin, a[i]);
            }

            int d = (mmax + mmin) / 2;
            
            if (mmax + mmin == 0) break;

            for (int i = 0; i < n; ++i) {
                a[i] = std::abs(a[i] - d);
            }
            //std::cout << d << '\n';
            res.push_back(d);
        }

        if (res.size() < 41) {
            std::cout << res.size() << '\n';
            for (int i = 0; i < res.size(); ++i) {
                std::cout << res[i] << ' ';
            }
            std::cout << '\n';
        } else {
            std::cout << "-1\n";
        }
    }
}