#include <iostream>
#include <vector>
#include <map>

bool dfs(int pos, std::vector<std::vector<int>>& g, std::vector<int>& color, std::vector<int>& order) {
    color[pos] = 1;
    order.push_back(pos);
    for (int i = 0; i < g[pos].size(); ++i) {
        int v = g[pos][i];
        if (color[v] == 1) {
            // cycle;
            order.push_back(v);
            return true;
        }
        if (color[v] == 0 && dfs(v, g, color, order)) {
            return true;
        }
    }

    color[pos] = 2;
    return false;
}

bool dfs2(int pos, std::vector<std::vector<int>>& g, std::vector<int>& color, std::vector<int>& order) {
    color[pos] = 1;
    order.push_back(pos);

    for (int i = 0; i < g[pos].size(); ++i) {
        int v = g[pos][i];

        if (color[v] == 1) {
            order.push_back(v);
            return true;
        }

        if (color[v] == 0 && dfs2(v, g, color, order)) {
            return true;
        }
    }

    order.pop_back();
    color[pos] = 2;
    return false;
}


int main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    for (int i = 0; i < m; ++i) {
        int a, b; std::cin >> a >> b;
        g[a-1].push_back(b-1);
    }

    std::vector<int> color(n, 0); // 0 - not visited, 1 - in cycle, 2 - visited
    for (int i = 0; i < n; ++i) {
        std::vector<int> order;
        if (color[i] == 0 && dfs(i, g, color, order)) {
            // simplify order
            int start;
            std::map<int, int> fmap;
            for (int i = 0; i < order.size(); ++i) {
                if (fmap.find(order[i]) != fmap.end()) {
                    start = order[i];
                    break;
                }
                fmap[order[i]] = i;
            }

            order.clear();
            std::vector<int> color2(n, 0);
            dfs2(start, g, color2, order);

            std::cout << order.size() << '\n';
            for (int i = 0; i < order.size(); ++i) {
                std::cout << 1 + order[i] << ' ';
            }
            std::cout << '\n';
            return 0;
        }
    }
    
    std::cout << "IMPOSSIBLE\n";
}