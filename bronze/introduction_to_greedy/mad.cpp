#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=1012

int main() {
    freopen("breedflip.in", "r", stdin);
    int n; std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;

    int cnt = 0;
    int i = 0;
    while (i < a.size()) {
        while (i < a.size() && a[i] == b[i]) i++;
        if (i < a.size()) {
            cnt++;
        }
        while (i < a.size() && a[i] != b[i]) i++;
    }

    freopen("breedflip.out", "w", stdout);
    std::cout << cnt << '\n';
}