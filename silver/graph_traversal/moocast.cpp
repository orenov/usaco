#include <iostream>
#include <vector>
#include <algorithm>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=668

void dfs(int pos, std::vector<std::vector<int>>& g, std::vector<int>& visited, int& cnt) {
    if (visited[pos]) return;
    cnt++;
    visited[pos] = true;

    for (int i = 0; i < g[pos].size(); ++i) {
        dfs(g[pos][i], g, visited, cnt);
    }
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    std::vector<std::vector<int>> data(n, std::vector<int>(3, 0));
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i][0] >> data[i][1] >> data[i][2];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int dsq = (data[i][0] - data[j][0]) * (data[i][0] - data[j][0]) + (data[i][1] - data[j][1]) * (data[i][1] - data[j][1]);
            if (dsq <= data[i][2] * data[i][2]) {
                g[i].push_back(j);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        std::vector<int> visited(n, false);
        dfs(i, g, visited, cnt);
        ans = std::max(ans, cnt);
    }

    std::cout << ans << '\n';
}