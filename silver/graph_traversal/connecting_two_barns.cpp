#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=1159

void dfs(int pos, std::vector<std::vector<int>>& g, std::vector<int>& cc, int id) {
    cc[pos] = id;
    for (int i = 0; i < g[pos].size(); ++i) {
        if (cc[g[pos][i]] == -1) {
            dfs(g[pos][i], g, cc, id);
        }
    }
}

int min_vectors(std::vector<int>& a, std::vector<int>& b) {
    int d = 1e9;
    int i = 0;
    int j = 0;
    while (i < a.size() || j < b.size()) {
        int tmp = a[i] - b[j];
        d = std::min(d, tmp * tmp);
        if (i + 1 < a.size() && j + 1 < b.size()) {
            int tmp1 = a[i + 1] - b[j];
            int tmp2 = a[i] - b[j + 1];
            if (tmp1 * tmp1 < tmp2 * tmp2) {
                i++;
            } else {
                j++;
            }
        } else if (i + 1 < a.size()) {
            i++;
        } else if (j + 1 < b.size()) {
            j++;
        } else {
            break;
        }
    }

    return d;
}

std::vector<long long> get_dist(int cluster_id, std::vector<int>& cc, int id) {
    std::vector<long long> d(id, 1e15);
    long long index = -1;
    for (int i = 0; i < cc.size(); ++i) {
        if (cc[i] == cluster_id) {
            index = i;
        }
        if (index != -1) {
            d[cc[i]] = std::min(d[cc[i]], (i - index) * (i - index));
        }
    }

    index = -1;
    for (int i = cc.size() - 1; i >= 0; --i) {
        if (cc[i] == cluster_id) {
            index = i;
        }
        if (index != -1) {
            d[cc[i]] = std::min(d[cc[i]], (i - index) * (i - index));
        }
    }
    return d;
}

int main() {
    int T; std::cin >> T;

    for (int qq = 1; qq <= T; ++qq) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> g(n, std::vector<int>());
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--;v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int id = 0;
        std::vector<int> cc(n, -1);
        for (int i = 0; i < n; ++i) {
            if (cc[i] == -1) {
                dfs(i, g, cc, id);
                id++;
            }
        }

        // if same cluster no new things needed
        if (cc[0] == cc.back()) {
            std::cout << "0\n";
            continue;
        }

        std::vector<std::vector<int>> fmap(id, std::vector<int>());
        for (int i = 0; i < n; ++i) {
            fmap[cc[i]].push_back(i);
        }

        // directly connect 0 and n - 1
        long long d = 1e15;
        std::vector<long long> d0 = get_dist(cc[0], cc, id);
        std::vector<long long> dn = get_dist(cc.back(), cc, id);

        for (int i = 0; i < id; ++i) {
            d = std::min(d, d0[i] + dn[i]);
        }

        std::cout << d << '\n';
    }
}