#include <iostream>
#include <vector>

bool fun(std::vector<int>& a, int x) {
    std::vector<int> rest;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] <= x) continue;
        if (a[i] >= a.size() - x + 1) continue;
        if (rest.size() == 0 || rest.back() < a[i]) {
            rest.push_back(a[i]);
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    int T; std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int n; std::cin >> n;
        std::vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        int l = -1;
        int r = n/2;
        // (l, r] invariant
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (fun(a, m)) {
                r = m;
            } else {
                l = m;
            }
        }

        std::cout << r << '\n';
    }
}