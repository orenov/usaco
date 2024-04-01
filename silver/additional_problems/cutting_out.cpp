#include <iostream>
#include <vector>
#include <algorithm>

int fun(std::vector<std::pair<int, int>>& v, int x, std::vector<int>& answer) {
    // x - count of arrays
    // so that each element from v comes at least "x" times
    int cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
        cnt += v[i].first / x;
        for (int j = 0; j < v[i].first / x; ++j) {
            answer.push_back(v[i].second);
        }
    }

    return cnt;
}

int main() {
    int n, k; std::cin >> n >> k;
    std::vector<int> a(2*1e5 + 1, 0);
    for (int i = 0; i < n; ++i) {
        int tmp; std::cin >> tmp;
        a[tmp]++;
    }

    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != 0) {
            v.push_back({a[i], i});
        }
    }

    sort(v.begin(), v.end(), std::greater<std::pair<int,int>>());

    int l = 1;
    int r = 1e9;
    std::vector<int> answer;
    // [l, r) invariant
    while (l + 1 < r) {
        int m = (l + r) / 2;
        answer.clear();
        if (fun(v, m, answer) >= k) {
            l = m;
        } else {
            r = m;
        }
    }

    answer.clear();
    fun(v, l, answer);
    for (int i = 0; i < k; ++i) {
        std::cout << answer[i] << ' ';
    }
    std::cout << '\n';

}