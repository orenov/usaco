#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, k; std::cin >> n >> k;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end());
        // [l, r] invariant
        long long l = a.back();
        long long r = a.back() + k - 1;
        //std::cout << "int: " << l << ' ' << r << '\n';

        for (int i = 0; i < n - 1; ++i) {
            int d = std::ceil((a.back() - a[i]) / (2.0 * k));
            // big interval
            long long new_r1, new_l1, new_r2, new_l2;
            {
                long long ll = a[i] + 2 * k * d;
                long long rr = a[i] + 2 * k * d + k - 1;
                new_r1 = std::min(r, rr);
                new_l1 = std::max(l, ll);
            }
            // small interval
            {
                long long ll = a[i] + 2 * k * (d - 1);
                long long rr = a[i] + 2 * k * (d - 1) + k - 1;
                new_r2 = std::min(r, rr);
                new_l2 = std::max(l, ll); 
            }

            if (new_l1 <= new_r1) {
                r = new_r1;
                l = new_l1;
            } else {
                r = new_r2;
                l = new_l2;
            }
            //std::cout << a[i] << " - [" << ll << ", " << rr << "]\n";
            //std::cout << "int: " << l << ' ' << r << '\n';
        }

        if (r >= l) {
            std::cout << l << '\n';
        } else {
            std::cout << -1 << '\n';
        }
    }
}