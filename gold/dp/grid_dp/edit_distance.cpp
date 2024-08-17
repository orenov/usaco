#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::vector<std::vector<int>> dp(s1.size() + 1, std::vector<int>(s2.size() + 1, 0));

    for (int i = 0; i <= s1.size(); ++i) dp[i][0] = i;
    for (int i = 0; i <= s2.size(); ++i) dp[0][i] = i;

    /*
        "" L O V E
    ""  0  1 2 3 4
    M   1  1  
    O   2
    V   3
    I   4
    E   5
    */

    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            dp[i][j] = 1 + std::min(dp[i-1][j-1], std::min(dp[i-1][j], dp[i][j-1]));
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = std::min(dp[i][j], dp[i-1][j-1]);
            }
        }
    }

    std::cout << dp.back().back() << '\n';
}