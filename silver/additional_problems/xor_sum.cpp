#include <iostream>
#include <vector>

int main() {
    int n, q; std::cin >> n >> q;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] ^ a[i];
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        std::cout << (prefix[r] ^ prefix[l - 1]) << '\n';
    }
}