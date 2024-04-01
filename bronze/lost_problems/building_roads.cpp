#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <string>
#include <set>

void dfs(int pos, std::vector<std::vector<int>>& g, std::vector<int>& cc, int id) {
    if (cc[pos] != -1) return;

    cc[pos] = id;
    for (int i = 0; i < g[pos].size(); ++i) {
        dfs(g[pos][i], g, cc, id);
    }
}

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> g(n, std::vector<int>());

    for (int i = 0; i < m; ++i) {
        int from, to;
        std::cin >> from >> to;
        from--; to--;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    std::vector<int> cc(n, -1);
    int id = 0;
    for (int i = 0; i < n; ++i) {
        if (cc[i] == -1) {
            dfs(i, g, cc, id);
            id++;
        }
    }

    std::cout << id - 1 << '\n';
    std::set<int> add;
    add.insert(cc[0]);

    for (int i = 0; i < n; ++i) {
        if (add.find(cc[i]) == add.end()) {
            std::cout << 1 << ' ' << i + 1 << '\n';
            add.insert(cc[i]);
        }
    }
}
