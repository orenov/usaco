#include <iostream>
#include <vector>
#include <string>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, k; std::cin >> n >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        k--;
        int cnt1 = 0;
        int cnt2 = 0;
        // first position
        {
            std::swap(a[k], a[0]);
            for (int i = 1; i < n && a[i] < a[0]; ++i) {
                cnt1++;
            }
            std::swap(a[k], a[0]);
        }

        // on first big position
        {
            int j = 0;
            while (j < k) {
                if (a[j] > a[k]) break;
                j++;
            }

            if (j != 0 && j != k) {
                cnt2++;
                std::swap(a[k], a[j]);
                for (int i = j + 1; i < n && a[i] < a[j]; ++i) {
                    cnt2++;
                }
                std::swap(a[k], a[j]);
            }
        }

        std::cout << std::max(cnt1, cnt2) << '\n';
    }
}