#include <iostream>
#include <vector>


using ll = long long;


int main() {
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    
    ll h, c; std::cin >> h >> c;
    std::vector<std::vector<ll>> ah(h, std::vector<ll>(2, 0));
    std::vector<std::vector<ll>> ac(c, std::vector<ll>(2, 0));

    for (ll i = 0; i < h; ++i) {
        std::cin >> ah[i][0] >> ah[i][1];
    }

    for (ll i = 0; i < c; ++i) {
        std::cin >> ac[i][0] >> ac[i][1];
    }

    std::vector<std::vector<std::vector<ll>>> dp(h + 1, std::vector<std::vector<ll>>(c + 1, std::vector<ll>(2, 2e14)));
    dp[1][0][0] = 0; // i, j, k; i = number of H passed, j = number of G passed, 0 - H is last, 1 - G is last;

    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j <= c; ++j) {
            for (int k = 0; k < 2; ++k) {
                //if (k == 0 && i == 0) continue;
				//if (k == 1 && j == 0) continue;
                if (dp[i][j][k] == 2e14) continue;
                std::vector<ll> pos;
                if (k == 0) pos = ah[i-1];
                if (k == 1) pos = ac[j-1];
                //std::cout << i << ' ' << j <<  ' ' << k << ' ' << dp[i][j][k] << '\n';
                if (i + 1 <= h) {
                    ll dist = (ah[i][0] - pos[0]) * (ah[i][0] - pos[0]) + (ah[i][1] - pos[1]) * (ah[i][1] - pos[1]);
                    dp[i+1][j][0] = std::min(dp[i+1][j][0], dp[i][j][k] + dist);
                }

                if (j + 1 <= c) {
                    ll dist = (ac[j][0] - pos[0]) * (ac[j][0] - pos[0]) + (ac[j][1] - pos[1]) * (ac[j][1] - pos[1]);
                    dp[i][j+1][1] = std::min(dp[i][j+1][1], dp[i][j][k] + dist);
                }
            }
        }
    }
    
    std::cout << dp.back().back()[0] << '\n';
}