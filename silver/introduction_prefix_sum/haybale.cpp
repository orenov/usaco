#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=104

int main() {
    int n, k; std::cin >> n >> k;
    std::vector<int> p(n + 2, 0);
    for (int i = 0; i < k; ++i) {
        int l, r; std::cin >> l >> r;
        p[l]++;
        p[r + 1]--;
    }

    for (int i = 0; i < p.size(); ++i) {
        p[i] += p[i-1];
    }
    
    std::sort(p.begin(), p.end());

    std::cout << p[1 + p.size() / 2] << '\n';
}