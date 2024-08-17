#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::map<int, int> fmap;
        for (int i = 0; i < n; ++i) {
            int tmp; std::cin >> tmp;
            fmap[tmp]++;
        }

        int r = 0;
        for (auto it = fmap.begin(); it != fmap.end(); ++it) {
            r += it->second / 3;
        }

        std::cout << r << '\n';
    }
}