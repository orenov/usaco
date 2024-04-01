#include <iostream>
#include <vector>
#include <algorithm>
 
bool run(std::vector<std::pair<int, int>>& a, int d, int x, 
         std::vector<std::vector<int>>& answer) {
    int i = 0;
    for (int j = 1; i < a.size() && j < answer.size(); ++j) {
        for (int k = 0; i < a.size() && k < x; ++k) {
            if (a[i].first > j) break;
            if (a[i].first + d < j) return false;
            if (j >= a[i].first && j <= a[i].first + d) {
                answer[j].push_back(a[i].second);
                ++i;
            }
        }
    } 
 
    return i == a.size();
}
 
int main() {
    int n, d, m;
    std::cin >> n >> d >> m;
    std::vector<std::pair<int, int>> a(m, {0, 0});
 
    for (int i = 0; i < m; ++i) {
        std::cin >> a[i].first;
        a[i].second = i + 1;
    }
    std::sort(a.begin(), a.end());
 
    int l = 0;
    int r = m;
    std::vector<std::vector<int>> answer;
    // (l, r]
    while (l + 1 < r) {
        answer = std::vector<std::vector<int>>(n + 1, std::vector<int>());
        int middle = (l + r) / 2;
        if (run(a, d, middle, answer)) {
            r = middle;
        } else {
            l = middle;
        }
    }
 
    answer = std::vector<std::vector<int>>(n + 1, std::vector<int>());
    run(a, d, r, answer);
    std::cout << r << '\n';
 
    for (int i = 1; i <= n; ++i) {
        for (size_t j = 0; j < answer[i].size(); ++j) {
            std::cout << answer[i][j] << ' ';
        }
        std::cout << "0\n";
    }
}