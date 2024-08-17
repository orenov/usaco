#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

bool is_same(std::vector<int>& a, std::vector<int>& b) {
    std::set<int> fset;
    for (int i = 0; i < a.size(); ++i) {
        fset.insert(a[i]);
    }
    for (int i = 0; i < b.size(); ++i) {
        if (fset.find(b[i]) == fset.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n; std::cin >> n;
        std::vector<int> a(n), b(n);
        std::map<int, int> mapa, mapb;
        
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            mapa[a[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
            mapb[b[i]] = i;
        }

        if (!is_same(a, b)) {
            std::cout << "NO\n";
            continue;
        }

        int steps_a = 0;
        std::vector<int> ra(n);
        for (int i = 0; i < n; ++i) {
            auto it = mapa.begin();
            int minimum_position = it->second;
            int minimum_value = it->first;
            int current_value = a[i];
            int current_position = mapa[a[i]];

            if (current_value != minimum_value) {
                int d = std::abs(minimum_position - current_position);
                steps_a += 2 * d - 1;
                ra[d]++;
                std::swap(a[minimum_position], a[current_position]);
                mapa[current_value] = minimum_position;
            }
            mapa.erase(minimum_value);
        }

        std::vector<int> rb(n);
        int steps_b = 0;
        for (int i = 0; i < n; ++i) {
            auto it = mapb.begin();
            int minimum_position = it->second;
            int minimum_value = it->first;
            int current_value = b[i];
            int current_position = mapb[b[i]];

            if (current_value != minimum_value) {
                int d = std::abs(minimum_position - current_position);
                steps_a += 2 * d - 1;
                ra[d]++;
                std::swap(b[minimum_position], b[current_position]);
                mapb[current_value] = minimum_position;
            }
            mapb.erase(minimum_value);
        }

        if (steps_a % 2 == steps_b % 2) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }

    }
}