#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<int> a(n);
        std::vector<int> b(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> b[i];

        int la = 0;
        int ra = n - 1;
        int lb = 0;
        int rb = n - 1;

        int flag = false;
        while (la < ra) {
            int b1 = a[la] == b[lb] || a[la] == b[rb];
            int b2 = a[ra] == b[lb] || a[ra] == b[rb];

            if (b1 && b2) {
                if (a[la] == b[lb]) {
                    la++;
                    lb++;
                } else {
                    la++;
                    rb--;
                }
            } else {
                flag = true;
                break;
            }
        }

        if (flag) {
            std::cout << "Alice\n"; 
        } else {
            std::cout << "Bob\n";
        }
    }
}