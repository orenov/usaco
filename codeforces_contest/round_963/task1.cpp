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
        int a = n;
        int b = n;
        int c = n;
        int d = n;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'A' && a > 0) {
                --a;
            }
            if (s[i] == 'B' && b > 0) {
                --b;
            }
            if (s[i] == 'C' && c > 0) {
                --c;
            }
            if (s[i] == 'D' && d > 0) {
                --d;
            }
        }

        std::cout << 4 * n - (a + b + c + d) << '\n';
    }
}