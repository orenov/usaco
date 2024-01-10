#include <iostream>
#include <vector>
#include <algorithm>
 

// https://codeforces.com/gym/104520/submission/230963860

int main() {
    int n; std::cin >> n;
    std::vector<long long> a(n, 0);
    std::vector<long long> b(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
 
    for (int i = 0; i < n; ++i) {
        a[i] = a[i] * (i + 1) * (n - i);
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end(), std::greater<long long>());
 
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += a[i] * b[i];
    }
 
    std::cout << res << '\n';
}