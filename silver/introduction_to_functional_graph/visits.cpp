#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <climits>

int64_t dfs(int pos, std::vector<int>& a, std::vector<bool>& visited, std::vector<int>& c) {
    int slow = pos, fast = pos;
    do {
        if (visited[slow]) return 0;
        slow = a[slow];
        fast = a[a[fast]];
    } while (slow != fast);

    if (visited[slow]) return 0;
    int v = INT_MAX;
    do {
        v = std::min(v, c[slow]);
        slow = a[slow];
    } while (slow != fast);

    while (!visited[pos]) {
        visited[pos] = true;
        pos = a[pos];
    }

    return v;
}

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    std::vector<int> c(n, 0);
    int64_t total = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> c[i];
        a[i]--;
        total += c[i];
    }
    std::vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            total -= dfs(i, a, visited, c);
        }
    }

    std::cout << total << '\n';
}