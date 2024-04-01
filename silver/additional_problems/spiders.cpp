#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int s, t; std::cin >> s >> t;
    s--;
    t--;

    std::vector<int> primes(3e5+1, true);
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i < primes.size(); ++i) {
        if (!primes[i]) continue;
        for (int j = 2 * i; j < primes.size(); j += i) {
            primes[j] = false;
        }
    }

    std::vector<std::vector<int>> fmap(primes.size(), std::vector<int>());

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                if (primes[j]) {
                    fmap[j].push_back(i);
                }
                if (primes[a[i]/j]) {
                    fmap[a[i]/j].push_back(i);
                }
            }
        }
    }

    std::vector<int> from(n, -1);
    from[s] = s;

    std::queue<int> q; q.push(s);

    while (q.size() > 0) {
        int v = q.front();
        q.pop();
        
        if (v == t) break;

        for (int i = 1; i * i <= a[v]; ++i) {
            if (a[v] % i == 0) {
                if (primes[i] && fmap[i].size() > 0) {
                    for (int j = 0; j < fmap[i].size(); ++j) {
                        int cur = fmap[i][j];
                        if (from[cur] == -1) {
                            from[cur] = v;
                            q.push(cur);
                        }
                    }
                    fmap[i].clear();
                }
                if (primes[a[v]/i] && fmap[a[v]/i].size() > 0) {
                    for (int j = 0; j < fmap[a[v]/i].size(); ++j) {
                        int cur = fmap[a[v]/i][j];
                        if (from[cur] == -1) {
                            from[cur] = v;
                            q.push(cur);
                        }
                    }
                    fmap[a[v]/i].clear();
                }
            }
        }
    }

    if (from[t] == -1) {
        std::cout << "-1\n";
        return 0;
    }

    std::vector<int> path;
    while (t != s) {
        path.push_back(t);
        t = from[t];
    }
    path.push_back(s);
    
    std::cout << path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; --i) {
        std::cout << path[i] + 1 << ' ';
    }
    std::cout << '\n';
}