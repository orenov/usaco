#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k; std::cin >> n >> k;
    std::vector<int> sum(n, 0);
    for (int i = 2; i <= n; ++i) {
        int val1, val2;
        std::cout << "or 1 " << i << std::endl;
        std::cin >> val1;
        std::cout << "and 1 " << i << std::endl;
        std::cin >> val2;
        
        sum[i-1] = val1 + val2;
    }

    int v1, v2;
    std::cout << "or 2 3" << std::endl;
    std::cin >> v1;
    std::cout << "and 2 3" << std::endl;
    std::cin >> v2;
    sum[0] = (sum[1] + sum[2] - v1 - v2) / 2;
    for (int i = 1; i < n; ++i) {
        sum[i] -= sum[0];
    }

    std::sort(sum.begin(), sum.end());

    std::cout << "finish " << sum[k-1] << std::endl;
}