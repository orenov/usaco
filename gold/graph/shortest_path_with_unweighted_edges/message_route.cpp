#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m; std::cin >> n >> m;
    int source = 0;
    int target = n - 1;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    for (int i = 0; i < m; ++i) {
        int a, b; std::cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    std::vector<int> from(n, -1);
    from[source] = source;
    std::queue<int> q; q.push(source);

    while (q.size() > 0) {
        int node = q.front(); q.pop();
            
        for (int j = 0; j < g[node].size(); ++j) {
            if (from[g[node][j]] == -1) {
                from[g[node][j]] = node;
                q.push(g[node][j]);
            }
        }
    }

    if (from[target] == -1) {
        std::cout << "IMPOSSIBLE\n";
        return 0;
    }

    std::vector<int> path;
    path.push_back(target);

    while (path.back() != from[path.back()]) {
        path.push_back(from[path.back()]);
    }

    std::cout << path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; --i) {
        std::cout << path[i] + 1 << ' ';
    }
    std::cout << '\n';
}