#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL true

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

void run(int pos, vector<string>& board, int& cnt, int cols, int diag, int r_diag) {
    if (pos == 8) {
        cnt++;
        return;
    }

    for (int i = 0; i < 8; ++i) {
        if (board[pos][i] == '*') continue;
        if (cols & (1 << i)) continue;
        if (diag & (1 << (i + pos))) continue;
        if (r_diag & (1 << (i - pos + 8))) continue;

        run(pos + 1,
            board, 
            cnt, 
            cols | (1 << i), 
            diag | (1 << (i + pos)), 
            r_diag | (1 << (i - pos + 8)));
    }
}

int main() {
    if (!LOCAL) freopen(".in", "r", stdin);
    vector<string> board(8, "");
    for (int i = 0; i < 8; ++i) {
        cin >> board[i];
    }
    int cnt = 0;
    run(0, board, cnt, 0, 0, 0);

    if (!LOCAL) freopen(".out", "w", stdout);
    std::cout << cnt << '\n';
}
