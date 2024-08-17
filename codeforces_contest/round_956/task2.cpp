#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void run(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b, int n, int m) {
    std::vector<int> debt(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != b[i][j] && (j == m - 1 || i == n - 1)) {
                std::cout << "NO\n";
                return;
            }
            if (a[i][j] != b[i][j]) {
                int d = (b[i][j] + 3 - a[i][j]) % 3;
                a[i][j+1] = (a[i][j+1] + 3 - d) % 3;
                a[i+1][j] = (a[i+1][j] + 3 - d) % 3;
                a[i+1][j+1] = (a[i+1][j+1] + d) % 3;
            }
        }
    }

    std::cout << "YES\n";
}


int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, m; std::cin >> n >> m;
        std::vector<std::vector<int>> a(n, std::vector<int>(m));
        std::vector<std::vector<int>> b(n, std::vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c; std::cin >> c;
                a[i][j] = c - '0';
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c; std::cin >> c;
                b[i][j] = c - '0';
            }
        }

        run(a, b, n, m);
    }
}