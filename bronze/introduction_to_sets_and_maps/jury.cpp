#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
 
#define LOCAL true
 
/*
    Author: Oleksii Renov
*/
 
using namespace std;
using ll = long long int;
 
/*
https://codeforces.com/contest/831/submission/220858231
x 
 
a1, a1 + a2, a1 + a2 + a3, .., a1 + ... + an
 
b1, b2, ... , bk
 
for all i: bi  somewhere in top subset
*/
 
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k, n; cin >> k >> n;
    vector<int> a(k, 0);
    
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
 
    vector<int> b(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
 
    int cur = 0;
    unordered_map<int, int> fmap;
    set<int> fset;
    for (int i = 0; i < k; ++i) {
        cur += a[i];
        if (fset.find(cur) != fset.end()) continue;
        
        fset.insert(cur);
        for (int j = 0; j < n; ++j) {
            fmap[b[j] - cur]++;
        }
    }
 
    int cnt = 0;
    for (auto it = fmap.begin(); it != fmap.end(); ++it) {
        if (it->second == n) {
            cnt++;
        }
    }
 
    std::cout << cnt << '\n';
}