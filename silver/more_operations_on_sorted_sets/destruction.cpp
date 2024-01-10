#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>
#include <set>

// https://codeforces.com/problemset/problem/1474/C

std::vector<std::vector<int>> run(std::multiset<int> fset, int x, int n) {
    std::vector<std::vector<int>> res(n, std::vector<int>(2, 0));
    res[0][0] = *fset.rbegin();
    fset.erase(fset.find(res[0][0]));
    res[0][1] = x;
    fset.erase(fset.find(x));
    for (int i = 1; i < n; ++i) {
        int cur_sum = res[i-1][0];
        int big = *fset.rbegin();
        fset.erase(fset.find(big));

        if (fset.find(cur_sum - big) != fset.end()) {
            res[i][0] = big;
            res[i][1] = cur_sum - big;

            fset.erase(fset.find(res[i][1]));
        } else {
            res.clear();
            break;
        }
    }

    return res;
}

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;

        std::multiset<int> fsett;
        for (int i = 0; i < 2 * n; ++i) {
            int val; std::cin >> val;
            fsett.insert(val);
        }

        std::vector<std::vector<int>> answer;
        for (auto it = fsett.rbegin(); it != fsett.rend(); ++it) {
            if (it == fsett.rbegin()) continue;
            answer = run(fsett, *it, n);
            if (answer.size() > 0) break;
        }

        if (answer.size() > 0) {
            std::cout << "YES\n";
            std::cout << answer[0][0] + answer[0][1] << '\n';
            for (int i = 0; i < answer.size(); ++i) {
                std::cout << answer[i][0] << ' ' << answer[i][1] << '\n';
            }
        } else {
            std::cout << "NO\n";
        }
    }
}