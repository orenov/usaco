#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

// https://cses.fi/problemset/task/1163

int main() {
    int x, n; std::cin >> x >> n;
    std::set<int> right, left;
    std::map<int, int> len;
    right.insert(0);
    right.insert(x);

    left.insert(0);
    left.insert(-x);

    len[x] = 1;
    std::vector<int> res(n, 0);

    for (int i = 0; i < n; ++i) {
        int pos; std::cin >> pos;
        
        int l = *left.lower_bound(-1 * pos) * -1;
        int r = *right.lower_bound(pos);
        len[r - l]--;

        if (len[r - l] == 0) {
            len.erase(r - l);
        }

        left.insert(-1 * pos);
        right.insert(pos);

        len[pos - l]++;
        len[r - pos]++;

        res[i] = len.rbegin()->first;
    }

    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';
}