#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

bool is_prime(int x) {
    if (x == 1 || x == 2) return true;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T; std::cin >> T;
    std::vector<int> r{1,2,2,3,3,4};

    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        
        if (n <= r.size()) {
            int mmax = 0;
            for (int i = 0; i < n; ++i) {
                mmax = std::max(mmax, r[i]);
            }
            std::cout << mmax << '\n';
            for (int i = 0; i < n; ++i) {
                std::cout << r[i] << ' ';
            }
            std::cout << '\n';
        } else {
            std::cout << "4\n";
            for (int i = 0; i < n; ++i) {
                std::cout << 1 + (i % 4) << ' ';
            }
            std::cout << '\n';
        }


    }
}