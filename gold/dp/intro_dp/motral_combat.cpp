#include <iostream>
#include <vector>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::vector<std::vector<int>> dp(n, std::vector<int>(3, 2e9));
        // 0 - friend , 0
        // 1 - me, 0
        // 2 - me, 1

        int cnt = 0;
        bool is_friend = true;
        int how = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                
            }


            if (a[i] == 1) {
                if (is_friend) {
                    cnt++;
                    is_friend = false;
                    how = 0;
                } else {
                    if (how == 1) {
                        is_friend = true;
                        how = 0;
                    } else {
                        how++;
                    }
                }
            } else {
                is_friend = false;
                how = 0;
            }
        }

        std::cout << cnt << '\n';
    }
}