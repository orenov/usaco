#include <iostream>
#include <vector>
#include <string>


int fun(std::vector<int>& a, int x) {
    int cnt = 0;
    int i = 0;
    int cur_len = 0;
    while (i < a.size()) {
        if (a[i] > x) return 1e9;
        if (cur_len + a[i] <= x) {
            cur_len += a[i];
            i++;
        } else {
            cnt++;
            cur_len = 0;
        }
    }

    if (cur_len > 0) cnt++;

    return cnt;
}

int main() {
    int k; std::cin >> k;
    std::string s;
    std::getline(std::cin, s);
    std::getline(std::cin, s);
    std::vector<int> a;
    
    int i = 0;
    while (i < s.size()) {
        int cnt = 0;
        while (i < s.size() && s[i] != ' ' && s[i] != '-') {
            cnt++;
            i++;
        }
        a.push_back(cnt + 1);
        ++i;
    }
    a.back()--;

    int l = 0;
    int r = s.size();
    // (l, r] invariant
    while (l + 1 < r) {
        int m = (l + r) / 2;

        //std::cout << l << ' ' << r << ' ' <<  m << ' ' << fun(a, m) << '\n';
        if (fun(a, m) <= k) {
            r = m;
        } else {
            l = m;
        }
    }

    std::cout << r << '\n';
    
}