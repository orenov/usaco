#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<std::vector<int>> a(n, std::vector<int>(2, 0));

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i][0] >> a[i][1];
        }

        std::vector<int> source(2);
        std::vector<int> target(2);

        std::cin >> source[0] >> source[1] >> target[0] >> target[1];

        int a = source[1] - target[1];
        int b = target[0] - source[0];
        int c = -1 * b * source[1] + (-1 * a) * source[0]; 

        

    }
}