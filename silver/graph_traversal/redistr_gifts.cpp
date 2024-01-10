#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

// http://usaco.org/index.php?page=viewproblem2&cpid=1206

void dfs(int pos, std::vector<std::vector<int>>& g, std::vector<bool>& visited) {
    visited[pos] = true;
    for (int i = 0; i < g[pos].size(); ++i) {
        if (!visited[g[pos][i]]) {
            dfs(g[pos][i], g, visited);
        }
    }
}

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> prio(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> g(n, std::vector<int>());
    std::vector<std::vector<int>> g_rev(n, std::vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> prio[i][j];
            prio[i][j]--;
        }

        for (int j = 0; j < n; ++j) {
            if (prio[i][j] == i) break;
            g[i].push_back(prio[i][j]);
            g_rev[prio[i][j]].push_back(i);
        }
    }

    std::vector<int> res(n, -1);

    for (int i = 0; i < n; ++i) {
        std::vector<bool> visited1(n, false);
        std::vector<bool> visited2(n, false);
        dfs(i, g,     visited1);
        dfs(i, g_rev, visited2);
        std::set<int> good;
        //std::cout << i << '\n';
        for (int j = 0; j < n; ++j) {
            //std::cout << '(' << visited1[j] << ',' << visited2[j] << ") ";
            if (visited1[j]  && visited2[j]) {
                good.insert(j);
            }
        }
        //std::cout << '\n';

        for (int j = 0; j < n; ++j) {
            if (good.find(prio[i][j]) != good.end()) {
                res[i] = prio[i][j];
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << res[i] + 1 << '\n';
    }
}