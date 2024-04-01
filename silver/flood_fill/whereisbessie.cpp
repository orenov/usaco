#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>


// UNFINISHED

void floodfill(int r, int c, char ch, std::vector<std::string>>& g, int& x, int& y) {
    if (r >= g.size()) return;
    if (c >= g.size()) return;
    if (g[r][c] != ch) return;

    x = std::max(x, r);
    y = std::max(y, c);

    floodfill(r + 1, c, ch, g, x, y);
    floodfill(r, c + 1, ch, g, x, y);
}

int main() {
    // freopen("where.in", "r", stdin);
    // freopen("where.out", "w", stdout); 
    int n; std::cin >> n;
    std::vector<std::string>> g(n, "");
    for (int i = 0; i < n; ++i) {
        std::cin >> g[i];
    }
    std::vector<std::vector<int>> lastx(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> lasty(n, std::vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            floodfill(i, j, g[i][j], g, lastx[i][j], lasty[i][j]);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            for (int )


        }
    }

    std::cout << cnt << '\n';
}