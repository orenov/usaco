#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <string>
#include <set>
#include <queue>

bool DEBUG = false;

struct Edge {
    int id, from, to, type;
    Edge(int id, int from, int to, int type) : id(id), from(from), to(to), type(type) {}
};

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<Edge>> g(n, std::vector<Edge>());
    for (int i = 0; i < m; ++i) {
        int from, to, type;
        std::cin >> from >> to >> type;
        from--;
        to--;

        Edge edge1 = Edge(i, from, to, type);
        Edge edge2 = Edge(i, to, from, type);

        g[from].push_back(edge1);
        g[to].push_back(edge2);
    }

    std::vector<double> res(n, -1000.0);
    for (int i = 0; i < n; ++i) {
        if (res[i] == -1000.0) {
            std::map<int, std::pair<int,int>> vals;
            std::queue<std::vector<int>> q; // (id, a.first - x);
            double x = -1000.0;

            q.push({i, 0, 1});
            vals[i] = {0, 1};
            while (q.size() > 0) {
                auto next = q.front(); q.pop();
                int pos  = next[0];
                int bias = next[1];
                int sign = next[2];

                for (int i = 0; i < g[pos].size(); ++i) {
                    int new_bias = g[pos][i].type - bias; // bias - x; type - (bias - x) = type - bias + x = bias - type - x;
                    int new_sign = sign == 1 ? -1 : 1;
                    std::pair<int, int> new_data = {new_bias, new_sign};
                    // 'v' = new_bias + new_sign * x
                    // '0' = 0 + x
                    // '1' = 1 - x
                    // '2' = 2 - x
                    // '0' = 0 + x
                    // '2' = 1 + x
                    if (DEBUG) std::cout << g[pos][i].from << ' ' << g[pos][i].to << ' ' << new_bias << ' ' << new_sign << '\n';
                    if (vals.find(g[pos][i].to) == vals.end() || vals[g[pos][i].to] == new_data) {
                        if (vals.find(g[pos][i].to) == vals.end()) {
                            q.push({g[pos][i].to, new_bias, new_sign});
                            vals[g[pos][i].to] = new_data;
                        }
                    } else {
                        // found possible 'x' value
                        if (vals[g[pos][i].to].second == new_sign) {
                            std::cout << "NO\n";
                            return 0;
                        }
                        // b1 + s1 * x = b2 + s2 * x
                        // x = (b1 - b2) / (s2 - s1)
                        if (DEBUG) std::cout << new_bias << ' ' << vals[g[pos][i].to].first << ' ' << vals[g[pos][i].to].second << ' ' << new_sign << '\n';
                        double new_x = (1.0 * new_bias - vals[g[pos][i].to].first) / (vals[g[pos][i].to].second - new_sign);
                        if (x != -1000.0 && x != new_x) {
                            std::cout << "NO\n";
                            return 0;
                        }

                        x = new_x;
                        if (DEBUG) std::cout << "Found x: " << x << '\n';
                    }
                }
            }

            // if no exact 'x' recalculate via median 
            if (x == -1000.0) {
                std::vector<int> v;
                for (auto it = vals.begin(); it != vals.end(); ++it) {
                    if (it->second.second == -1) {
                        v.push_back(it->second.first);
                    } else {
                        v.push_back(it->second.first * -1);
                    }
                }

                std::sort(v.begin(), v.end());
                x = v[v.size() / 2];
                if (v.size() % 2 == 0) {
                    x = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2.0;
                }
            }

            for (auto it = vals.begin(); it != vals.end(); ++it) {
                res[it->first] = it->second.first + x * it->second.second;
            }
        }
    }

    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';

}
