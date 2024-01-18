#include <iostream>
#include <vector>
#include <set>

int main() {
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    int N = 2001;
    std::vector<std::vector<bool>> g(N, std::vector<bool>(N, false));

    int n; std::cin >> n;
    int r = N/2;
    int c = N/2;
    for (int i = 0; i < n; ++i) {
        char way; std::cin >> way;
        if (way == 'N') {
            g[r][c] = true;
            g[r][c+1] = true;
            g[r][c+2] = true;
            c += 2;
        } else if (way == 'S') {
            g[r][c] = true;
            g[r][c-1] = true;
            g[r][c+2] = true;
            c -= 2;
        } else if (way == 'E') {
            g[r][c] = true;
            g[r+1][c] = true;
            g[r+2][c] = true;
            r += 2;
        } else if (way == 'W') {
            g[r][c] = true;
            g[r-1][c] = true;
            g[r-2][c] = true;
            r -= 2;
        }
    }

    std::vector<std::vector<bool>> visited(N, std::vector<bool>(N, false));
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j] && !g[i][j]) {
                std::vector<std::pair<int, int>> stack;
                stack.push_back({i, j});
                cnt++;

                while (stack.size() > 0) {
                    std::pair<int, int> cur = stack.back(); stack.pop_back();
                    int r = cur.first;
                    int c = cur.second;
                    
                    if (r < 0 || r >= N) continue;
                    if (c < 0 || c >= N) continue;
                    if (visited[r][c]) continue;
                    if (g[r][c]) continue;
                    visited[r][c] = true;

                    stack.push_back({r + 1, c});
                    stack.push_back({r - 1, c});
                    stack.push_back({r, c + 1});
                    stack.push_back({r, c - 1});
                }
            }
        }
    }

    std::cout << cnt - 1 << '\n';
}