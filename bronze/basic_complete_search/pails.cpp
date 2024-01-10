#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL false

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=615
*/

using namespace std;
using ll = long long int;

int main() {
    if (!LOCAL) freopen("pails.in", "r", stdin);

    int x, y, m;
    cin >> x >> y >> m;

    int res = 0;

    for (int i = 0; i * x <= m; ++i) {
        int tmp = i * x + y * ((m - i * x) / y);
        res = max(res, tmp);
    }

    if (!LOCAL) freopen("pails.out", "w", stdout);
    std::cout << res << '\n';
}
