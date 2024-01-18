#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

int hash(int x, int y) {
    return 1000 * x + y;
}

int getx(int x) {
    return x / 1000;
}

int gety(int x) {
    return x % 1000;
}

void floodfill(int r, int c, std::map<int, std::vector<int>>& fmap, 
    std::set<int>& visited, std::set<int>& lit, int n, int m) {
    if (r < 0 || r >= n) return;
    if (c < 0 || c >= m) return;
    int h = hash(r, c);
    if (visited.find(h) != visited.end()) return;
    visited.insert(h);
    //std::cout << "Visiting " << h << '\n';
    if (lit.find(h) == lit.end()) return;
    //std::cout << h << '\n';
    for (int i = 0; i < fmap[h].size(); ++i) {
        //std::cout << "insert: " << fmap[h][i] << '\n';
        if (visited.find(fmap[h][i]) != visited.end() && lit.find(fmap[h][i]) == lit.end()) {
            visited.erase(fmap[h][i]);
            lit.insert(fmap[h][i]);
            floodfill(getx(fmap[h][i]), gety(fmap[h][i]), fmap, visited, lit, n, m);
        } else {
            lit.insert(fmap[h][i]);
        }
    }

    floodfill(r + 1, c, fmap, visited, lit, n, m);
    floodfill(r - 1, c, fmap, visited, lit, n, m);
    floodfill(r, c + 1, fmap, visited, lit, n, m);
    floodfill(r, c - 1, fmap, visited, lit, n, m);
}

int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    int n, m; std::cin >> n >> m;
    std::map<int, std::vector<int>> fmap;
    std::set<int> visited, lit;
    for (int i = 0; i < m; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        x1--;y1--;x2--;y2--;
        fmap[hash(x1, y1)].push_back(hash(x2, y2));
    }

    lit.insert(hash(0, 0));
    floodfill(0, 0, fmap, visited, lit, n, m);
    std::cout << lit.size() << '\n';
}