#include <iostream>
#include <vector>

int main() {
    int n; std::cin >> n;
    std::vector<int64_t> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
   
    int64_t res = 0;
    for (int b = 0; b < 30; ++b) {
        std::vector<int64_t> cnt(2, 0);
        std::vector<int64_t> sum_cnt(2, 0);

        cnt[0]++;
        sum_cnt[0]++;
        int cur = 0;

        for (int i = 0; i < n; ++i) {
            cur ^= (a[i] >> b) % 2;
            res += sum_cnt[1 - cur] * (1 << b);
            cnt[cur]++;
            sum_cnt[0] += cnt[0];
            sum_cnt[1] += cnt[1];
            
            res %= 998244353;
            sum_cnt[0] %= 998244353;
            sum_cnt[1] %= 998244353;
        }
    }

    std::cout << res << '\n';
}