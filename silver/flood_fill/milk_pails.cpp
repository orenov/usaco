#include <iostream>
#include <vector>
#include <set>
#include <queue>

int hash(int x, int y) {
    return 1000 * x + y;
}

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, k, m;
    std::cin >> x >> y >> k >> m;
    std::set<int> visited;
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    int closest = m;
    k += 1;
    while (k > 0) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            std::pair<int, int> p = q.front(); q.pop();
            if (visited.find(hash(p.first, p.second)) != visited.end()) continue;
            closest = std::min(closest, std::abs(p.first + p.second - m));
            visited.insert(hash(p.first, p.second));
            
            q.push({x, p.second});
            q.push({p.first, y});
            q.push({0, p.second});
            q.push({p.first, 0});
            int t1 = std::min(p.first, y - p.second);
            q.push({p.first - t1, p.second + t1});
            int t2 = std::min(x - p.first, p.second);
            q.push({p.first + t2, p.second - t2});           
        }

        k--;
    }

    std::cout << closest << '\n';
}