#include <iostream>
#include <vector>


int64_t fun(std::vector<int64_t>& a, int x) {
    int64_t cnt_min = 2e9;
    for (int i = 0; i < a.size(); ++i) {
        // try make a[i] = x;
        if (a[i] >= x) return 0;
        int64_t need = 0;
        int64_t val  = x;
        int64_t flag = false;
        for (int j = i; j < a.size(); ++j) {
            if (a[j] >= val) {
                flag = true;
                break;
            }

            need += val - a[j];
            val--;
        }

        if (flag) {
            cnt_min = std::min(cnt_min, need);
        }
    }

    return cnt_min;
}

int main() {
    int T; std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int n, k; std::cin >> n >> k;
        std::vector<int64_t> a(n, 0);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        int64_t l = 1;
        int64_t r = 1e9;
        // [l, r) invariant
        while (l + 1 < r) {
            int64_t m = (l + r) / 2;
            if (fun(a, m) <= k) {
                l = m;
            } else {
                r = m;
            }
        }
        std::cout << l << '\n';
    }
}