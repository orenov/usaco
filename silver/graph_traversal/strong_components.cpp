#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>
#include <set>

// https://codeforces.com/problemset/problem/920/E

void dfs(int pos, std::vector<std::set<int>>& g, std::set<int>& unreachable, std::vector<bool>& visited) {
    visited[pos] = true;
    std::vector<int> vals; // vector of unreachable nodes

    auto it1 = g[pos].begin();
    auto it2 = unreachable.begin();

    while (it1 != g[pos].end() && it2 != unreachable.end()) {
        //std::cout << "=== " << *it1 << ' ' << *it2 << '\n';
        if (*it1 == *it2) {
            ++it1;
            ++it2;
        } else if (*it1 > *it2) {
            if (!visited[*it2]) vals.push_back(*it2);
            ++it2;
        } else {
            ++it1;
        }
    }

    while (it2 != unreachable.end()) {
        if (!visited[*it2]) vals.push_back(*it2);
        ++it2;
    }

    for (int i = 0; i < vals.size(); ++i) {
        unreachable.erase(vals[i]);
    }

    for (int i = 0; i < vals.size(); ++i) {
        if (!visited[vals[i]]) dfs(vals[i], g, unreachable, visited);
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::set<int>> g(n, std::set<int>());
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;
        u--; v--;
        g[u].insert(v);
        g[v].insert(u);
    }

    std::vector<int> res;
    std::vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            // logic
            std::set<int> unreachable;
            for (auto it = g[i].begin(); it != g[i].end(); ++it) {
                unreachable.insert(*it);
            }

            visited[i] = true;
            for (int j = 0; j < n; ++j) {
                if (unreachable.find(j) == unreachable.end() && !visited[j]) {
                    dfs(j, g, unreachable, visited);
                }
            }
            res.push_back(n - unreachable.size());
        }
    }

    std::sort(res.begin(), res.end());
    std::cout << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';

}