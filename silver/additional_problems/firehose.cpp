#include <iostream>
#include <vector>
#include <algorithm>

int fun(std::vector<int>& a, int x) {
    int cnt1 = 0;
    int cnt2 = 0;
    {
        int cur = a[0] + 2*x;
        cnt1++;
        for (int i = 1; i < a.size(); ++i) {
            if (cur >= a[i]) {
                continue;
            } else {
                cnt1++;
                cur = a[i] + 2*x;
            }
        }
    }

    {
        int cur = a[0] - 2*x;
        int end = a.size() - 1;
        cnt2++;

        if (cur < 0) {
            cur += 1000000;
            while (end >= 0 && cur <= a[end]) {
                end--;
            }
        }
        cur = a[0];

        for (int i = 1; i <= end; ++i) {
            if (cur >= a[i]) {
                continue;
            } else {
                cnt2++;
                cur = a[i] + 2*x;
            }
        }        
    }

    return std::min(cnt1, cnt2);
}

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int k; std::cin >> k;

    int l = -1;
    int r = 1e9;

    while (l + 1 < r) {
        int m = (l + r) / 2;
        //std::cout << m << ' ' << fun(a, m) << '\n';
        if (fun(a, m) <= k) {
            r = m;
        } else {
            l = m;
        }
    }

    std::cout << r << '\n';
}