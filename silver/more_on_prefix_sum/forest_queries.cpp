#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <string>

// https://cses.fi/problemset/task/1652

int main() {
    int n, q; std::cin >> n >> q;
    std::vector<std::string> a(n, "");
    std::vector<std::vector<int>> b(n + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int val = a[i-1][j-1] == '*' ? 1 : 0;
            b[i][j] = val + b[i-1][j] + b[i][j-1] - b[i-1][j-1];
        }
    }

    for (int i = 0; i < q; ++i) {
        int y1, x1, y2, x2; 
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << b[x2][y2] - b[x2][y1-1] - b[x1-1][y2] + b[x1-1][y1-1] << '\n';
    }
}
