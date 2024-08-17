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

        std::map<int, int> fmap;

        for (int i = 0; i < n; ++i) {
            fmap[a[i]]++;
        }
        bool f = false;
        for (auto it = fmap.begin();  it != fmap.end(); ++it) {
            if (it->second % 2 == 1) {
                f = true;
            }
        }

        if (f) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}