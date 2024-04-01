#include <iostream>
#include <vector>
#include <map>


void try_update(int i, int j, int k, std::vector<int>& ans, std::vector<int>& a) {
    int x = 0;
    k--;
    while (k >= 0) {
        if ((a[i] & (1 << k)) == (a[j] & (1 << k)) && (a[i] & (1 << k)) == 0) {
            x |= 1 << k;
        }
        --k;
    }

    int val = (x ^ a[i]) & (x ^ a[j]);
    if (val > ans[3]) ans = {i, j, x, val};
}

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, k; std::cin >> n >> k;
        std::vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::vector<int> answer{0, 0, 0, -1}; // i, j, x, val
        if (n == 2) {
            try_update(0, 1, k, answer, a);
            std::cout << answer[0] + 1<< ' ' << answer[1] + 1<< ' ' << answer[2] << '\n';
            continue;
        }
        std::vector<std::vector<int>> b; b.push_back(std::vector<int>());
        for (int i = 0; i < n; ++i) {
            b[0].push_back(i);
        }

        int kk = k - 1;
        while (kk >= 0) {
            std::vector<std::vector<int>> bb;
            for (int i = 0; i < b.size(); ++i) {
                std::vector<int> zero, one;
                for (int j = 0; j < b[i].size(); ++j) {
                    if (a[b[i][j]] & (1 << kk)) {
                        one.push_back(b[i][j]);
                    } else {
                        zero.push_back(b[i][j]);
                    }
                }

                if (zero.size() == 2) {
                    try_update(zero[0], zero[1], k, answer, a);
                } else if (zero.size() > 2) {
                    bb.push_back(zero);
                }

                if (one.size() == 2) {
                    try_update(one[0], one[1], k, answer, a);
                } else if (one.size() > 2) {
                    bb.push_back(one);
                }
            }

            b = bb;
            --kk;
        }

        for (int i = 0; i < b.size(); ++i) {
            if (b[i].size() >= 2) {
                try_update(b[i][0], b[i][1], k, answer, a);
            }
        }

        std::cout << answer[0] + 1 << ' ' << answer[1] + 1 << ' ' << answer[2] << '\n';

    }
}