#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::string> g(n, "");
    for (int i = 0; i < n; ++i) {
        std::cin >> g[i];
    }

    std::vector<int> source;
    std::vector<int> target;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'A') {
                source = {i, j};
            }
            if (g[i][j] == 'B') {
                target = {i, j};
            }
        }
    }

    std::vector<std::vector<int>> moves{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // L D R U
    std::string from = "RDLU";
    std::map<char, std::vector<int>> fmap;
    fmap['R'] = {0, 1};
    fmap['D'] = {1, 0};
    fmap['L'] = {0, -1};
    fmap['U'] = {-1, 0};

    std::queue<std::vector<int>> q; q.push(source);

    while (q.size() > 0) {
        std::vector<int> node = q.front(); q.pop();

        for (int k = 0; k < moves.size(); ++k) {
            int new_x = node[0] + moves[k][0];
            int new_y = node[1] + moves[k][1];

            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && (g[new_x][new_y] == '.' || g[new_x][new_y] == 'B')) {
                g[new_x][new_y] = from[k];
                q.push({new_x, new_y});
            }
        }
    }
    
    if (g[target[0]][target[1]] == 'B') {
        std::cout << "NO\n";
        return 0;
    }

    std::string path = "";

    while (g[target[0]][target[1]] != 'A') {
        path.push_back(g[target[0]][target[1]]);
        int new_x = target[0] - fmap[g[target[0]][target[1]]][0];
        int new_y = target[1] - fmap[g[target[0]][target[1]]][1];
        target = {new_x, new_y};
    }
    for (int i = 0; i < path.size() / 2; ++i) {
        std::swap(path[i], path[path.size() - i - 1]);
    }

    std::cout << "YES\n";
    std::cout << path.size() << '\n';
    std::cout << path << '\n';

}