#include <iostream>

int64_t calc(int64_t a, int64_t b) {
    if (a == b) return 0;

    if (a > b) {
        return (1 + a % 2) + calc((a + a % 2) / 2, b);
    } else {
        return std::min(b - a, (1 + b % 2) + calc(a, b / 2));
    }
}

int main() {
    int n; std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int64_t a, b;
        std::cin >> a >> b;
        std::cout << calc(a, b) << '\n';
    }
}