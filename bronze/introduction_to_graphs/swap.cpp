#include <iostream>
#include <vector>
#include <algorithm>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=1013

void cycle(int a1, int a2, int b1, int b2, std::vector<int>& a) {
    for (int i = a1; i <= (a2 + a1) / 2; ++i) {
        std::swap(a[i], a[a2 + a1 - i]);
    }
    for (int i = b1; i <= (b2 + b1) / 2; ++i) {
        std::swap(a[i], a[b2 + b1 - i]);
    }
}

bool check(std::vector<int>& a) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != i + 1) return false;
    }
    return true;
}

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int n, k; std::cin >> n >> k;
    int a1, a2, b1, b2; std::cin >> a1 >> a2 >> b1 >> b2;
    a1--;a2--;b1--;b2--;

    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) a[i] = i + 1;
    
    int cnt = 1;
    
    cycle(a1, a2, b1, b2, a);
    
    while (!check(a)) {
        cycle(a1, a2, b1, b2, a);
        cnt++;
    }
    
    k %= cnt;

    while (k > 0) {
        cycle(a1, a2, b1, b2, a);
        k--;
    }

    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << '\n';
    }
}