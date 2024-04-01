#include <iostream>
#include <vector>
#include <algorithm>

bool fun(std::vector<double>& a, double x) {
    double total = 0.0;
    for (int i = 0; i < a.size(); ++i) {
        total += a[i] - x;
    }

    double best = a[1] - x;
    double current = a[1] - x;
    for (int i = 2; i < a.size() - 1; ++i) {
        if (current < 0) {
            current = 0;
        }
        current += a[i] - x;
        best = std::max(best, current);
    }
    

    return total - best >= 0;
}

int main() {
    freopen("sabotage.in", "r", stdin);
    freopen("sabotage.out", "w", stdout);
    int n; std::cin >> n;
    std::vector<double> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    double l = 0.0;
    double r = 10000.0;

    while (std::abs(r - l) > 1e-6) {
        double m = (l + r) / 2;
        if (fun(a, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(3);
    std::cout << r << '\n';
}