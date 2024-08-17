#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<int> b(n-1);
        for (int i = 0; i < n - 1; ++i) {
            std::cin >> b[i];
        }

        std::vector<int> a(n);
        a[0] = b[0];
        a[n-1] = b[n-2];

        for (int i = 1; i < n - 1; ++i) {
            a[i] = b[i] | b[i-1];
        }

        bool f = true;

        for (int i = 0; i < n - 1; ++i) {
            if ( (a[i] & a[i+1]) != b[i]) {
                f = false;
            }
        }

        if (f) {
            for (int i = 0; i < n; ++i) {
                std::cout << a[i] <<  ' ';
            }  
            std::cout << '\n';
        } else {
            std::cout << "-1\n";
        }
    }
}