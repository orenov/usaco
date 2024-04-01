#include <iostream>
#include <vector>
#include <queue>
#include <set>

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }

    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            if (a[i][j] == a[i+1][j] && a[i][j] == a[i][j+1] && a[i][j] == a[i+1][j+1]) {
                q.push({i, j});
            }
        }
    }

    std::vector<std::vector<int>> res;
    while (q.size() > 0) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        //std::cout << x << ' ' << y << '\n';

        if (a[x][y] == -1) continue;

        std::set<int> col;
        if (a[x][y] > 0) col.insert(a[x][y]);
        if (a[x+1][y] > 0) col.insert(a[x+1][y]);
        if (a[x][y+1] > 0) col.insert(a[x][y+1]);
        if (a[x+1][y+1] > 0) col.insert(a[x+1][y+1]);

        if (col.size() == 0) continue;

        a[x][y] = -1;
        a[x+1][y] = 0;
        a[x][y+1] = 0;
        a[x+1][y+1] = 0;
        

        res.push_back({x, y, *col.begin()});
        // add new candidates;
        // (x-1, y-1), (x-1,y), (x-1,y+1);
        // (x, y-1), ^(x,y)^, (x, y+1)
        // (x+1,y-1), (x+1,y), (x+1,y+1)
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;
                int new_x = x + i;
                int new_y = y + j;

                if (new_x < 0 || new_x >= n - 1) continue;
                if (new_y < 0 || new_y >= m - 1) continue;

                std::set<int> s;
                if (a[new_x][new_y] > 0) s.insert(a[new_x][new_y]);
                if (a[new_x+1][new_y] > 0) s.insert(a[new_x+1][new_y]);
                if (a[new_x][new_y+1] > 0) s.insert(a[new_x][new_y+1]);
                if (a[new_x+1][new_y+1] > 0) s.insert(a[new_x+1][new_y+1]);
                
                //std::cout << "(" << new_x << ',' << new_y << ") - " << s.size() << '\n';

                if (s.size() == 1) {
                    q.push({new_x, new_y});
                }
            }
        }
    }

    // check
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > 0) {
                std::cout << "-1\n";
                return 0;
            }
        }
    }

    std::cout << res.size() << '\n';
    for (int i = res.size() - 1; i >= 0; --i) {
        std::cout << 1 + res[i][0] << ' ' << 1 + res[i][1] << ' ' << res[i][2] << '\n';
    }
}