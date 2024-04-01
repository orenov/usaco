#include <iostream>
#include <vector>

void dfs1(int pos, int parent, 
        std::vector<std::vector<int>>& g,
        std::vector<int>& max1, 
        std::vector<int>& max2, 
        std::vector<int>& max1_id) 
{
    for (int i = 0; i < g[pos].size(); ++i) {
        if (g[pos][i] == parent) continue;
        dfs1(g[pos][i], pos, g, max1, max2, max1_id);
        int cur = 1 + max1[g[pos][i]];
        if (cur > max1[pos]) {
            max2[pos] = max1[pos];
            max1[pos] = cur;
            max1_id[pos] = g[pos][i];
        } else if (cur > max2[pos]) {
            max2[pos] = cur;
        }
    }
}

void dfs2(int pos, int parent, std::vector<std::vector<int>>& g,
         std::vector<int>& max1, std::vector<int>& max2, 
         std::vector<int>& max1_id) {
    for (int i = 0; i < g[pos].size(); ++i) {
        if (g[pos][i] == parent) continue;
        if (max1_id[pos] == g[pos][i]) {
            if (max2[pos] + 1 > max1[g[pos][i]]) {
                max2[g[pos][i]] = max1[g[pos][i]];
                max1[g[pos][i]] = max2[pos] + 1;
                max1_id[g[pos][i]] = pos;
            }
            if (max2[pos] + 1 > max2[g[pos][i]]) {
                max2[g[pos][i]] = max2[pos] + 1;
            }            
        } else {
            max2[g[pos][i]] = max1[g[pos][i]];
            max1[g[pos][i]] = max1[pos] + 1;
            max1_id[g[pos][i]] = pos;
        }
        
        dfs2(g[pos][i], pos, g, max1, max2, max1_id);
    }
}

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v; std::cin >> u >> v; --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::vector<int> max1(n, 0);
    std::vector<int> max2(n, 0);
    std::vector<int> max3(n, 0);
    std::vector<int> max1_id(n, -1);
    std::vector<int> up(n, -1);
    dfs1(0, -1, g, max1, max2, max1_id);
    up[0] = 0;
    dfs2(0, -1, g, max1, max2, max1_id);

    for (int i = 0; i < n; ++i) {
        std::cout << max1[i] << ' ';
    }
    std::cout << '\n';
}