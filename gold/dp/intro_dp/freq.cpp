#include <iostream>
#include <vector>
#include <map>
#include <set>

int main() {
    int n, c; std::cin >> n >> c;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int cnt = 0;
    int add = 0;
    std::map<int, int> fmap;

    for (int i = 0; i < n; ++i) {
        if (a[i] == c) {
            cnt++;
        } else {
            fmap[a[i]] = std::max(fmap[a[i]], cnt) + 1;
        }

        add = std::max(add, fmap[a[i]] - cnt);
    }

    std::cout << add + cnt << '\n';
}