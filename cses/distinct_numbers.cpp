#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL true

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

int main() {
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 1;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] != a[i-1]) cnt++;
    }

    std::cout << cnt << '\n';
}
