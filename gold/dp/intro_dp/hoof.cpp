#include <iostream>
#include <vector>
#include <cstring>

int dp[100001][21][3];

bool is_win(char bessie, char john) {
    if (bessie == 'H' && john == 'S') return true;
    if (bessie == 'S' && john == 'P') return true;
    if (bessie == 'P' && john == 'H') return true;
    return false;
}

int char_to_int(char c) {
    if (c == 'H') return 0;
    if (c == 'S') return 1;
    return 2;
}

char to_win(char c) {
    if (c == 'S') return 'H';
    if (c == 'P') return 'S';
    return 'P';
}

// 0 - hoof
// 1 - paper
// 2 - scissors
int run(int pos, char gesture, int k, std::vector<char>& a) {
    if (pos == a.size()) return 0;

    if (gesture == 'A') {
        return std::max(run(0, 'H', k, a), std::max(run(0, 'P', k, a), run(0, 'S', k, a)));
    }

    if (dp[pos][k][char_to_int(gesture)] != -1) {
        return dp[pos][k][char_to_int(gesture)];
    }

    if (is_win(gesture, a[pos])) {
        dp[pos][k][char_to_int(gesture)] = 1 + run(pos + 1, gesture, k, a);
        return dp[pos][k][char_to_int(gesture)];
    }

    int m = run(pos + 1, gesture, k, a);
    if (k > 0) {
        m = std::max(m, 1 + run(pos + 1, to_win(a[pos]), k - 1, a)); 
    }

    dp[pos][k][char_to_int(gesture)] = m;
    return dp[pos][k][char_to_int(gesture)];
}

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n, k; std::cin >> n >> k;
    std::vector<char> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::memset(dp, -1, sizeof(dp));
    std::cout << run(0, 'A', k, a) << '\n';
}