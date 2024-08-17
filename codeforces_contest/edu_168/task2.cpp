#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        std::string s; std::cin >> s;
        std::string r = "";
        bool f = false;

        for (int i = 0; i < s.size(); ++i) {
            r.push_back(s[i]);
            if ( (i == s.size() - 1 || s[i] == s[i + 1]) && !f) {
                if (s[i] == 'a') {
                    r.push_back('z');
                } else {
                    r.push_back('a');
                }
                f = true;
            }
        }
        //r.push_back(s.back());

        std::cout << r << '\n';
    }
}