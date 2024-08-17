#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::string s; std::cin >> s;

        long long r = 0;
        std::vector<int> opened;

        for (int i = 1; i < s.size(); i += 2) {
            if (opened.size() == 0) {
                // open
                opened.push_back(i - 1);
            } else {
                // close
                r += (i - 1 - opened.back());
                opened.pop_back();
            }

            if (s[i] == '(') {
                opened.push_back(i);
            } else {
                r += (i - opened.back());
                opened.pop_back();
            }
        }

        std::cout << r << '\n';
    }
}