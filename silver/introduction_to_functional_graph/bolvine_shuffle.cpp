#include <iostream>
#include <vector>

void dfs(int pos, std::vector<int>& a, std::vector<int>& times, std::vector<int>& color, int& timer, int& cnt) {
    times[pos] = timer++;
    color[pos] = 1;

    if (color[a[pos]] == 0) {
        dfs(a[pos], a, times, color, timer, cnt);
    } else if (color[a[pos]] == 1) {
        cnt += times[pos] - times[a[pos]] + 1;
    }
    color[pos] = 2;
}

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i]--;
    }

    int cnt = 0;
    int timer = 0;
    std::vector<int> times(n, -1);
    std::vector<int> color(n, 0);
    for (int i = 0; i < times.size(); ++i) {
        if (color[i] == 0) {
            dfs(i, a, times, color, timer, cnt);
        }
    }

    std::cout << cnt << '\n';
}