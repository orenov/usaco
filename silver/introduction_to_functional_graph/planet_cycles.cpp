#include <iostream>
#include <vector>

void dfs(int pos, std::vector<int>& a, std::vector<int>& times, 
        std::vector<int>& color, std::vector<int>& res, int& timer) 
{
    // color: 0 - unseen, 1 - in loop, 2 - done, 3 - loop start, 4 - done cycle
    times[pos] = timer++;
    color[pos] = 1;

    if (color[a[pos]] == 0) {
        dfs(a[pos], a, times, color, res, timer);

        if (color[a[pos]] == 4) {
            res[pos] = res[a[pos]];
            if (color[pos] != 3) color[pos] = 4;
        } else {
            res[pos] = 1 + res[a[pos]];
        }
    } else if (color[a[pos]] == 1) {
        res[pos] = times[pos] - times[a[pos]] + 1;

        color[pos] = 4;
        color[a[pos]] = 3;
    } else {
        res[pos] = 1 + res[a[pos]];
    }

    if (color[pos] == 1) color[pos] = 2;
}


int main() {
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i]; a[i]--;
    }

    std::vector<int> times(n, -1);
    std::vector<int> color(n, false);
    std::vector<int> res(n, 0);
    int timer = 0;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(i, a, times, color, res, timer);
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';


}