#include <iostream>
#include <vector>
#include <string>
#include <map>

int read_val(int bits) {
    std::string s; std::cin >> s;
    int val = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') val += 1 << i;
    }
    return val;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, q; std::cin >> n >> m >> q;
    std::vector<int> w(m, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
    }
    std::map<int, int> v;
    for (int i = 0; i < m; ++i) {
        v[read_val(n)]++;
    }

    std::vector<std::vector<int>> mem(1 << n, std::vector<int>(102, 0));
    for (int i = 0; i < 1 << n; ++i) { // 4096
        for (auto it = v.begin(); it != v.end(); ++it) { // 4096
            int val = 0;
            int ff = i ^ it->first;
            for (int k = 0; k < n; ++k) { // 12
                if (ff & (1 << k)) {
                   val += w[k]; 
                }
            }
            val = std::min(val, 101);

            mem[i][0] += it->second;
            mem[i][val] -= it->second;
        }

        for (int j = 1; j < 102; ++j) {
            mem[i][j] += mem[i][j-1];
        }
    }

    for (int i = 0; i < q; ++i) {
        int val = read_val(n);
        int k; std::cin >> k;
        std::cout << m - mem[val][k] << '\n';
    }
}