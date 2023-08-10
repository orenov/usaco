#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;


int main() {
    freopen("shell.in", "r", stdin);
    int n; cin >> n;
    vector<int> cnt(3, 0);
    vector<vector<int>> state{{1,0,0},{0,1,0},{0,0,1}};

    for (int i = 0; i < n; ++i) {
        int x, y, answer;
        cin >> x >> y >> answer;
        x--;y--;answer--;

        swap(state[0][x], state[0][y]);
        swap(state[1][x], state[1][y]);
        swap(state[2][x], state[2][y]);

        if (state[0][answer]) cnt[0]++;
        if (state[1][answer]) cnt[1]++;
        if (state[2][answer]) cnt[2]++;
    }

    freopen("shell.out", "w", stdout);
    std::cout << max(cnt[0], max(cnt[1], cnt[2])) << '\n';
}