#include <iostream>
#include <vector>
#include <string>

void floodfill(int r, int c, std::vector<std::string>& g, std::vector<std::vector<bool>>& visited, int& area, int& perimeter) {
    if (r < 0 || r >= g.size()) {perimeter++; return;}
    if (c < 0 || c >= g.size()) {perimeter++; return;}
    if (g[r][c] == '.') {perimeter++; return;}
    if (visited[r][c]) return;
    visited[r][c] = true;
    area++;

    floodfill(r + 1, c, g, visited, area, perimeter);
    floodfill(r - 1, c, g, visited, area, perimeter);
    floodfill(r, c + 1, g, visited, area, perimeter);
    floodfill(r, c - 1, g, visited, area, perimeter);
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    int n; std::cin >> n;
    std::vector<std::string> g(n, "");
    for (int i = 0; i < n; ++i) {
        std::cin >> g[i];
    }
    int area = 0;
    int perimeter = 0;

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j]) {
                int tmp_area = 0;
                int tmp_perimeter = 0;
                floodfill(i, j, g, visited, tmp_area, tmp_perimeter);
                if (tmp_area > area || (tmp_area == area && tmp_perimeter < perimeter)) {
                    area = tmp_area;
                    perimeter = tmp_perimeter;
                }
            }
        }
    }

    std::cout << area << ' ' << perimeter << '\n';
}