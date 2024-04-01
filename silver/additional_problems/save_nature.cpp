#include <vector>
#include <iostream>
#include <algorithm>

int64_t gcd(int64_t a, int64_t b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int64_t fun(std::vector<int64_t>& p, int64_t x, int64_t a, int64_t y, int64_t b, int64_t len) {
    int64_t money = 0;

    int64_t c = a * b / gcd(a, b);
    int64_t z = x + y;

    int64_t cnt_z = len / c;
    int64_t cnt_x = (len / a) - cnt_z;
    int64_t cnt_y = (len / b) - cnt_z;

    if (x < y) {
        std::swap(a, b);
        std::swap(x, y);
        std::swap(cnt_x, cnt_y);
    }

    // a > b
    for (int i = 0; i < cnt_z; ++i) money += p[i] * (x + y) / 100;
    for (int i = cnt_z; i < cnt_z + cnt_x; ++i) money += p[i] * x / 100;
    for (int i = cnt_z + cnt_x; i < cnt_z + cnt_x + cnt_y; ++i) money += p[i] * y / 100;
    
    return money;
}


int main() {
    int q; std::cin >> q;
    for (int qq = 0; qq < q; ++qq) {
        int n; std::cin >> n;
        std::vector<int64_t> p(n, 0);
        for (int i = 0; i < n; ++i) {
            std::cin >> p[i];
        }
        std::sort(p.begin(), p.end(), std::greater<int64_t>());
        int64_t x, a, y, b;
        std::cin >> x >> a >> y >> b;
        int64_t k; std::cin >> k;
        
        int64_t l = 0;
        int64_t r = n + 1;
        // (l, r] invariant

        while (l + 1 < r) {
            int64_t m = (l + r) / 2;
            if (fun(p, x, a, y, b, m) >= k) {
                r = m;
            } else {
                l = m;
            }
        }

        if (r == n + 1) r = -1;
        std::cout << r << '\n';
    }
}