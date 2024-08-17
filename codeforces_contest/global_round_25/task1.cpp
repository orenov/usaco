#include <iostream>
#include <vector>
#include <string>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::string s; std::cin >> s;

        int zeros = 0;
        bool cont = false;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                zeros++;
                if (i > 0 && s[i-1] == '1') cont = true;
            }
        }

        if (zeros % 2 == 1) {
            std::cout << "NO\n";
        } else if (zeros == 2 && cont) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
}