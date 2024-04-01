#include <iostream>
#include <vector>

int main() {
    int T; std::cin >> T;
    for (int qq = 0; qq < T; ++qq) {
        int n, q; std::cin >> n >> q;
        std::vector<std::vector<int64_t>> a(1001, std::vector<int64_t>(1001, 0));
        for (int i = 0; i < n; ++i) {
            int h, w; std::cin >> h >> w;
            a[h][w] += h * w;
        }

        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a.size(); ++j) {
                if (i != 0) a[i][j] += a[i-1][j];
                if (j != 0) a[i][j] += a[i][j-1];
                if (i != 0 && j != 0) a[i][j] -= a[i-1][j-1];
            }
        }

        for (int i = 0; i < q; ++i) {
            int h1, w1, h2, w2; 
            std::cin >> h1 >> w1 >> h2 >> w2;

            std::cout << a[h2-1][w2-1] - a[h2-1][w1] - a[h1][w2-1] + a[h1][w1] << '\n';
        }
    }
}