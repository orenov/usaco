#include <iostream>
#include <vector>

void fill(int pos, std::vector<int>& a, std::vector<int>& res) {
    int slow = a[pos];
    int fast = a[a[pos]];
    int k = 1;
    while (slow != fast) {
        slow = a[slow];
        fast = a[a[fast]];
        ++k;
    }

    // std::cout << "F: " << slow << '\n';

    slow = pos;
    while (slow != fast) {
        slow = a[slow];
        fast = a[fast];
    }
    // std::cout << "S: " << slow << '\n';

    // slow is cycle start;
    while (pos != slow) {
        res[pos] = slow;
        pos = a[pos];
    }

    res[slow] = slow;
    slow = a[slow];

    while (slow != fast) {
        res[slow] = slow;
        slow = a[slow];
    }
}

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i]--;
    }

    std::vector<int> res(n, -1);
    std::vector<int> color(n, 0);
    for (int i = 0; i < n; ++i) {
        if (res[i] == -1) {
            fill(i, a, res);
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << res[i] + 1 << ' ';
    }
    std::cout << '\n';
}