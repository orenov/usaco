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
    vector<int> p(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int cnt = 0;
            int sum = 0;
            
            for (int k = i; k <= j; ++k) {
                cnt++;
                sum += p[k];
            }

            double d = 1.0 * sum / cnt;
            for (int k = i; k <= j; ++k) {
                if (p[k] == d) {
                    res++;
                    break;
                }
            }
        }
    }

    std::cout << res << '\n';

}
