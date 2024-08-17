#include <vector>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> s;
    std::vector<int> res(n, 0);

    for (int i = 0; i < n; ++i) {
        while (s.size() > 0 && a[s.back()] >= a[i]) s.pop_back();

        if (s.size() != 0) {
            res[i] = s.back() + 1;
        }

        s.push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';

}