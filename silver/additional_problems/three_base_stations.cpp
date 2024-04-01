#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

bool fun(std::vector<int>& a, double x, std::vector<double>& positions) {
    positions.push_back(a[0] + x);
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] > positions.back() + x) {
            positions.push_back(a[i] + x);
        }
    }

    return positions.size() <= 3;
}

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    double l = 0.0;
    double r = 1e9;
    std::vector<double> positions;

    while (std::abs(r - l) > 1e-6) {
        double m = (r + l) / 2;
        positions.clear();
        if (fun(a, m, positions)) {
            r = m;
        } else {
            l = m;
        }
    }

    positions.clear();
    fun(a, r, positions);

    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(9);
    std::cout << r << '\n';
    std::cout << positions[0] << ' ' << positions[1] << ' ' << positions[2] << '\n';

}