#include <iostream>
#include <vector>

void run(int x, int a, int b, int flag, std::vector<std::vector<bool>>& dp) {
    if (x >= dp.size()) return;
    if (dp[x][flag]) return;
    
    dp[x][flag] = true;

    run(x + a, a, b, flag, dp);
    run(x + b, a, b, flag, dp);
    if (flag == 0) {
        run(x / 2, a, b, 1, dp);
    }
}

int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    int t, a, b;
    std::cin >> t >> a >> b;
    
    std::vector<std::vector<bool>> dp(t + 1, std::vector<bool>(2, false));
    run(0, a, b, 0, dp);
    for (int i = dp.size() - 1; i >= 0; --i) {
        if (dp[i][0] || dp[i][1]) {
            std::cout << i << '\n';
            break;
        }
    }
}