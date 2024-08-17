#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

void depth(int pos, int k, std::vector<int>& d) {
    if (pos >= k) return;
    d.push_back(pos);
    depth(pos + 1, k, d);
    depth(pos + 1, k, d);
}

void apply(int pos, std::vector<int>& a, 
            std::vector<int>& p, 
            std::vector<bool>& good, int& cnt_good, 
            std::vector<int>& d, int k,
            std::vector<int>& parents) 
{
    // pos - index in perimutation p to update
    // a[p[pos]] -> pos's parent
    // 
    int child1 = pos + 1;
    int child2 = pos + (1 << (k - d[pos] - 1));

    bool is_good = (k == d[pos] + 1) || 
        (good[child1] && a[p[child1]] == p[pos] &&
         good[child2] && a[p[child2]] == p[pos]);

    if (is_good) {
        if (good[pos] == false) {
            good[pos] = true;
            cnt_good++;
        }
    } else {
        if (good[pos] == true) {
            good[pos] = false;
            cnt_good--;
        }
    }
    
    if (pos == 0) return; 
    apply(parents[pos], a, p, good, cnt_good, d, k, parents);
}

int main() {
    int T; std::cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int n, q; std::cin >> n >> q;
        std::vector<int> a(n);
        for (int i = 1; i < n; ++i) {
            std::cin >> a[i];
            a[i]--;
        }
        std::vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> p[i];
            p[i]--;
        }

        int k = 0;
        while (n + 1 != 1 << k) ++k;
        std::vector<int> d;
        std::vector<int> parents(n, -1);
        depth(0, k, d);
        
        for (int i = 0; i < n; ++i) {
            int child1 = i + 1;
            int child2 = i + (1 << (k - d[i] - 1));
            if (child1 >= n || k == d[i] + 1) continue;
            parents[child1] = i;
            parents[child2] = i;
        }

        int cnt_good = 0;
        std::vector<bool> good(n);
        for (int i = n - 1; i >= 0; --i) {
            apply(i, a, p, good, cnt_good, d, k, parents);
        }

        for (int s = 0; s < q; ++s) {
            int x, y; std::cin >> x >> y;
            
            std::swap(p[x-1], p[y-1]);

            apply(x - 1, a, p, good, cnt_good, d, k, parents);
            apply(y - 1, a, p, good, cnt_good, d, k, parents);

            if (cnt_good == n) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }

        }
    }
}