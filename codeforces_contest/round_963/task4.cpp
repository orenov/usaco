#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>


bool fun(std::vector<int>& a, int k, int m) {
    std::vector<int> b(a.size());
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] >= m) {
            b[i] = 1;
        } else {
            b[i] = -1;
        }
    }

    int need = (a.size() - (a.size() / k) * k);
    int pos = need / 2 + 1;
    int neg = need - pos;


    int cur_pos = 0;
    int cur_neg = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] == 1) {
            cur_pos++;
        } else {
            cur_neg++;
        }

        if (cur_pos > cur_neg && need >= cur_pos + cur_neg) {
            need -= cur_pos;
            need -= cur_neg;
            cur_pos = 0;
            cur_neg = 0;
        }
        if (cur_pos + cur_neg == k) {
            cur_pos = 0;
            cur_neg = 0;
        }
    }
    
    return cur_pos <= 0;
}

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, k; std::cin >> n >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        int l = 1;
        int r = 1e9 + 1;

        // [l, r) invariant
        while (l + 1 < r) {
            int m = (l + r) / 2;
            std::cout << l << ' ' << r << ' ' << m << ' ' << fun(a, k, m) << '\n';

            if (fun(a, k, m)) {
                r = m;
            } else {
                l = m;
            }
        }

        std::cout << l << '\n';
    }
}