#include <iostream>
#include <vector>
#include <algorithm>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=669

void dfs(int pos, std::vector<std::vector<int>>& g, std::vector<int>& visited) {
    if (visited[pos]) return;
    visited[pos] = true;

    for (int i = 0; i < g[pos].size(); ++i) {
        dfs(g[pos][i], g, visited);
    }
}

bool run(std::vector<std::vector<int>>& data, int d) {
    std::vector<std::vector<int>> g(data.size(), std::vector<int>());

    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data.size(); ++j) {
            if (i == j) continue;
            int x = data[i][0] - data[j][0];
            int y = data[i][1] - data[j][1];
            if (x * x + y * y <= d) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    std::vector<int> visited(data.size(), false);
    dfs(0, g, visited);
    for (int i = 0; i < visited.size(); ++i) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n; std::cin >> n;
    std::vector<std::vector<int>> data(n, std::vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i][0] >> data[i][1];
    }

    int l = -1;
    int r = 25000 * 25000;
    // (l, r] invariant
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (run(data, m)) {
            r = m;
        } else {
            l = m;
        }
    }

    std::cout << r << '\n';
}