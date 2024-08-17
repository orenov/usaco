#include <iostream>
#include <vector>

int dist(std::vector<int>& a, std::vector<int>& b) {
    return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}

int main() {
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);

    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(2, 0));
    std::vector<std::vector<int>> b(m + 1, std::vector<int>(2, 0));
    
    std::cin >> a[0][0] >> a[0][1] >> b[0][0] >> b[0][1];

    for (int i = 1; i <= n; ++i) {
        char c; std::cin >> c;
        if (c == 'N') {
            a[i][0] = a[i-1][0];
            a[i][1] = a[i-1][1] + 1;
        }
        if (c == 'S') {
            a[i][0] = a[i-1][0];
            a[i][1] = a[i-1][1] - 1;
        }
        if (c == 'E') {
            a[i][0] = a[i-1][0] + 1;
            a[i][1] = a[i-1][1];
        }
        if (c == 'W') {
            a[i][0] = a[i-1][0] - 1;
            a[i][1] = a[i-1][1];
        }
    }

    for (int i = 1; i <= m; ++i) {
        char c; std::cin >> c;
        if (c == 'N') {
            b[i][0] = b[i-1][0];
            b[i][1] = b[i-1][1] + 1;
        }
        if (c == 'S') {
            b[i][0] = b[i-1][0];
            b[i][1] = b[i-1][1] - 1;
        }
        if (c == 'E') {
            b[i][0] = b[i-1][0] + 1;
            b[i][1] = b[i-1][1];
        }
        if (c == 'W') {
            b[i][0] = b[i-1][0] - 1;
            b[i][1] = b[i-1][1];
        }
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 1e9));

    dp[0][0] = 0;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {

            if (i != n) {
                dp[i+1][j] = std::min(dp[i+1][j], dp[i][j] + dist(a[i+1], b[j]));
            }

            if (j != m) {
                dp[i][j+1] = std::min(dp[i][j+1], dp[i][j] + dist(a[i], b[j+1]));
            }

            if (i != n && j != m) {
                dp[i+1][j+1] = std::min(dp[i+1][j+1], dp[i][j] + dist(a[i+1], b[j+1]));
            }

        }
    }

    std::cout << dp.back().back() << '\n';
}