#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

long long sum(std::vector<long long>& a) {
    long long r = 0;
    for (int i = 0; i < a.size(); ++i) {
        r += a[i];
    }
    return r;
}

std::vector<long long> mad(std::vector<long long>& a) {
    std::map<long long, long long> cnt;
    int cur = 0;
    std::vector<long long> r(a.size());

    for (int i = 0; i < a.size(); ++i) {
        cnt[a[i]]++;
        if (cnt[a[i]] >= 2 && a[i] >= cur) {
            cur = a[i];
        }
        r[i] = cur;
    }

    return r;
}

void print(std::vector<long long>& a) {
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        long long res = 0;

        //print(a);
        res += sum(a);
        a = mad(a);

        //
        res += sum(a);
        a = mad(a);

        //print(a);
        //while (is_any_ones_in_middle(a)) {
        //    res += sum(a);
        //    a = mad(a);
        //    print(a);
        //}

        for (int i = 0; i < a.size(); ++i) {
            res += a[i] * (a.size() - i);
        }

        std::cout << res << '\n';
    }
}