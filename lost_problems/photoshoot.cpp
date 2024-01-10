#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>



int main() {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    int cnt = 0;
    int i = n - 1;
    while (i >= 0) {
        if (s[0] == 'G') {
            while (i >= 0 && !(i % 2 == 1 && s[i] == 'H')) {
                s.pop_back();
                --i;
            }
            
        } else if (s[0] == 'H') {

        }
    }

    std::cout << cnt << '\n';
}