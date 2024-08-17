#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<std::vector<int>> a(n, std::vector<int>(2, 0));
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i][1]; // not inclusive (x, y], if x == y then empty
            if (a[i][1] % 2 == 1) a[i][1]++;
        }

        int cnt = 0;
        int i = 0;
        while (i < n) {
            if (a[i][1] == a[i][0]) {
                i++;
                continue;
            }

            int len = a[i][1] - a[i][0];

            //std::cout << i << ' ' << len << ' ' << a[i][0] << ' ' << a[i][1] << ' ' << cnt << '\n';

            if (len <= 0) {
                i++;
                continue;
            }

            if (len >= 3) {
                i++;
                cnt++;
                continue;
            }
            
            if (len <= 2 && i + 1 == n) {
                i++;
                cnt++;
                continue;
            }

            if (len <= 2 && i + 1 < n) {
                if (a[i][1] == a[i+1][1]) {
                    a[i+1][1] -= 2;
                    i++;
                    cnt++;
                } else if (a[i][0] == a[i+1][0]) {
                    a[i+1][0] += 2;
                    i++;
                    cnt++;
                } else if (a[i+1][0] == a[i+1][1]) {
                    i++;
                    cnt++;
                } else {
                    i++;
                    cnt++;
                    continue;
                }
            }
        }

        std::cout << cnt << '\n';
    }
}