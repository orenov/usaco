#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<std::string> a(2);
        for (int i = 0; i < 2; ++i) {
            std::cin >> a[i];
        }

        int r = 0;
        for (int i = 1; i < n - 1; ++i) {
            // . . .
            // x . x
            if (a[0][i] == '.' && a[1][i] == '.' && 
                a[1][i-1] == 'x' && a[0][i-1] == '.' &&
                a[1][i+1] == 'x' && a[0][i+1] == '.') 
            {
                r++;
            }

            if (a[1][i] == '.' && a[0][i] == '.' && 
                a[0][i-1] == 'x' && a[1][i-1] == '.' &&
                a[0][i+1] == 'x' && a[1][i+1] == '.') 
            {
                r++;
            }
        }

        std::cout << r << '\n';
    }
}